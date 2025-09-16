using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UIElements;

public class InputTester : MonoBehaviour
{
	// �T���v���R�[�h
	//�@InputSystem�̎󂯎����ɂ��ď����Ă���܂�

	bool isPressed = false;

	// Update is called once per frame
	void Update()
	{
		// ���݂̃R���g���[���[���̎擾
		var currentGamepad = Gamepad.current;

		// �X�e�B�b�N�̏����擾
		var leftStick = currentGamepad.leftStick.ReadValue();
		var rightStick = currentGamepad.rightStick.ReadValue();

		// �X�e�B�b�N�̃f�b�h�]�[��
		float deadZone = 0.3f;
		if (leftStick.magnitude < deadZone)
		{
			leftStick = Vector2.zero;
		}

		// �\���L�[
		var dpad = currentGamepad.dpad.ReadValue();

		// �\���L�[�e����
		if (dpad.y > 0)
		{
			// Dpad Up�������ꂽ�Ƃ��̏���
		}
		else if (dpad.y < 0)
		{
			// Dpad Down�������ꂽ�Ƃ��̏���
		}
		else if (dpad.x < 0)
		{
			// Dpad Left�������ꂽ�Ƃ��̏���
		}
		else if (dpad.x > 0)
		{
			// Dpad Right�������ꂽ�Ƃ��̏���
		}

		// �X�e�B�b�N�����������ŕ���������Ƃ��...�͂�

		// �{�^�������擾
		var buttonA = currentGamepad.buttonSouth.isPressed;           // Press���
		var buttonB = currentGamepad.buttonEast.wasPressedThisFrame;  // Trigger���
		var buttonX = currentGamepad.buttonWest.wasReleasedThisFrame; // Release���

		var isActuated = currentGamepad.IsActuated(); // ��������̃{�^����������Ă��邩
	}
}
