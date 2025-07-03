//==============================================================
//
//  �t�@�C�����FEasing.cpp
//
//	�T�v�F
//	�ړ����ɃC�[�W���O���|�����ړ���������
//	�i���t�Đ�������ۂ�End����Start�ɐi�ޓ����ɂȂ�̂Œ��Ӂj
//
//	�C�[�W���O�ړ��O���t�Q�l�T�C�g��
//	https://gizma.com/easing/
//==============================================================

// �C���N���[�h��
#include <iostream>
#include "Easing.h"

// Using�錾
using namespace std;

// �萔��`
#define PI (3.14159f)

//==============================================================
//�@�֐����FEasing::Easing()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FEasing�N���X�̃R���X�g���N�^	
//==============================================================
Easing::Easing()
	:m_EasingPow(0.0f),
	 m_ChangePowPlay(0.0f),
	 m_ChangePowReverse(1.0f),
	 m_IsPlay(false)
{
}

//==============================================================
//�@�֐����FEasing::~Easing()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FEasing�N���X�̃f�X�g���N�^�i���ɉ������ĂȂ��j
//==============================================================
Easing::~Easing()
{
}

//==============================================================
//�@�֐����FEasing::ResetChangePowPlay()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�ړ��͂̃��Z�b�g�i�Đ��p�j
//==============================================================
void Easing::ResetChangePowPlay()
{
	m_ChangePowPlay = 0.0f;
}

//==============================================================
//�@�֐����FEasing::ResetChangePowRevarse()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�ړ��͂̃��Z�b�g�i�t�Đ��p�j
//==============================================================
void Easing::ResetChangePowRevarse()
{
	m_ChangePowReverse = 1.0f;
}

//==============================================================
//�@�֐����FEasing::GetIsPlay()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�C�[�W���O�����Ԃ��֐�
//==============================================================
bool Easing::GetIsPlay()
{
	return m_IsPlay;
}

//============================== ��������ړ��p�̊֐� ========================================

//======= �C�[�Y�C�� =======
//==============================================================
//�@�֐����FEasing::MoveEaseInSine()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInSine�̃O���t�ɉ������ړ���������
//===============================================================
float Easing::MoveEaseInSine(float Start, float End, float MoveSpeed, bool PlayOrRevarse)
{
	// �ʏ�Đ��̏ꍇ
	if (PlayOrRevarse)
	{
		// �I���ʒu�ɓ��B����܂ł̔���
		if (m_ChangePowPlay < 1.0f)
		{
			m_IsPlay = true;							// ���ݍĐ������ǂ���
			m_ChangePowPlay += MoveSpeed;				// �ړ����x�����Z����(�����ňړ����x���ς��)
			m_EasingPow = EaseInSine(m_ChangePowPlay);	// �e��C�[�W���O�ɑΉ������ړ��ʂ��v�Z�p�̕ϐ��ɑ��
		}
		else
		{
			m_IsPlay = false;	// �Đ��I��
		}

		// �ړ��ʂ�Ԃ�
		return (End - Start) * m_EasingPow + Start;
	}
	// �t�Đ��̏ꍇ
	if (!PlayOrRevarse)
	{
		// �I���ʒu�ɓ��B����܂ł̔���
		if (m_ChangePowReverse > 0.0f)
		{
			m_IsPlay = true;								// ���ݍĐ������ǂ���
			m_ChangePowReverse -= MoveSpeed;				// �ړ����x�����Z����(�����ňړ����x���ς��)
			m_EasingPow = EaseInSine(m_ChangePowReverse);	// �e��C�[�W���O�ɑΉ������ړ��ʂ��v�Z�p�̕ϐ��ɑ��
		}
		else
		{
			m_IsPlay = false;	// �Đ��I��
		}

		// �ړ��ʂ�Ԃ�
		return (End - Start) * m_EasingPow + Start;
	}

	return 0.0f;
}

//==============================================================
//�@�֐����FEasing::MoveEaseInQuad()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInQuad�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInCubic()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInCubic�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInQuart()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInQuart�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInQuint()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInQuint�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInExpo()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInExpo�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInCirc()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInCirc�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInBack()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInBack�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInElastic()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInElastic�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInBounce()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInBounce�̃O���t�ɉ������ړ���������
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

//======= �C�[�Y�A�E�g =======
//==============================================================
//�@�֐����FEasing::MoveEaseOutSine()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutSine�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseOutQuad()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutQuad�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseOutCubic()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutCubic�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseOutQuart()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutQuart�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseOutQuint()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutQuint�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseOutExpo()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutExpo�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseOutCirc()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutCirc�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseOutBack()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutBack�̃O���t�ɉ������ړ���������i�ʏ�Đ��j
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
//�@�֐����FEasing::MoveEaseOutElastic()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutElastic�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseOutBounce()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseOutBounce�̃O���t�ɉ������ړ���������
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

