#ifndef __WORLD3_UI_H__
#define __WORLD3_UI_H__

// インクルード部
#include "DirectXTex/TextureLoad.h"
#include "Sprite.h"
#include "CameraBase.h"
#include "Geometory.h"
#include "Defines.h"
#include "Texture.h"
#include "Easing.h"
#include "Animation.h"
#include "SceneStageSelect.h"
#include "Main.h"

// 定数定義
#define W3_MAX_UI_TEX (10)
#define W3_STAGE_TEX   (7)

// UIの座標
#define W3_STAGE_01_POSX (325.0f)
#define W3_STAGE_01_POSY (310.0f)

#define W3_STAGE_02_POSX (580.0f)
#define W3_STAGE_02_POSY (310.0f)

#define W3_STAGE_03_POSX (840.0f)
#define W3_STAGE_03_POSY (310.0f)

#define W3_STAGE_04_POSX (835.0f)
#define W3_STAGE_04_POSY (350.0f)

#define W3_STAGE_05_POSX (1090.0f)
#define W3_STAGE_05_POSY (365.0f)

#define W3_STAGE_06_POSX (880.0f)
#define W3_STAGE_06_POSY (365.0f)

#define W3_STAGE_07_POSX (640.0f)
#define W3_STAGE_07_POSY (365.0f)

// 移動用座標
#define W3_MOVECURSOR_POS10 (250.0f)
#define W3_MOVECURSOR_POS1 (425.0f)

#define W3_MOVECURSOR_POS2 (490.0f)
#define W3_MOVECURSOR_POS3 (675.0f)

#define W3_MOVECURSOR_POS4 (750.0f)
#define W3_MOVECURSOR_POS5 (930.0f)

#define W3_MOVECURSOR_POS6 (260.0f)
#define W3_MOVECURSOR_POS7 (450.0f)

#define W3_MOVECURSOR_POS8 (780.0f)
#define W3_MOVECURSOR_POS9 (975.0f)

#define W3_MOVECURSOR_POS11 (560.0f)
#define W3_MOVECURSOR_POS12 (750.0f)

#define W3_MOVECURSOR_POS13 (540.0f)
#define W3_MOVECURSOR_POS_NEXT (150.0f)

// クラス
class World3_UI
{
public:
	World3_UI();
	~World3_UI();

	void In_Other();
	void Out_StageName();
	void RasetEase();
	void Draw_clear(float PosX, float PosY);
	void Draw_NextCursor(int SelectStage);
	void Draw_Other();
	void Move_PlayerCursor(int SelectStage);
	void Draw_Stage(int SelectStage);

private:
	// インスタンス化
	CameraBase* m_pCamera;
	Texture* m_pTexture[W3_MAX_UI_TEX];
	Texture* m_pStageTex[W3_STAGE_TEX];
	Texture* m_pButtonTex;
	Easing* m_pEasing;
	Easing* m_pPopUpEase;
	CAnim* m_pAnim;

	float m_PlayerCursorPos[14];
	float m_StageNamePos;
	float m_StageSelectPos;
	float m_ButtonSize;
	float m_fPopUpSize;
};

#endif // !__WORLD3_UI_H__

