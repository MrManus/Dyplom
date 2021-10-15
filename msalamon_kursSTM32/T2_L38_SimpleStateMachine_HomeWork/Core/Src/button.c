/*
 * button.c
 *
 *  Created on: Oct 13, 2021
 *      Author: Manus
 */
#include "main.h"

#include "button.h"


// Button Init
void ButtonInitKey(TButton* Key, GPIO_TypeDef* GpioPort, uint16_t GpioPin, uint32_t TimerDebounce,
					uint32_t TimerLongPress, uint32_t TimerRepeat, uint32_t TimerRelease,
					uint8_t RedCounter)
{
	Key->State = IDLE;

	Key->GpioPort = GpioPort;
	Key->GpioPin = GpioPin;

	Key->TimerDebounce = TimerDebounce;
	Key->TimerLongPress = TimerLongPress;
	Key->TimerRepeat = TimerRepeat;
	Key->TimerRelease = TimerRelease;
	Key->RedCounter = RedCounter;

}
// Time setting functions
void ButtonSetDebounceTime(TButton* Key, uint32_t Milliseconds)
{
	Key->TimerDebounce = Milliseconds;
}

void ButtonSetLongPressTime(TButton* Key, uint32_t Milliseconds)
{
	Key->TimerLongPress = Milliseconds;
}

void ButtonSetRepeatTime(TButton* Key, uint32_t Milliseconds)
{
	Key->TimerRepeat = Milliseconds;
}
// Register callbacks
void ButtonRegisterPressCallback(TButton* Key, void *Callback)
{
	Key->ButtonPressed = Callback;
}

void ButtonRegisterLongPressCallback(TButton* Key, void *Callback)
{
	Key->ButtonLongPressed = Callback;
}

void ButtonRegisterRepeatCallback(TButton* Key, void *Callback)
{
	Key->ButtonRepeat = Callback;
}

void ButtonRegisterReleaseCallback(TButton* Key, void *Callback)
{
	Key->ButtonReleased = Callback;
}

// States routine
void ButtonIdleRoutine(TButton* Key)
{
	if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(Key->GpioPort, Key->GpioPin))
	{
		Key->State = DEBOUNCE;
		Key->LastTick = HAL_GetTick();
	}
}

void ButtonDebounceRoutine(TButton* Key)
{
	if((HAL_GetTick() - Key->LastTick) > Key->TimerDebounce)
	{
		if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(Key->GpioPort, Key->GpioPin))
		{
			Key->State = PRESSED;
			Key->LastTick = HAL_GetTick();

			if(Key->ButtonPressed != NULL)
			{
				Key->ButtonPressed();
			}
		}
		else
		{
			Key->State = IDLE;
		}
	}
}

void ButtonPressedRoutine(TButton* Key)
{
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(Key->GpioPort, Key->GpioPin))
	{
		Key->State = RELEASE;
		Key->RedCounter = 0;
		Key->LastTick = HAL_GetTick();
	}
	else
	{
		if((HAL_GetTick() - Key->LastTick) > Key->TimerLongPress)
		{
			Key->State = REPEAT;
			Key->LastTick = HAL_GetTick();

			if(Key->ButtonLongPressed != NULL)
			{
				Key->ButtonLongPressed();
			}
		}
	}

}

void ButtonRepeatRoutine(TButton* Key)
{
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(Key->GpioPort, Key->GpioPin))
	{
		Key->State = RELEASE;
		Key->RedCounter = 0;
		Key->LastTick = HAL_GetTick();
	}
	else
	{
		if((HAL_GetTick() - Key->LastTick) > Key->TimerRepeat)
		{
			Key->LastTick = HAL_GetTick();
			if(Key->ButtonRepeat != NULL)
			{
				Key->ButtonRepeat();
			}
		}
	}
}
void ButtonReleaseRoutine(TButton* Key)
{
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(Key->GpioPort, Key->GpioPin))
	{
		if((HAL_GetTick() - Key->LastTick) > Key->TimerRelease)
		{
			if(Key->RedCounter < 6)
			{
				Key->RedCounter ++;
				Key->LastTick = HAL_GetTick();
				if(Key->ButtonReleased != NULL)
				{
					Key->ButtonReleased();
				}
			}
			else
			{
				Key->State = IDLE;
			}
		}
	}
	else
	{
		Key->State = DEBOUNCE;
	}
}


// State Machine
void ButtonTask(TButton* Key)
{
	switch(Key->State)
	{
		case IDLE:
			// do IDLE
			ButtonIdleRoutine(Key);
			break;

		case DEBOUNCE:
			// do DEBOUNCE
			ButtonDebounceRoutine(Key);
			break;

		case PRESSED:
			// do PRESSED
			ButtonPressedRoutine(Key);
			break;

		case REPEAT:
			// do REPEAT
			ButtonRepeatRoutine(Key);
			break;

		case RELEASE:
			// do RELEASE
			ButtonReleaseRoutine(Key);
			break;
	}
}
