#include "Input.h"
#include "DirectX.h"

//--- �O���[�o���ϐ�
BYTE g_keyTable[256];
BYTE g_oldTable[256];
XINPUT_STATE g_State;
XINPUT_STATE g_oldState;
Controller g_oldController;
Controller g_Controller;
Vibration g_Vibration;             // �U���̐ݒ�
XINPUT_VIBRATION g_NoneVibration;  // ���U���̐ݒ�

//--- �v���g�^�C�v�錾
void UpdateVibration(float tick);

HRESULT InitInput()
{
	// ��ԍŏ��̓���
	GetKeyboardState(g_keyTable);
	// �U���̐ݒ�
	ZeroMemory(&g_Vibration.Vibration, sizeof(XINPUT_VIBRATION));
	g_Vibration.Vibration.wLeftMotorSpeed = 32000;
	g_Vibration.Vibration.wRightMotorSpeed = 16000;
	g_Vibration.fTime = g_Vibration.fMaxTime = 0.0f;
	// ���U���̐ݒ�
	ZeroMemory(&g_NoneVibration, sizeof(XINPUT_VIBRATION));
	g_NoneVibration.wLeftMotorSpeed = 0;
	g_NoneVibration.wRightMotorSpeed = 0;
	return S_OK;
}

void UninitInput()
{
}

void UpdateInput(float tick)
{
	// �Â����͂��X�V
	memcpy_s(g_oldTable, sizeof(g_oldTable), g_keyTable, sizeof(g_keyTable));
	// ���݂̓��͂��擾
	GetKeyboardState(g_keyTable);

	// �Â����͂��X�V
	g_oldController = g_Controller;
	// �R���g���[���[
	InputController();

	// �R���g���[���[�̐U�������̍X�V
	UpdateVibration(tick);
}

void UpdateVibration(float tick)
{
	if (g_Vibration.fTime < g_Vibration.fMaxTime)
	{
		// �^�C�}�[�̍X�V
		g_Vibration.fTime += tick;

		//---- �U���̊J�n ----
		if (g_Vibration.fTime >= 0.0f)
		{
			XInputSetState(0, &g_Vibration.Vibration);
		}
	}
	else
	{
		XInputSetState(0, &g_NoneVibration);
	}
}

void SetVibration(float fStartTime, float fEndTime, int nLeftMotorSpeed, int nRightMotorSpeed)
{
	g_Vibration.fTime = -fStartTime;
	g_Vibration.fMaxTime = fEndTime;
	// �U���̐ݒ�
	ZeroMemory(&g_Vibration.Vibration, sizeof(XINPUT_VIBRATION));
	g_Vibration.Vibration.wLeftMotorSpeed = nLeftMotorSpeed;
	g_Vibration.Vibration.wRightMotorSpeed = nRightMotorSpeed;
}

bool IsKeyPress(BYTE key)
{
	return g_keyTable[key] & 0x80;
}

bool IsKeyTrigger(BYTE key)
{
	return (g_keyTable[key] ^ g_oldTable[key]) & g_keyTable[key] & 0x80;
}

bool IsKeyRelease(BYTE key)
{
	return (g_keyTable[key] ^ g_oldTable[key]) & g_oldTable[key] & 0x80;
}

bool IsKeyRepeat(BYTE key)
{
	return false;
}

