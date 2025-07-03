#ifndef __UI_DIRECTION_H__
#define __UI_DIRECTION_H__

#include "Sprite.h"
#include "CameraBase.h"
#include "Geometory.h"
#include "Defines.h"
#include "Texture.h"
#include "Input.h"
#include "Sound.h"
#include "Easing.h"
#include "Animation.h"
#include "SceneStageSelect.h"

// �萔��`
#define MAX_DIRECTION_TEX (11)

// �񋓑̒�`
enum SelectKind
{
	E_NEXT,
	E_RETRUN_SELECT
};

class CDirection
{
public:
	CDirection();
	~CDirection();

	void StartDirection_Ready();
	void StartDirection_Start();
	void StartDirection_Alert();
	void DrawLoadAnim();
	void GoalDirection(int Stage);
	void MoveUI_In();
	void MoveUI_Out();
	void ChangeUISize(bool bEndGame, int Stage);
	void StartUIDirection();
	float GetPosX();
	bool GetbDirection();
	bool GetEndFade();
	bool GetGoalFlag();
	int  GetStartCnt();
	int GetGoalSelectKind();
	bool GetGoalSound();
	bool GetGoalDirection();

private:
	float m_Di_UIPosX[3];		// UI�̍��W
	float m_alpha[3];			// UI�̉摜�̔Z��
	float m_angle;				// UI�摜�̌X��
	float m_GoalTexangle;		// �S�[�����摜�̌X��
	bool m_bGoalDirection;		// �S�[�����o���s���Ă��邩�̔���
	bool m_bStartDirection;		// �X�^�[�g���o�̐؂�ւ��p
	bool m_bEndFade;			// �S�[�����̃t�F�[�h���s���Ă��邩�̔���
	float m_DirextionSize;		// �S�[��UI�̃T�C�Y
	int  m_Directionframe;		// ���o���̃J�E���g
	int  m_LoadAnimframe;		// �A�j���[�V�������̃J�E���g
	bool m_bGoalFlag;			// �S�[���������̃t���O
	DirectX::XMFLOAT2 m_UvPos;	// NowLoading�A�j���[�V������UV�|�W�V����
	int m_StartUICnt;			//�X�^�[�gUI�\���p�J�E���g�ϐ�
	bool m_bGoalSound;			//�S�[�����̃T�E���h�t���O
	int m_nGoalSelectKind;		// �S�[�����̑I�����̑I��ł��
	float m_fGoalTexPos;
	float m_ftime;				//��]�Ŏg������
	float m_fGoalButton_Return;	// �S�[����UI�i�Z���N�g�ɖ߂�j
	float m_fGoalButton_Next;	// �S�[����UI�i���̃X�e�[�W�ցj

	// �C���X�^���X��
	CameraBase* m_pCamera;
	Texture* m_pTexture[MAX_DIRECTION_TEX];
	Texture* m_pGoalShineTex;
	Texture* m_pGoalTextTex;
	Easing* m_pEasing;
	Easing* m_pTextEase;
	CAnim* m_pAnim;
	PixelShader* m_pGoalEfectPS;

	//---- �T�E���h�f�[�^ ----
	//���莞SE
	XAUDIO2_BUFFER* m_pSEDecision;
	IXAudio2SourceVoice* m_pSESpeaker;
	//�X�^�[�g���W���O��
	XAUDIO2_BUFFER* m_pSEStart;
	IXAudio2SourceVoice* m_pSEStartSpeaker;
	//�S�[�����W���O��
	XAUDIO2_BUFFER* m_pSEGoal;
	IXAudio2SourceVoice* m_pSEGoalSpeaker;

};

#endif // !__UI_DIRECTION_H__