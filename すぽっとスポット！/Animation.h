#ifndef __ANIMATION_H__
#define __ANIMATION_H__

//---- �C���N���[�h�� ----
#include "Model.h"
#include "Texture.h"

//---- �萔��` ----
#define LOAD_ANIM_FRAME    (1)
#define LOAD_ANIM_SPLIT_X  (8)
#define LOAD_ANIM_SPLIT_Y (11)
#define LOAD_ANIM_END     (86)

//---- �\���̒�` ----
struct AnimData
{
	int nAnimeSplitX;                 // �e�N�X�`���̕�����
	int nAnimeSplitY;                 // �e�N�X�`���̕�����
	int nAnimeFrame;                  // UV���W���؂�ւ��t���[����
	int nEndAnimNo;                   // �R�}�ԍ��̍Ō�
};

//---- �N���X ----
class CAnim
{
public:
	enum ClickMovekind
	{
		shrink,
		expansion
	};

public:
	CAnim();
	~CAnim();

	float Animation_Move(float MovePos, float Aroundframe, float Distance);
	float Animation_Rotation(float Aroundframe, float swingangle);
	float Animation_Scale(float Aroundframe, float ChangeScale, float Minsize);
	float Animation_Click(float MoveSize, float DefaultSize, float turnback, float movescale);
	DirectX::XMFLOAT2 TextureAnimation(bool Loop);	// ture�Ȃ烋�[�v����Afalse�Ȃ烋�[�v���Ȃ�
	void ResetUvPos();
	void ResetMoveframe();
	void SetClickAnimkind();
	int GetCurrentNo();
	void SetAnime(AnimData Data);
	bool GetIsEnd();

private:
	DirectX::XMFLOAT3 m_pos;			// ���S���W
	DirectX::XMFLOAT2 m_size;			// �c���T�C�Y
	DirectX::XMFLOAT2 m_PosTexCoord;	// �e�N�X�`�����W(����)
	DirectX::XMFLOAT2 m_SizeTexCoord;	// �e�N�X�`���T�C�Y(�E��)(0.0~1.0f)
	AnimData m_AnimData;                // �A�j���[�V�������s���ۂɎg�p����l
	float m_fAngle;						// ��]�p�x
	int m_nFrame;						// �A�j���[�V�����Ǘ��p�t���[��
	int m_nCurrentAnimNo;				// �A�j���[�V�����̃R�}�ԍ�
	int m_nMoveframe;					// ���ړ��A�j���[�V�����p�t���[��
	int m_nRotatframe;					// �h���A�j���[�V�����p�t���[��
	int m_nScaleframe;					// �g�k�A�j���[�V�����p�t���[��
	bool m_bMoveAnim;					// �e�N�X�`���A�j���[�V�����ғ��p�t���O
	int m_nClickAnimflg;				// �N���b�N���̃A�j���[�V�����̏��
};

#endif // !__ANIMATION_H__
