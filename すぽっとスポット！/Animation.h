#ifndef __ANIMATION_H__
#define __ANIMATION_H__

//---- インクルード部 ----
#include "Model.h"
#include "Texture.h"

//---- 定数定義 ----
#define LOAD_ANIM_FRAME    (1)
#define LOAD_ANIM_SPLIT_X  (8)
#define LOAD_ANIM_SPLIT_Y (11)
#define LOAD_ANIM_END     (86)

//---- 構造体定義 ----
struct AnimData
{
	int nAnimeSplitX;                 // テクスチャの分割数
	int nAnimeSplitY;                 // テクスチャの分割数
	int nAnimeFrame;                  // UV座標が切り替わるフレーム数
	int nEndAnimNo;                   // コマ番号の最後
};

//---- クラス ----
class CAnim
{
public:
	enum ClickMovekind
	{
		shrink,
		expansion
	};

public:
	CAnim();
	~CAnim();

	float Animation_Move(float MovePos, float Aroundframe, float Distance);
	float Animation_Rotation(float Aroundframe, float swingangle);
	float Animation_Scale(float Aroundframe, float ChangeScale, float Minsize);
	float Animation_Click(float MoveSize, float DefaultSize, float turnback, float movescale);
	DirectX::XMFLOAT2 TextureAnimation(bool Loop);	// tureならループする、falseならループしない
	void ResetUvPos();
	void ResetMoveframe();
	void SetClickAnimkind();
	int GetCurrentNo();
	void SetAnime(AnimData Data);
	bool GetIsEnd();

private:
	DirectX::XMFLOAT3 m_pos;			// 中心座標
	DirectX::XMFLOAT2 m_size;			// 縦横サイズ
	DirectX::XMFLOAT2 m_PosTexCoord;	// テクスチャ座標(左上)
	DirectX::XMFLOAT2 m_SizeTexCoord;	// テクスチャサイズ(右下)(0.0~1.0f)
	AnimData m_AnimData;                // アニメーションを行う際に使用する値
	float m_fAngle;						// 回転角度
	int m_nFrame;						// アニメーション管理用フレーム
	int m_nCurrentAnimNo;				// アニメーションのコマ番号
	int m_nMoveframe;					// 横移動アニメーション用フレーム
	int m_nRotatframe;					// 揺れるアニメーション用フレーム
	int m_nScaleframe;					// 拡縮アニメーション用フレーム
	bool m_bMoveAnim;					// テクスチャアニメーション稼動用フラグ
	int m_nClickAnimflg;				// クリック時のアニメーションの状態
};

#endif // !__ANIMATION_H__
