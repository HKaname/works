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
#define TITLE_ANIM_FRAME							    (2)  // 一コマごとの更新フレーム
#define TITLE_ANIME_SPLIT_X							    (8)  // タイトルアニメーションテクスチャ分割数X
#define TITLE_ANIME_SPLIT_Y							   (12)  // タイトルアニメーションテクスチャ分割数Y
#define TITLE_ANIME_END								   (90)  // タイトルアニメーションテクスチャ最後のコマ
#define TITLE_ANIME_DELAYFRAME						   (540) // タイトルアニメーションの待機時間

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

	//サウンド
	XAUDIO2_BUFFER* m_pSEJump;				//ジャンプ
	IXAudio2SourceVoice* m_pSEJumpSpeaker;	//ジャンプ
	XAUDIO2_BUFFER* m_pSEButton;			//ボタン
	IXAudio2SourceVoice* m_pSEButtonSpeaker;//ボタン
	XAUDIO2_BUFFER* m_pSEMoveCursor;			//カーソル移動
	IXAudio2SourceVoice* m_pSEMoveCursorSpeaker;//カーソル移動
};

#endif // !__TITLE_UI_H__

