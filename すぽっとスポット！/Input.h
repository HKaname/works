#ifndef __INPUT_H__
#define __INPUT_H__

#include <Windows.h>
#include <Xinput.h>
#undef max
#undef min

#pragma comment (lib, "xinput.lib")

typedef struct
{
	int iPad_left = 0, iPad_right = 0, iPad_up = 0, iPad_down = 0;
	int iPad_leftshoulder = 0, iPad_rightshoulder = 0;
	int iPad_A = 0, iPad_B = 0, iPad_X = 0, iPad_Y = 0;
	int iStick_left = 0, iStick_right = 0, iStick_up = 0, iStick_down = 0;
	int iPad_Start = 0;
}Controller;

typedef struct
{
	XINPUT_VIBRATION Vibration;  // êUìÆÇÃê›íË
	float fTime;                 // êUìÆópÇÃÉ^ÉCÉ}Å[
	float fMaxTime;              // êUìÆÇ™âΩïbä‘ë±Ç≠Ç©
} Vibration;

enum CONTOROLER_BUTTON
{
	BUTTON_UP = 0,		//è„
	BUTTON_DOWN,		//â∫
	BUTTON_RIGHT,		//âE
	BUTTON_LEFT,		//ç∂
	BUTTON_A,
	BUTTON_B,
	BUTTON_X,
	BUTTON_Y,
	BUTTON_START,
	STICK_UP,
	STICK_DOWN,
	STICK_LEFT,
	STICK_RIGHT,

	BUTTON_MAX
};

HRESULT InitInput();
void UninitInput();
void UpdateInput(float tick);
void SetVibration(float fStartTime, float fEndTime, int nLeftMotorSpeed = 32000, int nRightMotorSpeed = 16000);

bool IsKeyPress(BYTE key);
bool IsKeyTrigger(BYTE key);
bool IsKeyRelease(BYTE key);
bool IsKeyRepeat(BYTE key);
bool IsButtonTrigger(CONTOROLER_BUTTON button);
void InputController();


#endif // __INPUT_H__