#ifndef __WORLD4_UI_H__
#define __WORLD4_UI_H__

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
#define W4_MAX_UI_TEX (5)
#define W4_STAGE_TEX  (8)

// UIの座標
#define W4_STAGE_01_POSX (235.0f)
#define W4_STAGE_01_POSY (350.0f)

#define W4_STAGE_02_POSX (725.0f)
#define W4_STAGE_02_POSY (560.0f)

#define W4_STAGE_03_POSX (725.0f)
#define W4_STAGE_03_POSY (335.0f)

#define W4_STAGE_04_POSX (725.0f)
#define W4_STAGE_04_POSY (175.0f)

#define W4_STAGE_05_POSX (525.0f)
#define W4_STAGE_05_POSY (175.0f)

#define W4_STAGE_06_POSX (525.0f)
#define W4_STAGE_06_POSY (335.0f)

#define W4_STAGE_07_POSX (525.0f)
#define W4_STAGE_07_POSY (495.0f)

#define W4_STAGE_08_POSX (975.0f)
#define W4_STAGE_08_POSY (350.0f)

// 移動用座標
#define W4_MOVECURSOR_POS1 (325.0f)
#define W4_MOVECURSOR_POS2 (585.0f)

#define W4_MOVECURSOR_POS3 (450.0f)
#define W4_MOVECURSOR_POS4 (410.0f)

#define W4_MOVECURSOR_POS5 (435.0f)
#define W4_MOVECURSOR_POS6 (265.0f)

#define W4_MOVECURSOR_POS7 (250.0f)
#define W4_MOVECURSOR_POS8 (80.0f)

#define W4_MOVECURSOR_POS9 (250.0f)
#define W4_MOVECURSOR_POS10 (80.0f)

#define W4_MOVECURSOR_POS11 (435.0f)
#define W4_MOVECURSOR_POS12 (265.0f)

#define W4_MOVECURSOR_POS13 (800.0f)
#define W4_MOVECURSOR_POS14 (410.0f)

#define W4_MOVECURSOR_POS15 (885.0f)
#define W4_MOVECURSOR_POS_NEXT (1065.0f)

// クラス
class World4_UI
{
public:
	World4_UI();
	~World4_UI();

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
	Texture* m_pTexture[W4_MAX_UI_TEX];
	Texture* m_pStageTex[W4_STAGE_TEX];
	Texture* m_pButtonTex;
	Easing* m_pEasing;
	Easing* m_pPopupEase;
	CAnim* m_pAnim;

	float m_PlayerCursorPos[16];
	float m_StageNamePos;
	float m_StageSelectPos;
	float m_ButtonSize;
	float m_fPopUpSize;
};

#endif // !__WORLD4_UI_H__

