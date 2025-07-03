#ifndef __TUTORIAL_H__
#define __TUTORIAL_H__

// �C���N���[�h��
#include "DirectXTex/TextureLoad.h"
#include "Sprite.h"
#include "CameraBase.h"
#include "Geometory.h"
#include "Defines.h"
#include "Texture.h"
#include "Easing.h"
#include "Sound.h"
#include "Animation.h"

// �萔��`
#define MAX_TUTORIAL_TEX (20)

enum TutorialStep_UI
{
	TUTO_Step1 = 1,
	TUTO_Step2,
	TUTO_Step3,
	TUTO_Step4,
	TUTO_Step5,
	TUTO_Step6
};

enum Princesskind
{
	Normal,
	Winter
};

class Tutorial
{
public:
	Tutorial();
	~Tutorial();

	// �C�[�W���O�m�F
	bool GetIsPlayEase();

	// �{�^���g�k�A�j���[�V����
	void ButtonAnim();

	// �`���[�g���A���\��
	void InTutorial();

	// �`���[�g���A���ގU
	void OutTutorial();

	// ���b�Z�[�W�{�b�N�X�\��
	void InMessageBox();

	// ���b�Z�[�W�{�b�N�X�ގU
	void OutMessageBox();

	// �q���ҋ@�\��
	void Princess_Standby(int princesskind);

	// �P�|�P�`���[�g���A���`��
	void Draw_Step1_1();
	void Draw_Step2_1();
	void Draw_Step3_1();
	void Draw_Step4_1();

	// �P�|�Q�`���[�g���A���`��
	void Draw_Step1_2();
	void Draw_Step2_2();
	void Draw_Step3_2();
	void Draw_Step4_2();
	void Draw_Step5_2();
	void Draw_Step6_2();

	// �R�|�P�`���[�g���A���`��
	void Draw_Tutorial_3(int TutoStep);

	// �S�[�P�`���[�g���A���`��
	void Draw_Tutorial_4(int TutoStep);

private:
	float m_PrincessPos;	// �q���̈ʒu�iY�j
	float m_BubblePos;		// �����o���̈ʒu
	int m_AnimDelay;		// �`���[�g���A���̍ŏ��̃A�j���[�V�����̃f�B���C
	float m_ButtonSize;

	// �f�[�^�̍쐬�p
	CameraBase* m_pCamera;
	Texture* m_pTexture[MAX_TUTORIAL_TEX];
	Texture* m_pWordsTex[9];
	Texture* m_pPrincessTex[9];
	Easing* m_pEasing;
	CAnim* m_pAnim;
};

#endif // !__TUTORIAL_H__
