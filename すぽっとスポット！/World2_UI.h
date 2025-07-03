#ifndef __WORLD2_UI_H__
#define __WORLD2_UI_H__

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
#define W2_MAX_UI_TEX (5)
#define W2_STAGE_TEX  (6)

// UIの座標
#define STAGE_01_POSX (260.0f)
#define STAGE_01_POSY (350.0f)
#define STAGE_02_POSX (550.0f)
#define STAGE_02_POSY (475.0f)
#define STAGE_03_POSX (710.0f)
#define STAGE_03_POSY (325.0f)
#define STAGE_04_POSX (880.0f)
#define STAGE_04_POSY (325.0f)
#define STAGE_05_POSX (1030.0f)
#define STAGE_05_POSY (410.0f)
#define STAGE_06_POSX (890.0f)
#define STAGE_06_POSY (480.0f)

// 移動用座標
#define MOVECURSOR_POS1 (360.0f)
#define MOVECURSOR_POS2 (440.0f)
#define MOVECURSOR_POS3 (460.0f)
#define MOVECURSOR_POS4 (190.0f)
#define MOVECURSOR_POS5 (355.0f)
#define MOVECURSOR_POS6 (775.0f)
#define MOVECURSOR_POS7 (625.0f)
#define MOVECURSOR_POS8 (200.0f)
#define MOVECURSOR_POS9 (360.0f)
#define MOVECURSOR_POS10 (200.0f)
#define MOVECURSOR_POS11 (975.0f)
#define MOVECURSOR_POS_NEXT (1150.0f)

// クラス
class World2_UI
{
public:
	World2_UI();
	~World2_UI();

	void In_Other();
	void Out_StageName();
	void Draw_clear(float PosX, float PosY);
	void Draw_NextCursor(int SelectStage);
	void Draw_Other();
	void ResetEase();
	void Move_PlayerCursor1();
	void Move_PlayerCursor2();
	void Move_PlayerCursor3();
	void Move_PlayerCursor4();
	void Move_PlayerCursor5();
	void Move_PlayerCursor6();
	void Draw_Stage1();
	void Draw_Stage2();
	void Draw_Stage3();
	void Draw_Stage4();
	void Draw_Stage5();
	void Draw_Stage6();

private:
	// インスタンス化
	CameraBase* m_pCamera;
	Texture* m_pTexture[W2_MAX_UI_TEX];
	Texture* m_pStageTex[W2_STAGE_TEX];
	Texture* m_pButtonTex;
	Easing* m_pEasing;
	Easing* m_pPopUpEase;
	CAnim* m_pAnim;

	float m_PlayerCursorPos[12];
	float m_StageNamePos;
	float m_StageSelectPos;
	float m_ButtonSize;
	float m_fPopupSize;
};

#endif // !__WORLD22_UI_H__
