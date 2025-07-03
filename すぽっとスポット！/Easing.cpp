//==============================================================
//
//  ファイル名：Easing.cpp
//
//	概要：
//	移動時にイージングを掛けた移動をさせる
//	（※逆再生をする際はEndからStartに進む動きになるので注意）
//
//	イージング移動グラフ参考サイト↓
//	https://gizma.com/easing/
//==============================================================

// インクルード部
#include <iostream>
#include "Easing.h"

// Using宣言
using namespace std;

// 定数定義
#define PI (3.14159f)

//==============================================================
//　関数名：Easing::Easing()
//	引数１：なし
//	戻り値：なし
//
//	概　要：Easingクラスのコンストラクタ	
//==============================================================
Easing::Easing()
	:m_EasingPow(0.0f),
	 m_ChangePowPlay(0.0f),
	 m_ChangePowReverse(1.0f),
	 m_IsPlay(false)
{
}

//==============================================================
//　関数名：Easing::~Easing()
//	引数１：なし
//	戻り値：なし
//
//	概　要：Easingクラスのデストラクタ（特に何もしてない）
//==============================================================
Easing::~Easing()
{
}

//==============================================================
//　関数名：Easing::ResetChangePowPlay()
//	引数１：なし
//	戻り値：なし
//
//	概　要：移動力のリセット（再生用）
//==============================================================
void Easing::ResetChangePowPlay()
{
	m_ChangePowPlay = 0.0f;
}

//==============================================================
//　関数名：Easing::ResetChangePowRevarse()
//	引数１：なし
//	戻り値：なし
//
//	概　要：移動力のリセット（逆再生用）
//==============================================================
void Easing::ResetChangePowRevarse()
{
	m_ChangePowReverse = 1.0f;
}

//==============================================================
//　関数名：Easing::GetIsPlay()
//	引数１：なし
//	戻り値：なし
//
//	概　要：イージング中か返す関数
//==============================================================
bool Easing::GetIsPlay()
{
	return m_IsPlay;
}

//============================== ここから移動用の関数 ========================================

