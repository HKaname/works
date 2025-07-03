#ifndef __TUTORIAL_H__
#define __TUTORIAL_H__

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

	// イージング確認
	bool GetIsPlayEase();

	// ボタン拡縮アニメーション
	void ButtonAnim();

	// チュートリアル表示
	void InTutorial();

	// チュートリアル退散
	void OutTutorial();

	// メッセージボックス表示
	void InMessageBox();

	// メッセージボックス退散
	void OutMessageBox();

	// ヒメ待機表示
	void Princess_Standby(int princesskind);

	// １－１チュートリアル描画
	void Draw_Step1_1();
	void Draw_Step2_1();
	void Draw_Step3_1();
	void Draw_Step4_1();

	// １－２チュートリアル描画
	void Draw_Step1_2();
	void Draw_Step2_2();
	void Draw_Step3_2();
	void Draw_Step4_2();
	void Draw_Step5_2();
	void Draw_Step6_2();

	// ３－１チュートリアル描画
	void Draw_Tutorial_3(int TutoStep);

	// ４ー１チュートリアル描画
	void Draw_Tutorial_4(int TutoStep);

private:
	float m_PrincessPos;	// ヒメの位置（Y）
	float m_BubblePos;		// 吹き出しの位置
	int m_AnimDelay;		// チュートリアルの最初のアニメーションのディレイ
	float m_ButtonSize;

	// データの作成用
	CameraBase* m_pCamera;
	Texture* m_pTexture[MAX_TUTORIAL_TEX];
	Texture* m_pWordsTex[9];
	Texture* m_pPrincessTex[9];
	Easing* m_pEasing;
	CAnim* m_pAnim;
};

#endif // !__TUTORIAL_H__