bool IsButtonTrigger(CONTOROLER_BUTTON button)
{
	switch (button)
	{
	case BUTTON_UP:
		if (g_oldController.iPad_up != 1 && g_Controller.iPad_up == 1)
		{
			return true;
		}
		break;
	case BUTTON_DOWN:
		if (g_oldController.iPad_down != 1 && g_Controller.iPad_down == 1)
		{
			return true;
		}
		break;
	case BUTTON_RIGHT:
		if (g_oldController.iPad_right != 1 && g_Controller.iPad_right == 1)
		{
			return true;
		}
		break;
	case BUTTON_LEFT:
		if (g_oldController.iPad_left != 1 && g_Controller.iPad_left == 1)
		{
			return true;
		}
		break;
	case BUTTON_A:
		if (g_oldController.iPad_A != 1 && g_Controller.iPad_A == 1)
		{
			return true;
		}
		break;
	case BUTTON_B:
		if (g_oldController.iPad_B != 1 && g_Controller.iPad_B == 1)
		{
			return true;
		}
		break;
	case BUTTON_X:
		if (g_oldController.iPad_X != 1 && g_Controller.iPad_X == 1)
		{
			return true;
		}
		break;
	case BUTTON_Y:
		if (g_oldController.iPad_Y != 1 && g_Controller.iPad_Y == 1)
		{
			return true;
		}
		break;
	case STICK_UP:
		if (g_oldController.iStick_up != 1 && g_Controller.iStick_up == 1)
		{
			return true;
		}
		break;
	case STICK_DOWN:
		if (g_oldController.iStick_down != 1 && g_Controller.iStick_down == 1)
		{
			return true;
		}
		break;
	case STICK_RIGHT:
		if (g_oldController.iStick_right != 1 && g_Controller.iStick_right == 1)
		{
			return true;
		}
		break;
	case STICK_LEFT:
		if (g_oldController.iStick_left != 1 && g_Controller.iStick_left == 1)
		{
			return true;
		}
		break;
	case BUTTON_START:
		if (g_oldController.iPad_Start != 1 && g_Controller.iPad_Start == 1)
		{
			return true;
		}
		break;
	}

	return false;
}

void InputController()
{
	XInputGetState(0, &g_State);
	
	ZeroMemory(&g_Controller, sizeof(Controller));
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)		g_Controller.iPad_left = 1;			 //�Q�[���p�b�h�\���L�[��
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)		g_Controller.iPad_right = 1;		 //�Q�[���p�b�h�\���L�[�E
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)			g_Controller.iPad_up = 1;			 //�Q�[���p�b�h�\���L�[��
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)		g_Controller.iPad_down = 1;			 //�Q�[���p�b�h�\���L�[��
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)	g_Controller.iPad_leftshoulder = 1;	 //�Q�[���p�b�hL�{�^��
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)   g_Controller.iPad_rightshoulder = 1; //�Q�[���p�b�hR�{�^��
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_A)				g_Controller.iPad_A = 1;			 //�Q�[���p�b�hA
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_B)				g_Controller.iPad_B = 1;			 //�Q�[���p�b�hB
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_X)				g_Controller.iPad_X = 1;			 //�Q�[���p�b�hX
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_Y)				g_Controller.iPad_Y = 1;			 //�Q�[���p�b�hY
	if (g_State.Gamepad.wButtons & XINPUT_GAMEPAD_START)			g_Controller.iPad_Start = 1;			 //�Q�[���p�b�hY

	//�Q�[���p�b�h�A�i���O�X�e�B�b�N�̃f�b�h�]�[������
	if ((g_State.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(g_State.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{																	  
		g_State.Gamepad.sThumbLX = 0;
		g_State.Gamepad.sThumbLY = 0;
	}
	else
	{
		//---- �A�i���O�X�e�B�b�N ----
		if (abs(g_State.Gamepad.sThumbLX) > abs(g_State.Gamepad.sThumbLY))
		{
			if (g_State.Gamepad.sThumbLX > 0)
			{
				g_Controller.iStick_right = 1;
					g_Controller.iStick_left = 0;
			}
			else
			{
				g_Controller.iStick_right = 0;
					g_Controller.iStick_left = 1;
			}
		}
		else
		{
			if (g_State.Gamepad.sThumbLY > 0)
			{
				g_Controller.iStick_up = 1;
				g_Controller.iStick_down = 0;
			}
			else
			{
				g_Controller.iStick_up = 0;
				g_Controller.iStick_down = 1;
			}
		}
	}
	//if ((g_State.Gamepad.sThumbLX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
	//	(g_State.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	//{
	//	g_State.Gamepad.sThumbLX = 1;
	//	g_State.Gamepad.sThumbLY = 0;
	//}
	//if ((g_State.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
	//	(g_State.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	//{
	//	g_State.Gamepad.sThumbLX = 0;
	//	g_State.Gamepad.sThumbLY = 1;
	//}
	//if ((g_State.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
	//	(g_State.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	//{
	//	g_State.Gamepad.sThumbLX = 1;
	//	g_State.Gamepad.sThumbLY = 0;
	//}
	//if ((g_State.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
	//	(g_State.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && g_State.Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	//{
	//	g_State.Gamepad.sThumbLX = 0;
	//	g_State.Gamepad.sThumbLY = 1;
	//}
}
