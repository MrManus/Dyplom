/*
 * button.h
 *
 *  Created on: Oct 13, 2021
 *      Author: Manus
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

// states for state machine
typedef enum
{
	IDLE = 0,
	DEBOUNCE,
	PRESSED,
	REPEAT,
	RELEASE

} BUTTON_STATE;
// struct for button
typedef struct
{
	BUTTON_STATE 	State;
	GPIO_TypeDef* 	GpioPort;
	uint16_t 		GpioPin;

	uint32_t		LastTick;
	uint32_t		TimerDebounce; // Fixed
	uint32_t		TimerLongPress;
	uint32_t		TimerRepeat;
	uint32_t		TimerRelease;

	uint8_t			RedCounter;

	void(*ButtonPressed)(void);
	void(*ButtonLongPressed)(void);
	void(*ButtonRepeat)(void);
	void(*ButtonReleased)(void);


} TButton; //Button_t - no difference which one if is specified that it is TYPE
// public functions
void ButtonTask(TButton* Key);

void ButtonSetDebounceTime(TButton* Key, uint32_t Milliseconds);
void ButtonSetLongPressTime(TButton* Key, uint32_t Milliseconds);
void ButtonSetRepeatTime(TButton* Key, uint32_t Milliseconds);

void ButtonRegisterPressCallback(TButton* Key, void *Callback);
void ButtonRegisterLongPressCallback(TButton* Key, void *Callback);
void ButtonRegisterRepeatCallback(TButton* Key, void *Callback);
void ButtonRegisterReleaseCallback(TButton* Key, void *Callback);

void ButtonInitKey(TButton* Key, GPIO_TypeDef* GpioPort, uint16_t GpioPin, uint32_t TimerDebounce,
					uint32_t TimerLongPress, uint32_t TimerRepeat, uint32_t TimerRelease,
					uint8_t RedCounter);



#endif /* INC_BUTTON_H_ */