//======= �C�[�Y�C���A�E�g =======
//==============================================================
//�@�֐����FEasing::MoveEaseInOutSine()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutSine�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInOutQuad()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutQuad�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInOutCubic()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutCubic�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInOutQuart()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutQuart�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInOutQuint()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutQuint�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInOutExpo()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutExpo�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInOutCirc()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutCirc�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInOutBack()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutBack�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInOutElastic()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutElastic�̃O���t�ɉ������ړ���������
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
//�@�֐����FEasing::MoveEaseInOutBounce()
//	�����P�Ffloat Start�i�J�n�ʒu�j
//	�����Q�Ffloat End�i�I���ʒu�j
//	�����R�Ffloat MoveSpeed�i�ړ����x�j
//	�����S�Fbool PlayOrRevarse�i�Đ����t�Đ����j
//	�߂�l�Ffloat�i���W��Ԃ��j
//
//	�T�@�v�FEaseInOutBounce�̃O���t�ɉ������ړ���������
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

//======================= �������琔�� ============================

//======= �C�[�Y�C�� =======
//==============================================================
//�@�֐����FEasing::EaseInSine()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInSine�̌v�Z����
//==============================================================
float Easing::EaseInSine(float x)
{
	return 1.0f - cosf((x * PI) / 2.0f);
}

//==============================================================
//�@�֐����FEasing::EaseInQuad()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInQuad�̌v�Z����
//==============================================================
float Easing::EaseInQuad(float x)
{
	return x * x;
}

//==============================================================
//�@�֐����FEasing::EaseInCubic()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInCubic�̌v�Z����
//==============================================================
float Easing::EaseInCubic(float x)
{
	return x * x * x;
}

//==============================================================
//�@�֐����FEasing::EaseInQuart()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInQuart�̌v�Z����
//==============================================================
float Easing::EaseInQuart(float x)
{
	return x * x * x * x; 
}

//==============================================================
//�@�֐����FEasing::EaseInQuint()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInQuint�̌v�Z����
//==============================================================
float Easing::EaseInQuint(float x)
{
	return x * x * x * x * x;
}

//==============================================================
//�@�֐����FEasing::EaseInExpo()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInExpo�̌v�Z����
//==============================================================
float Easing::EaseInExpo(float x)
{
	return x == 0 ? 0 : powf(2, 10 * x - 10);
}

//==============================================================
//�@�֐����FEasing::EaseInCirc()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInCirc�̌v�Z����
//==============================================================
float Easing::EaseInCirc(float x)
{
	return 1 - sqrtf(1 - powf(x, 2));
}

//==============================================================
//�@�֐����FEasing::EaseInBack()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInBack�̌v�Z����
//==============================================================
float Easing::EaseInBack(float x)
{
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;
	return c3 * x * x * x - c1 * x * x;
}

//==============================================================
//�@�֐����FEasing::EaseInElastic()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInElastic�̌v�Z����
//==============================================================
float Easing::EaseInElastic(float x)
{
	const float c4 = (2.0f * PI) / 3.0f;
	return x == 0.0f ? 0.0f : x == 0.0f ? 1.0f
		: -powf(2.0f, 10.0f * x - 10.0f) * sinf((x * 10.0f - 10.75f) * c4);
}

//==============================================================
//�@�֐����FEasing::EaseInBounce()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInBounce�̌v�Z����
//==============================================================
float Easing::EaseInBounce(float x)
{
	return 1 - EaseOutBounce(1 - x);
}

//======= �C�[�Y�A�E�g =======
//==============================================================
//�@�֐����FEasing::EaseOutSine()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutSine�̌v�Z����
//==============================================================
float Easing::EaseOutSine(float x)
{
	return sinf((x * PI) / 2.0f);
}

//==============================================================
//�@�֐����FEasing::EaseOutQuad()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutQuad�̌v�Z����
//==============================================================
float Easing::EaseOutQuad(float x)
{
	return 1 - (1 - x) * (1 - x);
}

//==============================================================
//�@�֐����FEasing::EaseOutCubic()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutCubic�̌v�Z����
//==============================================================
float Easing::EaseOutCubic(float x)
{
	return 1 - (1 - x) * (1 - x) * (1 - x);
}

//==============================================================
//�@�֐����FEasing::EaseOutQuart()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutQuart�̌v�Z����
//==============================================================
float Easing::EaseOutQuart(float x)
{
	return 1 - (1 - x) * (1 - x) * (1 - x) * (1 - x);
}

//==============================================================
//�@�֐����FEasing::EaseOutQuint()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutQuint�̌v�Z����
//==============================================================
float Easing::EaseOutQuint(float x)
{
	return 1 - (1 - x) * (1 - x) * (1 - x) * (1 - x) * (1 - x);
}

//==============================================================
//�@�֐����FEasing::EaseOutExpo()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutExpo�̌v�Z����
//==============================================================
float Easing::EaseOutExpo(float x)
{
	return x == 1 ? 1 : 1 - powf(2, -10 * x);
}

//==============================================================
//�@�֐����FEasing::EaseOutCirc()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutCirc�̌v�Z����
//==============================================================
float Easing::EaseOutCirc(float x)
{
	return sqrtf(1 - powf(x - 1, 2));
}

