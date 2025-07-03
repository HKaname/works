//==============================================================
//
//  �t�@�C�����FAnimation.cpp
//
//�@�@�T�v�F
//	�A�j���[�V�����̊Ǘ�
//
//==============================================================

//---- �C���N���[�h���@----
#include "Animation.h"
#include "Defines.h"
#include "Input.h"

//==============================================================
//�@�֐����FCAnim::CAnim()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�A�j���[�V�����N���X�̃R���X�g���N�^
//		
//==============================================================
CAnim::CAnim()
	: m_size(100.0f, 100.0f),
	  m_pos((float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2, 0.0f),
	  m_PosTexCoord(0.0f, 0.0f),
	  m_SizeTexCoord(1.0f / (float)LOAD_ANIM_SPLIT_X, 1.0f / (float)LOAD_ANIM_SPLIT_Y),
	  m_fAngle(0.0f),
	  m_nFrame(0),
	  m_nCurrentAnimNo(0),
	  m_AnimData{ LOAD_ANIM_SPLIT_X, LOAD_ANIM_SPLIT_Y, LOAD_ANIM_FRAME, LOAD_ANIM_END },
	  m_nMoveframe(0),
	  m_nScaleframe(0),
	  m_nRotatframe(0),
	  m_bMoveAnim(true),
	  m_nClickAnimflg(shrink)
{

}

//==============================================================
//�@�֐����FCAnim::~CAnim()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�A�j���[�V�����N���X�̃f�X�g���N�^
//		
//==============================================================
CAnim::~CAnim()
{
}

//==============================================================
//�@�֐����FCAnim::Animation_Move()
//	�����P�Ffloat MovePos(�ړ���������W)
//	�����Q�Ffloat Aroundframe(�P���ɂ�����t���[����)
//	�����Q�Ffloat Distance(�ړ�����)
//	�߂�l�Fsinf(DirectX::XMConvertToRadians(angle)) * moveDistance + cursorPosX;
//
//	�T�@�v�F���ړ��A�j���[�V����
//		
//==============================================================
float CAnim::Animation_Move(float MovePos, float Aroundframe, float Distance)
{
	m_nMoveframe++;

	//�P�T�ɂ�����t���[�����O�`�P�ŕ\��
	float rate = (float)m_nMoveframe / Aroundframe;
	//���݂̌o�ߎ��Ԃɉ������p�x�����߂�
	float angle = 360.0f * rate;
	//�J�[�\������������(sin���P�`�[�P�̂��ߑ��₵���������������ɓ����)
	float moveDistance = Distance;
	//�J�[�\���̏����ʒu
	float cursorPosX = MovePos;

	return sinf(DirectX::XMConvertToRadians(angle)) * moveDistance + cursorPosX;
}

//==============================================================
//�@�֐����FCAnim::Animation_Scale()
//	�����P�Ffloat Aroundframe(�P���ɂ�����t���[����)
//	�����Q�Ffloat ChangeScale(�傫���̕ω���)
//	�����R�Ffloat Minsize(�ŏ��̑傫��)
//	�߂�l�FsinScale * scaleRnage + minScale
//
//	�T�@�v�F��]�A�j���[�V����
//		
//==============================================================
float CAnim::Animation_Rotation(float Aroundframe, float swingangle)
{
	m_nRotatframe++;

	//�P�T�ɂ�����t���[�����O�`�P�ŕ\��
	float rate = (float)m_nRotatframe / Aroundframe;
	//���݂̌o�ߎ��Ԃɉ������p�x�����߂�
	float angle = 360.0f * rate;
	//�h���p�x
	float swinangle = swingangle;

	//�h���p�x�͒ʏ�̊p�x�̎w��Ȃ̂ŁA���W�A���p�ɍēx�ϊ�����
	return DirectX::XMConvertToRadians(sinf(DirectX::XMConvertToRadians(angle)) * swinangle);
}

//==============================================================
//�@�֐����FCAnim::Animation_Scale()
//	�����P�Ffloat Aroundframe(�P���ɂ�����t���[����)
//	�����Q�Ffloat ChangeScale(�傫���̕ω���)
//	�����R�Ffloat Minsize(�ŏ��̑傫��)
//	�߂�l�FsinScale * scaleRnage + minScale
//
//	�T�@�v�F�g�k�A�j���[�V����
//		
//==============================================================
float CAnim::Animation_Scale(float Aroundframe, float ChangeScale, float Minsize)
{
	m_nScaleframe++;

	//�P�T�ɂ�����t���[�����O�`�P�ŕ\��
	float rate = (float)m_nScaleframe / Aroundframe;
	//���݂̌o�ߎ��Ԃɉ������p�x�����߂�
	float angle = 360.0f * rate;
	//�P�`�[�P�͈̔͂Ŋg�k����Ɖ摜�����]����̂ŁA�O�`�P�̊ԂɎ��܂�悤�ɕϊ�����i* 0.5f + 0.5f�j
	float sinScale = sinf(DirectX::XMConvertToRadians(angle)) * 0.5f + 0.5f;
	//�g�k�̕ω���
	float scaleRnage = ChangeScale;
	//�ŏ��X�P�[��
	float minScale = Minsize;

	return sinScale * scaleRnage + minScale;
}

//==============================================================
//�@�֐����FCAnim::Animation_Click()
//	�����P�Ffloat MoveSize
//  �����Q�Ffloat DefaultSize
//  �����R�Ffloat turnback
//  �����S�Ffloat movescale
//	�߂�l�FReturnSize
//
//	�T�@�v�F�������������Ƃ��̃A�j���[�V����
//		
//==============================================================
float CAnim::Animation_Click(float MoveSize, float DefaultSize, float turnback, float movescale)
{
	float ReturnSize = MoveSize;

	if (ReturnSize > turnback && m_nClickAnimflg == shrink)
	{
		ReturnSize -= movescale;
	}
	else
	{
		m_nClickAnimflg = expansion;
	}

	if (ReturnSize < DefaultSize && m_nClickAnimflg == expansion)
	{
		ReturnSize += movescale;
	}

	return ReturnSize;
}


//==============================================================
//�@�֐����FCAnim::TextureAnimation()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�e�N�X�`���A�j���[�V�����̍X�V�p
//		
//==============================================================
DirectX::XMFLOAT2 CAnim::TextureAnimation(bool Loop)
{
	// �A�j���[�V�����ԍ��̍X�V
	if (m_bMoveAnim)	// �A�j���[�V�������s����
	{
		// �A�j���[�V�����t���[���̍X�V
		m_nFrame++;

		if (0 == m_nFrame % m_AnimData.nAnimeFrame)
		{
			m_nCurrentAnimNo++;	// ���݂̃R�}�ԍ����X�V

			// �e�N�X�`�����W�̍X�V
			m_PosTexCoord.x = m_SizeTexCoord.x * (m_nCurrentAnimNo % m_AnimData.nAnimeSplitX);
			m_PosTexCoord.y = m_SizeTexCoord.y * (m_nCurrentAnimNo / m_AnimData.nAnimeSplitX);
		}
	}

	if (Loop)
	{
		// ���[�v�A�j���[�V��������
		// �A�j���[�V�����̃��Z�b�g(�ŏI�t���[���ɓ��B��������)�`�F�b�N
		// ���B������ŏ��̃R�}�֖߂�
		if (m_AnimData.nAnimeFrame * m_AnimData.nEndAnimNo <= m_nFrame)
		{
			m_PosTexCoord.x = 0;
			m_PosTexCoord.y = 0;
			m_nCurrentAnimNo = 0;
			m_nFrame = 0;
		}
	}
	else
	{
		// ���[�v����Ȃ��A�j���[�V����
		// �A�j���[�V�����̃X�g�b�v(�ŏI�t���[���ɓ��B��������)�`�F�b�N
		// ���B������A�j���[�V�������~�߂�
		if (m_AnimData.nAnimeFrame * m_AnimData.nEndAnimNo <= m_nFrame)
		{
			m_bMoveAnim = false;
		}
	}

	return m_PosTexCoord;
}

//==============================================================
//�@�֐����FCAnim::ResetUvPos()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�e�N�X�`���A�j���[�V������UV���W�̃��Z�b�g
//		
//==============================================================
void CAnim::ResetUvPos()
{
	m_PosTexCoord = DirectX::XMFLOAT2(0.0f, 0.0f);
	m_nCurrentAnimNo = 0;
	m_nFrame = 0;
	m_bMoveAnim = true;
}

//==============================================================
//�@�֐����FCAnim::ResetMoveframe()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F���ړ��A�j���[�V�����̃J�E���g�p�t���[���̃��Z�b�g
//		
//==============================================================
void CAnim::ResetMoveframe()
{
	m_nMoveframe = 0;
}

void CAnim::SetClickAnimkind()
{
	m_nClickAnimflg = shrink;
}

//==============================================================
//�@�֐����FCAnim::GetCurrentNo()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�e�N�X�`���A�j���[�V�����̃R�}�ԍ���Ԃ��֐�
//		
//==============================================================
int CAnim::GetCurrentNo()
{
	return m_nCurrentAnimNo;
}

//==============================================================
//�@�֐����FCAnim::SetAnime(AnimData Data)
//	�����P�F�A�j���[�V�����f�[�^
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�e�N�X�`���A�j���[�V�����Ɋւ���l��ݒ肷��֐�
//		
//==============================================================
void CAnim::SetAnime(AnimData Data)
{
	//---- �l�̑�� ----
	m_AnimData = Data;

	//---- UV�T�C�Y�̌v�Z ----
	m_SizeTexCoord.x = 1.0f / Data.nAnimeSplitX;
	m_SizeTexCoord.y = 1.0f / Data.nAnimeSplitY;
}

//==============================================================
//�@�֐����FCAnim::GetIsEnd()
//	�����P�F�Ȃ�
//	�߂�l�F�A�j���[�V�����̏I���̗L��
//
//	�T�@�v�F�e�N�X�`���A�j���[�V�������I����������Ԃ��֐�
//		
//==============================================================
bool CAnim::GetIsEnd()
{
	return !m_bMoveAnim;
}
