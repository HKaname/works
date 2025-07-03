#ifndef __MENU_H__
#define __MENU_H__

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
#define MAX_TEXTURE (18)	// �e�N�X�`���̐�
#define MAX_SECRET_TEX (7)	// �Ђ݂̃e�N�X�`���̐�

//---- �A�j���[�V�����f�[�^ ----
#define MAX_ANIM_TEX							(5)	  // �A�j���[�V�����̃e�N�X�`���̖���
#define MENU_ANIM_FRAME							(1)   // ��R�}���Ƃ̍X�V�t���[��
#define MENU_ANIME_SPLIT_X						(8)   // �^�C�g���A�j���[�V�����e�N�X�`��������X
#define MENU_ANIME_SPLIT_Y						(8)   // �^�C�g���A�j���[�V�����e�N�X�`��������Y
#define MENU_ANIME_END							(63)  // �^�C�g���A�j���[�V�����e�N�X�`���Ō�̃R�}

// �񋓑̒�`
enum MenuKind	// ���j���[���J����Ă��邩
{
	E_NONE,		 // �����N�����Ȃ�
	E_OPEN,		 // �J��
	E_CLOSE,	 // ����
	E_MOTIONLESS // �������Ȃ�
};

enum MenuSelectKind  // ���j���[�̑I�����
{
	E_CONTINU, // ������
	E_RETRY,   // ���g���C
	E_RETRUN  // �Z���N�g�ɖ߂�
};

enum MenuAnimationKind	// ���j���[�̃A�j���[�V�����̏��
{
	E_CONTINUE_LR,
	E_CONTINUE_UD,
	E_RETRY_UP,
	E_RETRY_DOWN,
};

// �N���X��`
class Menu
{
public:
	enum Sercret
	{
		E_SERCRET01 = 1,
		E_SERCRET02,
		E_SERCRET03,
		E_SERCRET04,
		E_SERCRET05,
		E_SERCRET06,
		E_SERCRET07
	};

	enum Difficulty
	{
		E_Easy = 1,
		E_RatherEasy,
		E_Normal,
		E_RatherDifficult,
		E_Difficult,

		E_Easy_EX,
		E_RatherEasy_EX,
		E_Normal_EX,
		E_RatherDifficult_EX,
		E_Difficult_EX
	};

public:
	Menu();
	~Menu();
	void Update();
	void Draw_GameUI();
	void Draw_MenuUI();
	void Draw_StageNum();
	void Draw_Secret(int Secret);
	void Draw_Difficulty(int difficulty);
	void MoveUI();
	void MoveStartUI();
	void MoveEndUI();
	void ResetUI();	
	void ResetRetryflg();
	int  SetMenuSelectContinu();
	int  SetMotionLess();
	int  SetNone();
	float GetPos();
	int GetMenuSelectKind();
	int GetMenuKined();
	bool GetbMenu();
	bool GetRetryFlg();
	bool GetReturnFlg();
	void PlaySEOpen();		//�I�[�v��SE�Đ�
	void PlaySEClose();		//�N���[�YSE�Đ�
	void PlaySEDecision();	//���艹SE�Đ�

	void SetCamera(CameraBase* pCamera);

private:
	int m_MenuSelectKind;		//���j���[�̑I�����
	int m_OldSelectMenu;		//��O�ɑI��ł����j���[�̏��
	int m_MenuAnimKind;			//���j���[�̃A�j���[�V�����̏��
	int m_MenuKind;
	int m_nDrawNum;				//�`��̏���
	float m_MenuPosX[2];		//���j���[�̕`����W(�O = ��,1�@= �E)
	float m_GameUIPosX;			//�X�^�[�g���̃��j���[�̈ړ������i���Ǝv����j
	bool m_bMenu;				//���j���[���J����Ă邩����
	bool m_RetryFlg;			//���g���C�������ꂽ���̔���
	bool m_ReturnFlg;			//�Z���N�g�ɖ߂邪�����ꂽ���̔���
	int  m_RandomNo;			//���ۂ��ނ̂Ђ݂̃����_���őI�΂ꂽ�l�̊i�[��
	int  m_nOldRandNo;			//���ۂ��ނ̂Ђ݂̃����_���őI�΂ꂽ�l�̕ۑ���
	float m_MenuSelectSize;
	bool  m_ClickAnimflg;
	DirectX::XMFLOAT2 m_MenuAnim_UVPos;

	// �C���X�^���X��
	CameraBase* m_pCamera;
	Texture* m_pTexture[MAX_TEXTURE];
	Texture* m_pSecretTex[MAX_SECRET_TEX];
	Texture* m_pAnimTex[MAX_ANIM_TEX];
	Texture* m_pEXdifficulty;
	Easing* m_pEasing;
	CAnim* m_pAnimation;

	//�T�E���h
	XAUDIO2_BUFFER* m_pSEMenuOpen;			//���j���[�I�[�v��
	XAUDIO2_BUFFER* m_pSEMenuClose;			//���j���[�N���[�Y
	XAUDIO2_BUFFER* m_pSEMenuDecision;		//���j���[���莞
	IXAudio2SourceVoice* m_pSEMenuSpeaker;	//���j���[�̍Đ��p
	XAUDIO2_BUFFER* m_pSEMenuMove;			//���j���[�ړ���
	IXAudio2SourceVoice* m_pSEMenuMoveSpeaker;	//���j���[�ړ��Đ��p
	XAUDIO2_BUFFER* m_pSEMenuRetry;			//���j���[���g���C��
	IXAudio2SourceVoice* m_pSEMenuRetrySpeaker;	//���j���[���g���C�Đ��p
};

#endif // !__MENU_H__
