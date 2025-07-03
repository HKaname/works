#ifndef __EASING_H__
#define __EASING_H__

// �N���X��`
class Easing
{
public:
	Easing();
	~Easing();

	// ChangePow�̃��Z�b�g(�Đ��p)
	void ResetChangePowPlay();

	// ChangePow�̃��Z�b�g(�t�Đ��p)
	void ResetChangePowRevarse();

	// �C�[�W���O�ړ������̔���
	bool GetIsPlay();

	// �C�[�W���O�ňړ�������֐��itrue�Œʏ�Đ��Afalse�ŋt�Đ��j
	// �C�[�Y�C��
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

	// �C�[�Y�A�E�g
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

	// �C�[�Y�C���A�E�g
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
	// �C�[�W���O(����)
	// �C�[�Y�C��
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

	// �C�[�Y�A�E�g
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

	// �C�[�Y�C���A�E�g
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

	float m_EasingPow;			// �C�[�W���O�̐����̒l���i�[����ϐ�
	float m_ChangePowPlay;		// �ړ����̃C�[�W���O�̗͂�ύX����ϐ��i�ʏ�Đ��j
	float m_ChangePowReverse;	// �ړ����̃C�[�W���O�̗͂�ύX����ϐ��i�t�Đ��j
	bool  m_IsPlay;				// �C�[�W���O�����ǂ�������
};

#endif // !__EASING_H__
