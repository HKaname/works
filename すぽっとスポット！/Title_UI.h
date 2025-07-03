#ifndef __TITLE_UI_H__
#define __TITLE_UI_H__

#include "DirectXTex/TextureLoad.h"
#include "Sprite.h"
#include "CameraBase.h"
#include "Geometory.h"
#include "Defines.h"
#include "Texture.h"
#include "Animation.h"
#include "Input.h"
#include "Sound.h"

#define MAX_UI_TEXTURE (9)
#define TITLE_ANIM_FRAME							    (2)  // ��R�}���Ƃ̍X�V�t���[��
#define TITLE_ANIME_SPLIT_X							    (8)  // �^�C�g���A�j���[�V�����e�N�X�`��������X
#define TITLE_ANIME_SPLIT_Y							   (12)  // �^�C�g���A�j���[�V�����e�N�X�`��������Y
#define TITLE_ANIME_END								   (90)  // �^�C�g���A�j���[�V�����e�N�X�`���Ō�̃R�}
#define TITLE_ANIME_DELAYFRAME						   (540) // �^�C�g���A�j���[�V�����̑ҋ@����

class Title_UI
{
public:
	enum TitleKind
	{
		E_START,
		E_CONTINUE
	};

public:
	Title_UI();
	~Title_UI();
	void Update();
	void Draw();
	TitleKind GetTitleKind() { return (TitleKind)m_TitleKind; }

private:
	CameraBase *m_pCamera;
	CAnim* m_pAnim;
	Texture* m_pTitleTex;
	Texture* m_pUITex[MAX_UI_TEXTURE];

	float m_CursorPosX;
	float m_CursorPosY;
	int m_TitleKind;
	DirectX::XMFLOAT2 m_UVPos;
	float m_CursorSize;
	float m_SelectSize_Start;
	float m_SelectSize_End;
	float m_Alpha;
	int m_TitleAnimDelayframe;
	bool m_ClickAnimflg;

	//�T�E���h
	XAUDIO2_BUFFER* m_pSEJump;				//�W�����v
	IXAudio2SourceVoice* m_pSEJumpSpeaker;	//�W�����v
	XAUDIO2_BUFFER* m_pSEButton;			//�{�^��
	IXAudio2SourceVoice* m_pSEButtonSpeaker;//�{�^��
	XAUDIO2_BUFFER* m_pSEMoveCursor;			//�J�[�\���ړ�
	IXAudio2SourceVoice* m_pSEMoveCursorSpeaker;//�J�[�\���ړ�
};

#endif // !__TITLE_UI_H__

