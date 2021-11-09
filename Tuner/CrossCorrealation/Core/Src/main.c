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
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "frequency_calculator.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define BufferLength 250
#define BufferLength 5
#define CrossCorelationLength ((2*BufferLength) - 1)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint16_t SamplingBuffer[BufferLength] = {1, 2, 3, 4, 5};
//float SamplingBuffer[BufferLength] = {-1,-0.795241058,-0.588481367,-0.387595594,-0.19992283,-0.0319787562,0.110796347,0.224243432,0.305636168,0.353772134,0.369000256,0.353183776,0.309599996,0.242781699,0.15830645,0.0625427142,-0.0376366228,-0.135161638,-0.223080859,-0.294871807,-0.344733953,-0.367851704,-0.360616803,-0.320800811,-0.247670159,-0.142039523,-0.00626033731,0.155854583,0.339168012,0.537411094,0.743424833,0.949439883,1.14738452,1.3292073,1.48720229,1.61432362,1.70447564,1.75276923,1.75573039,1.71145678,1.61971128,1.48195279,1.30129981,1.08242905,0.831413627,0.555505872,0.262874246,-0.0376961343,-0.337127149,-0.626382709,-0.896802247,-1.1404196,-1.35025394,-1.52056324,-1.64704716,-1.72699535,-1.759372,-1.74483585,-1.68569374,-1.5857898,-1.45033681,-1.28569329,-1.09909868,-0.898375213,-0.691610157,-0.486829489,-0.291677892,-0.113116823,0.0428469442,0.171391234,0.269058108,0.333875656,0.365417838,0.364799321,0.334606677,0.278768271,0.202368468,0.111414373,0.0125640556,-0.08717186,-0.180743232,-0.26137507,-0.32287088,-0.359891981,-0.368201584,-0.344863266,-0.288385361,-0.198805824,-0.0777131319,0.0717971995,0.245229378,0.436853051,0.639921427,0.846933305,1.04992855,1.24080455,1.41164267,1.55502856,1.6643573,1.73410714,1.76007354,1.7395525,1.67146647,1.55642676,1.39673078,1.19629252,0.96051091,0.696078837,0.410742223,0.113016985,-0.188123748,-0.483580768,-0.764464736,-1.02242374,-1.24995017,-1.4406538,-1.58949137,-1.69294274,-1.74912846,-1.7578615,-1.72063458,-1.64054084,-1.52213347,-1.37122869,-1.19466102,-1,-0.795241058,-0.588481367,-0.387595594,-0.19992283,-0.0319787562,0.110796347,0.224243432,0.305636168,0.353772134,0.369000256,0.353183776,0.309599996,0.242781699,0.15830645,0.0625427142,-0.0376366228,-0.135161638,-0.223080859,-0.294871807,-0.344733953,-0.367851704,-0.360616803,-0.320800811,-0.247670159,-0.142039523,-0.00626033731,0.155854583,0.339168012,0.537411094,0.743424833,0.949439883,1.14738452,1.3292073,1.48720229,1.61432362,1.70447564,1.75276923,1.75573039,1.71145678,1.61971128,1.48195279,1.30129981,1.08242905,0.831413627,0.555505872,0.262874246,-0.0376961343,-0.337127149,-0.626382709,-0.896802247,-1.1404196,-1.35025394,-1.52056324,-1.64704716,-1.72699535,-1.759372,-1.74483585,-1.68569374,-1.5857898,-1.45033681,-1.28569329,-1.09909868,-0.898375213,-0.691610157,-0.486829489,-0.291677892,-0.113116823,0.0428469442,0.171391234,0.269058108,0.333875656,0.365417838,0.364799321,0.334606677,0.278768271,0.202368468,0.111414373,0.0125640556,-0.08717186,-0.180743232,-0.26137507,-0.32287088,-0.359891981,-0.368201584,-0.344863266,-0.288385361,-0.198805824,-0.0777131319,0.0717971995,0.245229378,0.436853051,0.639921427,0.846933305,1.04992855,1.24080455,1.41164267,1.55502856,1.6643573,1.73410714,1.76007354,1.7395525,1.67146647,1.55642676,1.39673078,1.19629252,0.96051091,0.696078837,0.410742223,0.113016985,-0.188123748,-0.483580768,-0.764464736,-1.02242374,-1.24995017,-1.4406538,-1.58949137,-1.69294274,-1.74912846,-1.7578615,-1.72063458,-1.64054084,-1.52213347,-1.37122869,-1.19466102};

float CrossCorrelationVaule[CrossCorelationLength];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  GetCrossCorr(SamplingBuffer, BufferLength, CrossCorrelationVaule);
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
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
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

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
