using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.UIElements;

public class InputViewer : MonoBehaviour
{
	[Header("GUI情報の取得")]
	[SerializeField]
	private GameObject _inputGUI;    // GUIプレハブ
	private UIDocument _uiDocument;  // GUI情報格納用
	private Label[] _labels;         // Label格納用
	[SerializeField]
	private float _deadZone = 0.3f;  // 左右スティックのデッドゾーン

	private Dictionary<InputControl, Label> _activeLabels = new Dictionary<InputControl, Label>(); // 押されているボタンと対応するLabel 

	private IEnumerator Start()
	{
		// GUI生成
		var inputObject = Instantiate(_inputGUI);

		// GUI情報の取得
		_uiDocument = inputObject.GetComponent<UIDocument>();

		// UI構築が終わるまで待機
		while (_uiDocument.rootVisualElement.Q<Label>("Label1") == null)
		{
			yield return null;
		}

		// 初期化開始
		_labels = new Label[18];
		for (int i = 0; i < _labels.Length; i++)
		{
			_labels[i] = _uiDocument.rootVisualElement.Q<Label>("Label" + (i + 1));
			if (_labels[i] == null)
				Debug.LogError($"Label{i + 1} が見つかりませんでした");
		}
	}

	// Update is called once per frame
	void Update()
	{
		// 現在のコントローラー情報の取得
		var currentGamepad = Gamepad.current;

		// 接続チェック
		if (currentGamepad == null)
		{
			return;
		}

		// 状態チェック（ボタン入力）
		CheckButton(currentGamepad.buttonSouth, "Aボタンが押されています");
		CheckButton(currentGamepad.buttonEast, "Bボタンが押されています");
		CheckButton(currentGamepad.buttonWest, "Xボタンが押されています");
		CheckButton(currentGamepad.buttonNorth, "Yボタンが押されています");
		CheckButton(currentGamepad.leftShoulder, "LBが押されています");
		CheckButton(currentGamepad.rightShoulder, "RBが押されています");
		CheckButton(currentGamepad.leftStickButton, "LSが押されています");
		CheckButton(currentGamepad.rightStickButton, "RSが押されています");
		CheckButton(currentGamepad.startButton, "スタートが押されています");
		CheckButton(currentGamepad.selectButton, "セレクトが押されています");
		CheckButton(currentGamepad.dpad.up, "十字キー上が押されています");
		CheckButton(currentGamepad.dpad.down, "十字キー下が押されています");
		CheckButton(currentGamepad.dpad.left, "十字キー左が押されています");
		CheckButton(currentGamepad.dpad.right, "十字キー右が押されています");
		CheckButton(currentGamepad.leftTrigger, "LTが押されています");
		CheckButton(currentGamepad.rightTrigger, "RTが押されています");

		// 状態チェック（スティック入力）
		CheckStick(currentGamepad.leftStick, "左スティック操作中");
		CheckStick(currentGamepad.rightStick, "右スティック操作中");
	}

	// ボタンの状態をチェックして、Labelに反映
	private void CheckButton(ButtonControl button, string text)
	{
		if (button.isPressed)
		{
			if (!_activeLabels.ContainsKey(button))
			{
				// 新しく押された → 空いているLabelに割り当て
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
				// 離された → Labelを解放
				Label target = _activeLabels[button];
				target.text = "";
				_activeLabels.Remove(button);
			}
		}
	}

	// スティックの状態をチェックして、Labelに反映
	private void CheckStick(StickControl stick, string text)
	{
		Vector2 value = stick.ReadValue();
		if (value.magnitude > _deadZone)
		{
			if (!_activeLabels.ContainsKey(stick))
			{
				// 新しく倒された → 空いているLabelに割り当て
				Label target = FindEmptyLabel();
				if (target != null)
				{
					target.text = $"{text} ({value.x:F2}, {value.y:F2})";
					_activeLabels[stick] = target;
				}
			}
			else
			{
				// 既に倒されている → 位置更新
				Label target = _activeLabels[stick];
				target.text = $"{text} ({value.x:F2}, {value.y:F2})";
			}
		}
		else
		{
			if (_activeLabels.ContainsKey(stick))
			{
				// 離された → Labelを解放
				Label target = _activeLabels[stick];
				target.text = "";
				_activeLabels.Remove(stick);
			}
		}
	}

	// 空いているLabelを探す
	private Label FindEmptyLabel()
	{
		foreach (var lbl in _labels)
		{
			if (lbl != null && string.IsNullOrEmpty(lbl.text))
				return lbl;
		}
		return null; // 空きがない
	}
}
