using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.UIElements;

public class InputViewer : MonoBehaviour
{
	[Header("GUI���̎擾")]
	[SerializeField]
	private GameObject _inputGUI;    // GUI�v���n�u
	private UIDocument _uiDocument;  // GUI���i�[�p
	private Label[] _labels;         // Label�i�[�p
	[SerializeField]
	private float _deadZone = 0.3f;  // ���E�X�e�B�b�N�̃f�b�h�]�[��

	private Dictionary<InputControl, Label> _activeLabels = new Dictionary<InputControl, Label>(); // ������Ă���{�^���ƑΉ�����Label 

	private IEnumerator Start()
	{
		// GUI����
		var inputObject = Instantiate(_inputGUI);

		// GUI���̎擾
		_uiDocument = inputObject.GetComponent<UIDocument>();

		// UI�\�z���I���܂őҋ@
		while (_uiDocument.rootVisualElement.Q<Label>("Label1") == null)
		{
			yield return null;
		}

		// �������J�n
		_labels = new Label[18];
		for (int i = 0; i < _labels.Length; i++)
		{
			_labels[i] = _uiDocument.rootVisualElement.Q<Label>("Label" + (i + 1));
			if (_labels[i] == null)
				Debug.LogError($"Label{i + 1} ��������܂���ł���");
		}
	}

	// Update is called once per frame
	void Update()
	{
		// ���݂̃R���g���[���[���̎擾
		var currentGamepad = Gamepad.current;

		// �ڑ��`�F�b�N
		if (currentGamepad == null)
		{
			return;
		}

		// ��ԃ`�F�b�N�i�{�^�����́j
		CheckButton(currentGamepad.buttonSouth, "A�{�^����������Ă��܂�");
		CheckButton(currentGamepad.buttonEast, "B�{�^����������Ă��܂�");
		CheckButton(currentGamepad.buttonWest, "X�{�^����������Ă��܂�");
		CheckButton(currentGamepad.buttonNorth, "Y�{�^����������Ă��܂�");
		CheckButton(currentGamepad.leftShoulder, "LB��������Ă��܂�");
		CheckButton(currentGamepad.rightShoulder, "RB��������Ă��܂�");
		CheckButton(currentGamepad.leftStickButton, "LS��������Ă��܂�");
		CheckButton(currentGamepad.rightStickButton, "RS��������Ă��܂�");
		CheckButton(currentGamepad.startButton, "�X�^�[�g��������Ă��܂�");
		CheckButton(currentGamepad.selectButton, "�Z���N�g��������Ă��܂�");
		CheckButton(currentGamepad.dpad.up, "�\���L�[�オ������Ă��܂�");
		CheckButton(currentGamepad.dpad.down, "�\���L�[����������Ă��܂�");
		CheckButton(currentGamepad.dpad.left, "�\���L�[����������Ă��܂�");
		CheckButton(currentGamepad.dpad.right, "�\���L�[�E��������Ă��܂�");
		CheckButton(currentGamepad.leftTrigger, "LT��������Ă��܂�");
		CheckButton(currentGamepad.rightTrigger, "RT��������Ă��܂�");

		// ��ԃ`�F�b�N�i�X�e�B�b�N���́j
		CheckStick(currentGamepad.leftStick, "���X�e�B�b�N���쒆");
		CheckStick(currentGamepad.rightStick, "�E�X�e�B�b�N���쒆");
	}

	// �{�^���̏�Ԃ��`�F�b�N���āALabel�ɔ��f
	private void CheckButton(ButtonControl button, string text)
	{
		if (button.isPressed)
		{
			if (!_activeLabels.ContainsKey(button))
			{
				// �V���������ꂽ �� �󂢂Ă���Label�Ɋ��蓖��
				Label target = FindEmptyLabel();
				if (target != null)
				{
					target.text = text;
					_activeLabels[button] = target;
				}
			}
		}
		else
		{
			if (_activeLabels.ContainsKey(button))
			{
				// �����ꂽ �� Label�����
				Label target = _activeLabels[button];
				target.text = "";
				_activeLabels.Remove(button);
			}
		}
	}

	// �X�e�B�b�N�̏�Ԃ��`�F�b�N���āALabel�ɔ��f
	private void CheckStick(StickControl stick, string text)
	{
		Vector2 value = stick.ReadValue();
		if (value.magnitude > _deadZone)
		{
			if (!_activeLabels.ContainsKey(stick))
			{
				// �V�����|���ꂽ �� �󂢂Ă���Label�Ɋ��蓖��
				Label target = FindEmptyLabel();
				if (target != null)
				{
					target.text = $"{text} ({value.x:F2}, {value.y:F2})";
					_activeLabels[stick] = target;
				}
			}
			else
			{
				// ���ɓ|����Ă��� �� �ʒu�X�V
				Label target = _activeLabels[stick];
				target.text = $"{text} ({value.x:F2}, {value.y:F2})";
			}
		}
		else
		{
			if (_activeLabels.ContainsKey(stick))
			{
				// �����ꂽ �� Label�����
				Label target = _activeLabels[stick];
				target.text = "";
				_activeLabels.Remove(stick);
			}
		}
	}

	// �󂢂Ă���Label��T��
	private Label FindEmptyLabel()
	{
		foreach (var lbl in _labels)
		{
			if (lbl != null && string.IsNullOrEmpty(lbl.text))
				return lbl;
		}
		return null; // �󂫂��Ȃ�
	}
}
