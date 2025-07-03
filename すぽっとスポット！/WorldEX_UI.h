#ifndef __WORLD_EX_UI_H__
#define __WORLD_EX_UI_H__

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
#define EX_MAX_UI_TEX (5)
#define EX_STAGE_TEX  (5)

// UIの座標
#define EX_STAGE_01_POSX (525.0f)
#define EX_STAGE_01_POSY (200.0f)

#define EX_STAGE_02_POSX (525.0f)
#define EX_STAGE_02_POSY (450.0f)

#define EX_STAGE_03_POSX (410.0f)
#define EX_STAGE_03_POSY (450.0f)

#define EX_STAGE_04_POSX (410.0f)
#define EX_STAGE_04_POSY (200.0f)

#define EX_STAGE_05_POSX (1100.0f)
#define EX_STAGE_05_POSY (475.0f)

// 移動用座標
#define EX_MOVECURSOR_STAGE1_1 (60.0f)
#define EX_MOVECURSOR_STAGE1_2 (265.0f)

#define EX_MOVECURSOR_STAGE2_1 (480.0f)
#define EX_MOVECURSOR_STAGE2_2 (450.0f)

#define EX_MOVECURSOR_STAGE3_1 (500.0f)
#define EX_MOVECURSOR_STAGE3_2 (480.0f)

#define EX_MOVECURSOR_STAGE4_1 (265.0f)
#define EX_MOVECURSOR_STAGE4_2 (750.0f)

#define EX_MOVECURSOR_STAGE5_1 (375.0f)

// クラス
class WorldEX_UI
{
public:
	WorldEX_UI();
	~WorldEX_UI();

	void In_Other();
	void Out_StageName();
	void ResetEase();
	void Draw_clear(float PosX, float PosY);
	void Draw_NextCursor(int SelectStage);
	void Draw_Other();
	void Move_PlayerCursor(int SelectStage);
	void Draw_Stage(int SelectStage);

private:
	// インスタンス化
	CameraBase* m_pCamera;
	Texture* m_pTexture[EX_MAX_UI_TEX];
	Texture* m_pStageTex[EX_STAGE_TEX];
	Texture* m_pButtonTex;
	Easing* m_pEasing;
	Easing* m_pPopUpEase;
	CAnim* m_pAnim;

	float m_PlayerCursorPos[10];
	float m_StageNamePos;
	float m_StageSelectPos;
	float m_ButtonSize;
	float m_fPopUpSize;
};

#endif // !__WORLD_EX_UI_H_

