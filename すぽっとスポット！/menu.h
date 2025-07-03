#ifndef __MENU_H__
#define __MENU_H__

// インクルード部
#include "DirectXTex/TextureLoad.h"
#include "Sprite.h"
#include "CameraBase.h"
#include "Geometory.h"
#include "Defines.h"
#include "Texture.h"
#include "Easing.h"
#include "Sound.h"
#include "Animation.h"

// 定数定義
#define MAX_TEXTURE (18)	// テクスチャの数
#define MAX_SECRET_TEX (7)	// ひみつのテクスチャの数

//---- アニメーションデータ ----
#define MAX_ANIM_TEX							(5)	  // アニメーションのテクスチャの枚数
#define MENU_ANIM_FRAME							(1)   // 一コマごとの更新フレーム
#define MENU_ANIME_SPLIT_X						(8)   // タイトルアニメーションテクスチャ分割数X
#define MENU_ANIME_SPLIT_Y						(8)   // タイトルアニメーションテクスチャ分割数Y
#define MENU_ANIME_END							(63)  // タイトルアニメーションテクスチャ最後のコマ

// 列挙体定義
enum MenuKind	// メニューが開かれているか
{
	E_NONE,		 // 何も起こさない
	E_OPEN,		 // 開く
	E_CLOSE,	 // 閉じる
	E_MOTIONLESS // 動かさない
};

enum MenuSelectKind  // メニューの選択状態
{
	E_CONTINU, // 続ける
	E_RETRY,   // リトライ
	E_RETRUN  // セレクトに戻る
};

enum MenuAnimationKind	// メニューのアニメーションの状態
{
	E_CONTINUE_LR,
	E_CONTINUE_UD,
	E_RETRY_UP,
	E_RETRY_DOWN,
};

// クラス定義
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
	void PlaySEOpen();		//オープンSE再生
	void PlaySEClose();		//クローズSE再生
	void PlaySEDecision();	//決定音SE再生

	void SetCamera(CameraBase* pCamera);

private:
	int m_MenuSelectKind;		//メニューの選択状態
	int m_OldSelectMenu;		//一個前に選んでたメニューの状態
	int m_MenuAnimKind;			//メニューのアニメーションの状態
	int m_MenuKind;
	int m_nDrawNum;				//描画の順番
	float m_MenuPosX[2];		//メニューの描画座標(０ = 左,1　= 右)
	float m_GameUIPosX;			//スタート時のメニューの移動距離（だと思われる）
	bool m_bMenu;				//メニューが開かれてるか判定
	bool m_RetryFlg;			//リトライが押されたかの判定
	bool m_ReturnFlg;			//セレクトに戻るが押されたかの判定
	int  m_RandomNo;			//すぽいむのひみつのランダムで選ばれた値の格納先
	int  m_nOldRandNo;			//すぽいむのひみつのランダムで選ばれた値の保存先
	float m_MenuSelectSize;
	bool  m_ClickAnimflg;
	DirectX::XMFLOAT2 m_MenuAnim_UVPos;

	// インスタンス化
	CameraBase* m_pCamera;
	Texture* m_pTexture[MAX_TEXTURE];
	Texture* m_pSecretTex[MAX_SECRET_TEX];
	Texture* m_pAnimTex[MAX_ANIM_TEX];
	Texture* m_pEXdifficulty;
	Easing* m_pEasing;
	CAnim* m_pAnimation;

	//サウンド
	XAUDIO2_BUFFER* m_pSEMenuOpen;			//メニューオープン
	XAUDIO2_BUFFER* m_pSEMenuClose;			//メニュークローズ
	XAUDIO2_BUFFER* m_pSEMenuDecision;		//メニュー決定時
	IXAudio2SourceVoice* m_pSEMenuSpeaker;	//メニューの再生用
	XAUDIO2_BUFFER* m_pSEMenuMove;			//メニュー移動音
	IXAudio2SourceVoice* m_pSEMenuMoveSpeaker;	//メニュー移動再生用
	XAUDIO2_BUFFER* m_pSEMenuRetry;			//メニューリトライ時
	IXAudio2SourceVoice* m_pSEMenuRetrySpeaker;	//メニューリトライ再生用
};

#endif // !__MENU_H__
