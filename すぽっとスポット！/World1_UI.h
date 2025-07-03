#ifndef __WORLD1_UI_H__
#define __WORLD1_UI_H__

// インクルード部
#include "DirectXTex/TextureLoad.h"
#include "Sprite.h"
#include "CameraBase.h"
#include "Geometory.h"
#include "Defines.h"
#include "Texture.h"
#include "Easing.h"
#include "Animation.h"

// 定数定義
#define W1_MAX_UI_TEX (10)

// クラス
class World1_UI
{
public:
	World1_UI();
	~World1_UI();

	void In_Other();
	void Out_StageName();
	void Draw_clear(float PosX, float PosY);
	void Draw_NextCursor(int SelectStage, bool EX);
	void Draw_Other();
	void ResetEase();
	bool GetIsPlay();
	void Move_PlayerCursor1();
	void Move_PlayerCursor2();
	void Move_PlayerCursor3();
	void Move_PlayerCursor4();
	void Move_PlayerCursor5();
	void Draw_Stage1();
	void Draw_Stage2();
	void Draw_Stage3();
	void Draw_Stage4();
	void Draw_Stage5();

private:
	// インスタンス化
	CameraBase* m_pCamera;
	Texture* m_pTexture[W1_MAX_UI_TEX];
	Texture* m_pButtonTex;
	Easing* m_pEasing;
	Easing* m_pPopUpEase;
	CAnim* m_pAnim;

	float m_PlayerCursorPos[10];
	float m_StageNamePos;
	float m_StageSelectPos;
	float m_ButtonSize;
	float m_pPopUpSize;
};

#endif // !__WORLD1_UI_H__