//======= イーズイン =======
//==============================================================
//　関数名：Easing::MoveEaseInSine()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInSineのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInSine(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	// 通常再生の場合
	if (PlayOrRevarse)
	{
		// 終了位置に到達するまでの判定
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;							// 現在再生中かどうか
			m_ChangePowPlay += MoveSpeed;				// 移動速度を加算する(ここで移動速度が変わる)
			m_EasingPow = EaseInSine(m_ChangePowPlay);	// 各種イージングに対応した移動量を計算用の変数に代入
		}
		else
		{
			m_IsPlay = false;	// 再生終了
		}

		// 移動量を返す
		return (End - Start) * m_EasingPow + Start;
	}
	// 逆再生の場合
	if (!PlayOrRevarse)
	{
		// 終了位置に到達するまでの判定
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;								// 現在再生中かどうか
			m_ChangePowReverse -= MoveSpeed;				// 移動速度を加算する(ここで移動速度が変わる)
			m_EasingPow = EaseInSine(m_ChangePowReverse);	// 各種イージングに対応した移動量を計算用の変数に代入
		}
		else
		{
			m_IsPlay = false;	// 再生終了
		}

		// 移動量を返す
		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInQuad()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInQuadのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInQuad(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInQuad(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInQuad(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInCubic()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInCubicのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInCubic(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInCubic(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInCubic(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInQuart()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInQuartのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInQuart(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInQuart(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInQuart(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInQuint()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInQuintのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInQuint(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInQuint(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInQuint(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInExpo()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInExpoのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInExpo(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInExpo(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInExpo(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInCirc()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInCircのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInCirc(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInCirc(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInCirc(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInBack()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInBackのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInBack(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInBack(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInBack(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInElastic()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInElasticのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInElastic(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInElastic(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInElastic(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInBounce()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInBounceのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInBounce(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInBounce(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInBounce(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//======= イーズアウト =======
//==============================================================
//　関数名：Easing::MoveEaseOutSine()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutSineのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseOutSine(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutSine(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutSine(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseOutQuad()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutQuadのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseOutQuad(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutQuad(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutQuad(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseOutCubic()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutCubicのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseOutCubic(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutCubic(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutCubic(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseOutQuart()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutQuartのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseOutQuart(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutQuart(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutQuart(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseOutQuint()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutQuintのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseOutQuint(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutQuint(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutQuint(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseOutExpo()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutExpoのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseOutExpo(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutExpo(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutExpo(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseOutCirc()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutCircのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseOutCirc(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutCirc(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutCirc(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseOutBack()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutBackのグラフに沿った移動をさせる（通常再生）
//==============================================================
float Easing::MoveEaseOutBack(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutBack(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutBack(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseOutElastic()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutElasticのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseOutElastic(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutElastic(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutElastic(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseOutBounce()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseOutBounceのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseOutBounce(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseOutBounce(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseOutBounce(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//======= イーズインアウト =======
//==============================================================
//　関数名：Easing::MoveEaseInOutSine()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutSineのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutSine(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutSine(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutSine(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInOutQuad()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutQuadのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutQuad(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutQuad(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutQuad(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInOutCubic()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutCubicのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutCubic(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutCubic(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutCubic(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInOutQuart()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutQuartのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutQuart(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutQuart(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutQuart(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInOutQuint()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutQuintのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutQuint(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutQuint(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutQuint(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInOutExpo()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutExpoのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutExpo(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutExpo(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutExpo(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInOutCirc()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutCircのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutCirc(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutCirc(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutCirc(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInOutBack()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutBackのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutBack(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutBack(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutBack(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInOutElastic()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutElasticのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutElastic(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutElastic(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutElastic(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//　関数名：Easing::MoveEaseInOutBounce()
//	引数１：float Start（開始位置）
//	引数２：float End（終了位置）
//	引数３：float MoveSpeed（移動速度）
//	引数４：bool PlayOrRevarse（再生か逆再生か）
//	戻り値：float（座標を返す）
//
//	概　要：EaseInOutBounceのグラフに沿った移動をさせる
//===============================================================
float Easing::MoveEaseInOutBounce(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	if (PlayOrRevarse)
	{
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;
			m_ChangePowPlay += MoveSpeed;
			m_EasingPow = EaseInOutBounce(m_ChangePowPlay);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	if (!PlayOrRevarse)
	{
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;
			m_ChangePowReverse -= MoveSpeed;
			m_EasingPow = EaseInOutBounce(m_ChangePowReverse);
		}
		else
		{
			m_IsPlay = false;
		}

		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//======================= ここから数式 ============================

//======= イーズイン =======
//==============================================================
//　関数名：Easing::EaseInSine()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInSineの計算処理
//==============================================================
float Easing::EaseInSine(float x)
{
	return 1.0f - cosf((x * PI) / 2.0f);
}

//==============================================================
//　関数名：Easing::EaseInQuad()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInQuadの計算処理
//==============================================================
float Easing::EaseInQuad(float x)
{
	return x * x;
}

//==============================================================
//　関数名：Easing::EaseInCubic()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInCubicの計算処理
//==============================================================
float Easing::EaseInCubic(float x)
{
	return x * x * x;
}

//==============================================================
//　関数名：Easing::EaseInQuart()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInQuartの計算処理
//==============================================================
float Easing::EaseInQuart(float x)
{
	return x * x * x * x; 
}

//==============================================================
//　関数名：Easing::EaseInQuint()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInQuintの計算処理
//==============================================================
float Easing::EaseInQuint(float x)
{
	return x * x * x * x * x;
}

//==============================================================
//　関数名：Easing::EaseInExpo()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInExpoの計算処理
//==============================================================
float Easing::EaseInExpo(float x)
{
	return x == 0 ? 0 : powf(2, 10 * x - 10);
}

//==============================================================
//　関数名：Easing::EaseInCirc()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInCircの計算処理
//==============================================================
float Easing::EaseInCirc(float x)
{
	return 1 - sqrtf(1 - powf(x, 2));
}

//==============================================================
//　関数名：Easing::EaseInBack()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInBackの計算処理
//==============================================================
float Easing::EaseInBack(float x)
{
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;
	return c3 * x * x * x - c1 * x * x;
}

//==============================================================
//　関数名：Easing::EaseInElastic()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInElasticの計算処理
//==============================================================
float Easing::EaseInElastic(float x)
{
	const float c4 = (2.0f * PI) / 3.0f;
	return x == 0.0f ? 0.0f : x == 0.0f ? 1.0f
		: -powf(2.0f, 10.0f * x - 10.0f) * sinf((x * 10.0f - 10.75f) * c4);
}

//==============================================================
//　関数名：Easing::EaseInBounce()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInBounceの計算処理
//==============================================================
float Easing::EaseInBounce(float x)
{
	return 1 - EaseOutBounce(1 - x);
}

//======= イーズアウト =======
//==============================================================
//　関数名：Easing::EaseOutSine()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutSineの計算処理
//==============================================================
float Easing::EaseOutSine(float x)
{
	return sinf((x * PI) / 2.0f);
}

//==============================================================
//　関数名：Easing::EaseOutQuad()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutQuadの計算処理
//==============================================================
float Easing::EaseOutQuad(float x)
{
	return 1 - (1 - x) * (1 - x);
}

//==============================================================
//　関数名：Easing::EaseOutCubic()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutCubicの計算処理
//==============================================================
float Easing::EaseOutCubic(float x)
{
	return 1 - (1 - x) * (1 - x) * (1 - x);
}

//==============================================================
//　関数名：Easing::EaseOutQuart()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutQuartの計算処理
//==============================================================
float Easing::EaseOutQuart(float x)
{
	return 1 - (1 - x) * (1 - x) * (1 - x) * (1 - x);
}

//==============================================================
//　関数名：Easing::EaseOutQuint()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutQuintの計算処理
//==============================================================
float Easing::EaseOutQuint(float x)
{
	return 1 - (1 - x) * (1 - x) * (1 - x) * (1 - x) * (1 - x);
}

//==============================================================
//　関数名：Easing::EaseOutExpo()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutExpoの計算処理
//==============================================================
float Easing::EaseOutExpo(float x)
{
	return x == 1 ? 1 : 1 - powf(2, -10 * x);
}

//==============================================================
//　関数名：Easing::EaseOutCirc()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutCircの計算処理
//==============================================================
float Easing::EaseOutCirc(float x)
{
	return sqrtf(1 - powf(x - 1, 2));
}

//==============================================================
//　関数名：Easing::EaseOutBack()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutBackの計算処理
//==============================================================
float Easing::EaseOutBack(float x)
{
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;
	return 1.0f + c3 * powf(x - 1.0f, 3.0f) + c1 * powf(x - 1.0f, 2.0f);
}

//==============================================================
//　関数名：Easing::EaseOutElastic()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutElasticの計算処理
//==============================================================
float Easing::EaseOutElastic(float x)
{
	const float c4 = (2.0f * PI) / 3.0f;
	return x == 0.0f ? 0.0f : x == 1.0f ? 1.0f
		: powf(2.0f, -10.0f * x) * sinf((x * 10.0f - 0.75f) * c4) + 1.0f;
}

//==============================================================
//　関数名：Easing::EaseOutBounce()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseOutBounceの計算処理
//==============================================================
float Easing::EaseOutBounce(float x)
{
	const float n1 = 7.5625f;
	const float d1 = 2.75f;

	if (x < 1.0f / d1)
	{
		return n1 * x * x;
	}
	else if (x < 2.0f / d1) 
	{
		return n1 * (x -= 1.5f / d1) * x + 0.75f;
	}
	else if (x < 2.5f / d1)
	{
		return n1 * (x -= 2.25f / d1) * x + 0.9375f;
	}
	else 
	{
		return n1 * (x -= 2.625f / d1) * x + 0.984375f;
	}
}

//====== イーズインアウト =======
//==============================================================
//　関数名：Easing::EaseInOutSine()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutSineの計算処理
//==============================================================
float Easing::EaseInOutSine(float x)
{
	return -(cosf(PI * x) - 1.0f) / 2.0f;
}

//==============================================================
//　関数名：Easing::EaseInOutQuad()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutQuadの計算処理
//==============================================================
float Easing::EaseInOutQuad(float x)
{
	return x < 0.5 ? 2 * x * x : 1 - powf(-2 * x + 2, 2) / 2;
}

//==============================================================
//　関数名：Easing::EaseInOutCubic()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutCubicの計算処理
//==============================================================
float Easing::EaseInOutCubic(float x)
{
	return x < 0.5 ? 4 * x * x : 1 - powf(-2 * x + 2, 3) / 2;
}

//==============================================================
//　関数名：Easing::EaseInOutQuart()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutQuartの計算処理
//==============================================================
float Easing::EaseInOutQuart(float x)
{
	return x < 0.5 ? 8 * x * x * x * x : 1 - powf(-2 * x + 2, 4) / 2;
}

//==============================================================
//　関数名：Easing::EaseInOutQuint()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutQuintの計算処理
//==============================================================
float Easing::EaseInOutQuint(float x)
{
	return x < 0.5 ? 16 * x * x * x * x * x : 1 - powf(-2 * x + 2, 5) / 2;
}

//==============================================================
//　関数名：Easing::EaseInOutExpo()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutExpoの計算処理
//==============================================================
float Easing::EaseInOutExpo(float x)
{
	return x == 0 ? 0 : x == 1 ? 1 : x < 0.5 ? powf(2, 20 * x - 10) / 2 : (2 - powf(2, -20 * x + 10)) / 2;
}

//==============================================================
//　関数名：Easing::EaseInOutCirc()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutCircの計算処理
//==============================================================
float Easing::EaseInOutCirc(float x)
{
	return x < 0.5 ? (1 - sqrtf(1 - powf(2 * x, 2))) / 2 : (sqrtf(1 - powf(-2 * x + 2, 2)) + 1) / 2;
}

//==============================================================
//　関数名：Easing::EaseInOutBack()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutBackの計算処理
//==============================================================
float Easing::EaseInOutBack(float x)
{
	const float c1 = 1.70158f;
	const float c2 = c1 * 1.525f;
	return x < 0.5f ? (powf(2.0f * x, 2.0f) * ((c2 + 1.0f) * 2.0f * x - c2)) / 2.0f
		: (powf(2.0f * x - 2.0f, 2.0f) * ((c2 + 1.0f) * (x * 2.0f - 2.0f) + c2) + 2.0f) / 2.0f;
}

//==============================================================
//　関数名：Easing::EaseInOutElastic()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutElasticの計算処理
//==============================================================
float Easing::EaseInOutElastic(float x)
{
	const float c5 = (2.0f * PI) / 4.5f;
	return x == 0.0f ? 0.0f : x == 1.0f ? 1.0f : x < 0.5f
		? -(powf(2.0f, 20.0f * x - 10.0f) * sinf((20.0f * x - 11.125f) * c5)) / 2.0f
		: (powf(2.0f, -20.0f * x + 10.0f) * sinf((20.0f * x - 11.125f) * c5)) / 2.0f + 1.0f;
}

//==============================================================
//　関数名：Easing::EaseInOutBounce()
//	引数１：float x（0.0 ～ 1.0）
//	戻り値：float(移動時にどれだけ移動力を減らすかの値を返す)
//
//	概　要：EaseInOutBounceの計算処理
//==============================================================
float Easing::EaseInOutBounce(float x)
{
	return x < 0.5
		? (1 - EaseOutBounce(1 - 2 * x)) / 2
		: (1 + EaseOutBounce(2 * x - 1)) / 2;
}
