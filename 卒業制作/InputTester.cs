using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UIElements;

public class InputTester : MonoBehaviour
{
	// サンプルコード
	//　InputSystemの受け取り方について書いてあります

	bool isPressed = false;

	// Update is called once per frame
	void Update()
	{
		// 現在のコントローラー情報の取得
		var currentGamepad = Gamepad.current;

		// スティックの情報を取得
		var leftStick = currentGamepad.leftStick.ReadValue();
		var rightStick = currentGamepad.rightStick.ReadValue();

		// スティックのデッドゾーン
		float deadZone = 0.3f;
		if (leftStick.magnitude < deadZone)
		{
			leftStick = Vector2.zero;
		}

		// 十字キー
		var dpad = currentGamepad.dpad.ReadValue();

		// 十字キー各方向
		if (dpad.y > 0)
		{
			// Dpad Upが押されたときの処理
		}
		else if (dpad.y < 0)
		{
			// Dpad Downが押されたときの処理
		}
		else if (dpad.x < 0)
		{
			// Dpad Leftが押されたときの処理
		}
		else if (dpad.x > 0)
		{
			// Dpad Rightが押されたときの処理
		}

		// スティックも同じ処理で方向が取れるとれる...はず

		// ボタン情報を取得
		var buttonA = currentGamepad.buttonSouth.isPressed;           // Press情報
		var buttonB = currentGamepad.buttonEast.wasPressedThisFrame;  // Trigger情報
		var buttonX = currentGamepad.buttonWest.wasReleasedThisFrame; // Release情報

		var isActuated = currentGamepad.IsActuated(); // 何かしらのボタンが押されているか
	}
}
