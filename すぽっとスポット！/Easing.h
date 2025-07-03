#ifndef __EASING_H__
#define __EASING_H__

// クラス定義
class Easing
{
public:
	Easing();
	~Easing();

	// ChangePowのリセット(再生用)
	void ResetChangePowPlay();

	// ChangePowのリセット(逆再生用)
	void ResetChangePowRevarse();

	// イージング移動中かの判定
	bool GetIsPlay();

	// イージングで移動させる関数（trueで通常再生、falseで逆再生）
	// イーズイン
	float MoveEaseInSine    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInQuad    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInCubic   (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInQuart   (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInQuint   (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInExpo    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInCirc    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInBack    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInElastic (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInBounce  (float Start, float End, float MoveSpeed, bool PlayOrRevarse);

	// イーズアウト
	float MoveEaseOutSine    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseOutQuad    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseOutCubic   (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseOutQuart   (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseOutQuint   (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseOutExpo    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseOutCirc    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseOutBack    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseOutElastic (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseOutBounce  (float Start, float End, float MoveSpeed, bool PlayOrRevarse);

	// イーズインアウト
	float MoveEaseInOutSine    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInOutQuad    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInOutCubic   (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInOutQuart   (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInOutQuint   (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInOutExpo    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInOutCirc    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInOutBack    (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInOutElastic (float Start, float End, float MoveSpeed, bool PlayOrRevarse);
	float MoveEaseInOutBounce  (float Start, float End, float MoveSpeed, bool PlayOrRevarse);

private:
	// イージング(数式)
	// イーズイン
	float EaseInSine(float x);
	float EaseInQuad(float x);
	float EaseInCubic(float x);
	float EaseInQuart(float x);
	float EaseInQuint(float x);
	float EaseInExpo(float x);
	float EaseInCirc(float x);
	float EaseInBack(float x);
	float EaseInElastic(float x);
	float EaseInBounce(float x);

	// イーズアウト
	float EaseOutSine(float x);
	float EaseOutQuad(float x);
	float EaseOutCubic(float x);
	float EaseOutQuart(float x);
	float EaseOutQuint(float x);
	float EaseOutExpo(float x);
	float EaseOutCirc(float x);
	float EaseOutBack(float x);
	float EaseOutElastic(float x);
	float EaseOutBounce(float x);

	// イーズインアウト
	float EaseInOutSine(float x);
	float EaseInOutQuad(float x);
	float EaseInOutCubic(float x);
	float EaseInOutQuart(float x);
	float EaseInOutQuint(float x);
	float EaseInOutExpo(float x);
	float EaseInOutCirc(float x);
	float EaseInOutBack(float x);
	float EaseInOutElastic(float x);
	float EaseInOutBounce(float x);

	float m_EasingPow;			// イージングの数式の値を格納する変数
	float m_ChangePowPlay;		// 移動時のイージングの力を変更する変数（通常再生）
	float m_ChangePowReverse;	// 移動時のイージングの力を変更する変数（逆再生）
	bool  m_IsPlay;				// イージング中かどうか判定
};

#endif // !__EASING_H__
