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

// 定数定義
#define MAX_DIRECTION_TEX (11)

// 列挙体定義
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
	float m_Di_UIPosX[3];		// UIの座標
	float m_alpha[3];			// UIの画像の濃さ
	float m_angle;				// UI画像の傾き
	float m_GoalTexangle;		// ゴール時画像の傾き
	bool m_bGoalDirection;		// ゴール演出を行っているかの判定
	bool m_bStartDirection;		// スタート演出の切り替え用
	bool m_bEndFade;			// ゴール時のフェードが行われているかの判定
	float m_DirextionSize;		// ゴールUIのサイズ
	int  m_Directionframe;		// 演出時のカウント
	int  m_LoadAnimframe;		// アニメーション時のカウント
	bool m_bGoalFlag;			// ゴールした時のフラグ
	DirectX::XMFLOAT2 m_UvPos;	// NowLoadingアニメーションのUVポジション
	int m_StartUICnt;			//スタートUI表示用カウント変数
	bool m_bGoalSound;			//ゴール時のサウンドフラグ
	int m_nGoalSelectKind;		// ゴール時の選択肢の選んでる状況
	float m_fGoalTexPos;
	float m_ftime;				//回転で使う時間
	float m_fGoalButton_Return;	// ゴール時UI（セレクトに戻る）
	float m_fGoalButton_Next;	// ゴール時UI（次のステージへ）

	// インスタンス化
	CameraBase* m_pCamera;
	Texture* m_pTexture[MAX_DIRECTION_TEX];
	Texture* m_pGoalShineTex;
	Texture* m_pGoalTextTex;
	Easing* m_pEasing;
	Easing* m_pTextEase;
	CAnim* m_pAnim;
	PixelShader* m_pGoalEfectPS;

	//---- サウンドデータ ----
	//決定時SE
	XAUDIO2_BUFFER* m_pSEDecision;
	IXAudio2SourceVoice* m_pSESpeaker;
	//スタート時ジングル
	XAUDIO2_BUFFER* m_pSEStart;
	IXAudio2SourceVoice* m_pSEStartSpeaker;
	//ゴール時ジングル
	XAUDIO2_BUFFER* m_pSEGoal;
	IXAudio2SourceVoice* m_pSEGoalSpeaker;

};

#endif // !__UI_DIRECTION_H__