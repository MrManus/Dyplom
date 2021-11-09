/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <string.h>
#include "frequency_calculator.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef union
{
	struct
	{
		uint8_t		val:	8;
		uint8_t 	addr:	4;
		uint8_t		dummy:  4;
	}__attribute__((packed));
	uint16_t raw;
}display_frm_u;

typedef enum
{
	NO_OP = 0x00u,
	DIGIT_0 = 0x01u,
	DIGIT_1 = 0x02u,
	DIGIT_2 = 0x03u,
	DIGIT_3 = 0x04u,
	DIGIT_4 = 0x05u,
	DIGIT_5 = 0x06u,
	DIGIT_6 = 0x07u,
	DIGIT_7 = 0x08u,
	DECODE_MODE = 0x09u,
	INTESITY = 0x0Au,
	SCAN_LINIT = 0x0Bu,
	SHUTDOWN = 0x0Cu,
	DISPLAY_TEST = 0x0Fu
}display_cmd_e;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define SINGLE_CONV_SAMPLES	14112u
#define SINGLE_CONV_SAMPLES	1000u //TODO: Update to correct number of samples
#define DMA_ADC_BUFFER_LEN	(SINGLE_CONV_SAMPLES * 2u)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile bool samples_update_lock = false;
volatile uint16_t tick_1ms = 0u;
uint16_t dma_adc_buff[DMA_ADC_BUFFER_LEN];
uint16_t locked_samples_buff[SINGLE_CONV_SAMPLES];
display_frm_u disp_frm_buf;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */
void display_task(void);
void adc_data_processing_task(void);
void disp_send_cmd(display_cmd_e cmd, uint8_t val);
void disp_init(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_TIM10_Init();
  MX_SPI2_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim10);
  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)dma_adc_buff, DMA_ADC_BUFFER_LEN);
  disp_init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV8;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
  /* TIM1_UP_TIM10_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
  /* SPI2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SPI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(SPI2_IRQn);
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	/* DBG Start */
	HAL_GPIO_TogglePin(TimerCheck_GPIO_Port	, TimerCheck_Pin);
	/* DBG End */

	tick_1ms++;
	/* Tick value overflowing at 999 */
	tick_1ms %= 1000u;

	/*
	 * Here place 1ms tasks //TODO: check if works in valid period
	 */

	if(0u == tick_1ms % 10u)
	{
		/*
		 * Here place 10ms tasks //TODO: check if works in valid period
		 */
	}

	if(0u == tick_1ms % 100u)
	{
		/*
		 * Here place 100ms tasks //TODO: check if works in valid period
		 */

		adc_data_processing_task();

		display_task();
	}
}

void display_task(void)
{
//	  disp_send_cmd(DIGIT_3, 0x0F);
}

void disp_init()
{
  HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_SET);

  HAL_Delay(1);
  /* Normal Operation mode*/
  disp_send_cmd(SHUTDOWN, 0x01);
  HAL_Delay(1);

  HAL_Delay(1);
  /* Normal Operation mode*/
  disp_send_cmd(SHUTDOWN, 0x01);
  HAL_Delay(1);
  /* Set Intensity */
  disp_send_cmd(INTESITY, 0x0F);
  HAL_Delay(1);
  /* Set scan Limit */
  disp_send_cmd(SCAN_LINIT, 0x07);
  HAL_Delay(1);
}

void disp_send_cmd(display_cmd_e cmd, uint8_t val)
{
	disp_frm_buf.addr = cmd;
	disp_frm_buf.val = val;

	/* CS Pin LOW level*/
	HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit_IT(&hspi2, &disp_frm_buf, 1u);
}

void adc_data_processing_task(void)
{
	/* Lock the data so it wont be changed during processing */
	samples_update_lock = true;

	/*
	 *	Here do all ADC data processing
	 */
//	  GetCrossCorr(SignalBuffer, SignalLength, CrossCorrBuffer);

	/* Disable the lock after processing */
	samples_update_lock = false;
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
	/* DBG Start */
	HAL_GPIO_WritePin(LOG_GPIO_Port, LOG_Pin, GPIO_PIN_SET);
	/* DBG End */

	/* Allow to modify buffer only if it not used/locked */
	if(false == samples_update_lock)
	{
		 // Copy data from DMA buffer so it wont change during further processing
		memcpy(locked_samples_buff, &dma_adc_buff[0u],  sizeof(locked_samples_buff));
	}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	/* DBG Start */
	HAL_GPIO_WritePin(LOG_GPIO_Port, LOG_Pin, GPIO_PIN_RESET);
	/* DBG End */

	/* Allow to modify buffer only if it not used/locked */
	if(false == samples_update_lock)
	{
		// Copy data from DMA buffer so it wont change during further processing
		memcpy(locked_samples_buff, &dma_adc_buff[SINGLE_CONV_SAMPLES], sizeof(locked_samples_buff));
	}
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	/* CS Pin goes to HIGH level */
	HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_SET);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