//==============================================================
//�@�֐����FEasing::EaseOutBack()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutBack�̌v�Z����
//==============================================================
float Easing::EaseOutBack(float x)
{
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;
	return 1.0f + c3 * powf(x - 1.0f, 3.0f) + c1 * powf(x - 1.0f, 2.0f);
}

//==============================================================
//�@�֐����FEasing::EaseOutElastic()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutElastic�̌v�Z����
//==============================================================
float Easing::EaseOutElastic(float x)
{
	const float c4 = (2.0f * PI) / 3.0f;
	return x == 0.0f ? 0.0f : x == 1.0f ? 1.0f
		: powf(2.0f, -10.0f * x) * sinf((x * 10.0f - 0.75f) * c4) + 1.0f;
}

//==============================================================
//�@�֐����FEasing::EaseOutBounce()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseOutBounce�̌v�Z����
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

//====== �C�[�Y�C���A�E�g =======
//==============================================================
//�@�֐����FEasing::EaseInOutSine()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutSine�̌v�Z����
//==============================================================
float Easing::EaseInOutSine(float x)
{
	return -(cosf(PI * x) - 1.0f) / 2.0f;
}

//==============================================================
//�@�֐����FEasing::EaseInOutQuad()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutQuad�̌v�Z����
//==============================================================
float Easing::EaseInOutQuad(float x)
{
	return x < 0.5 ? 2 * x * x : 1 - powf(-2 * x + 2, 2) / 2;
}

//==============================================================
//�@�֐����FEasing::EaseInOutCubic()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutCubic�̌v�Z����
//==============================================================
float Easing::EaseInOutCubic(float x)
{
	return x < 0.5 ? 4 * x * x : 1 - powf(-2 * x + 2, 3) / 2;
}

//==============================================================
//�@�֐����FEasing::EaseInOutQuart()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutQuart�̌v�Z����
//==============================================================
float Easing::EaseInOutQuart(float x)
{
	return x < 0.5 ? 8 * x * x * x * x : 1 - powf(-2 * x + 2, 4) / 2;
}

//==============================================================
//�@�֐����FEasing::EaseInOutQuint()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutQuint�̌v�Z����
//==============================================================
float Easing::EaseInOutQuint(float x)
{
	return x < 0.5 ? 16 * x * x * x * x * x : 1 - powf(-2 * x + 2, 5) / 2;
}

//==============================================================
//�@�֐����FEasing::EaseInOutExpo()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutExpo�̌v�Z����
//==============================================================
float Easing::EaseInOutExpo(float x)
{
	return x == 0 ? 0 : x == 1 ? 1 : x < 0.5 ? powf(2, 20 * x - 10) / 2 : (2 - powf(2, -20 * x + 10)) / 2;
}

//==============================================================
//�@�֐����FEasing::EaseInOutCirc()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutCirc�̌v�Z����
//==============================================================
float Easing::EaseInOutCirc(float x)
{
	return x < 0.5 ? (1 - sqrtf(1 - powf(2 * x, 2))) / 2 : (sqrtf(1 - powf(-2 * x + 2, 2)) + 1) / 2;
}

//==============================================================
//�@�֐����FEasing::EaseInOutBack()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutBack�̌v�Z����
//==============================================================
float Easing::EaseInOutBack(float x)
{
	const float c1 = 1.70158f;
	const float c2 = c1 * 1.525f;
	return x < 0.5f ? (powf(2.0f * x, 2.0f) * ((c2 + 1.0f) * 2.0f * x - c2)) / 2.0f
		: (powf(2.0f * x - 2.0f, 2.0f) * ((c2 + 1.0f) * (x * 2.0f - 2.0f) + c2) + 2.0f) / 2.0f;
}

//==============================================================
//�@�֐����FEasing::EaseInOutElastic()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutElastic�̌v�Z����
//==============================================================
float Easing::EaseInOutElastic(float x)
{
	const float c5 = (2.0f * PI) / 4.5f;
	return x == 0.0f ? 0.0f : x == 1.0f ? 1.0f : x < 0.5f
		? -(powf(2.0f, 20.0f * x - 10.0f) * sinf((20.0f * x - 11.125f) * c5)) / 2.0f
		: (powf(2.0f, -20.0f * x + 10.0f) * sinf((20.0f * x - 11.125f) * c5)) / 2.0f + 1.0f;
}

//==============================================================
//�@�֐����FEasing::EaseInOutBounce()
//	�����P�Ffloat x�i0.0 �` 1.0�j
//	�߂�l�Ffloat(�ړ����ɂǂꂾ���ړ��͂����炷���̒l��Ԃ�)
//
//	�T�@�v�FEaseInOutBounce�̌v�Z����
//==============================================================
float Easing::EaseInOutBounce(float x)
{
	return x < 0.5
		? (1 - EaseOutBounce(1 - 2 * x)) / 2
		: (1 + EaseOutBounce(2 * x - 1)) / 2;
}
