#ifndef __WORLD5_UI_H__
#define __WORLD5_UI_H__

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
#define W5_MAX_UI_TEX (5)
#define W5_STAGE_TEX  (10)

// UIの座標
#define W5_STAGE_01_POSX (400.0f)
#define W5_STAGE_01_POSY (125.0f)

#define W5_STAGE_02_POSX (400.0f)
#define W5_STAGE_02_POSY (300.0f)

#define W5_STAGE_03_POSX (410.0f)
#define W5_STAGE_03_POSY (475.0f)

#define W5_STAGE_04_POSX (875.0f)
#define W5_STAGE_04_POSY (400.0f)

#define W5_STAGE_05_POSX (880.0f)
#define W5_STAGE_05_POSY (450.0f)

#define W5_STAGE_06_POSX (880.0f)
#define W5_STAGE_06_POSY (275.0f)

#define W5_STAGE_07_POSX (900.0f)
#define W5_STAGE_07_POSY (190.0f)

#define W5_STAGE_08_POSX (750.0f)
#define W5_STAGE_08_POSY (190.0f)

#define W5_STAGE_09_POSX (190.0f)
#define W5_STAGE_09_POSY (450.0f)

#define W5_STAGE_10_POSX (835.0f)
#define W5_STAGE_10_POSY (550.0f)

// 移動用座標
#define W5_MOVECURSOR_STAGE1_1 (85.0f)
#define W5_MOVECURSOR_STAGE1_2 (175.0f)

#define W5_MOVECURSOR_STAGE2_1 (175.0f)
#define W5_MOVECURSOR_STAGE2_2 (395.0f)

#define W5_MOVECURSOR_STAGE3_1 (360.0f)
#define W5_MOVECURSOR_STAGE3_2 (560.0f)

#define W5_MOVECURSOR_STAGE4_1 (765.0f)
#define W5_MOVECURSOR_STAGE4_2 (995.0f)

#define W5_MOVECURSOR_STAGE5_1 (575.0f)
#define W5_MOVECURSOR_STAGE5_2 (350.0f)

#define W5_MOVECURSOR_STAGE6_1 (395.0f)
#define W5_MOVECURSOR_STAGE6_2 (180.0f)

#define W5_MOVECURSOR_STAGE7_1 (190.0f)
#define W5_MOVECURSOR_STAGE7_2 (980.0f)

#define W5_MOVECURSOR_STAGE8_1 (680.0f)
#define W5_MOVECURSOR_STAGE8_2 (175.0f)

#define W5_MOVECURSOR_STAGE9_1 (500.0f)
#define W5_MOVECURSOR_STAGE9_2 (360.0f)

#define W5_MOVECURSOR_STAGE10  (450.0f)

// クラス
class World5_UI
{
public:
	World5_UI();
	~World5_UI();

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
	Texture* m_pTexture[W5_MAX_UI_TEX];
	Texture* m_pStageTex[W5_STAGE_TEX];
	Texture* m_pButtonTex;
	Easing* m_pEasing;
	Easing* m_pPopUpEase;
	CAnim* m_pAnim;

	float m_PlayerCursorPos[20];
	float m_StageNamePos;
	float m_StageSelectPos;
	float m_ButtonSize;
	float m_fPopUpSize;
};

#endif // !__WORLD5_UI_H__

