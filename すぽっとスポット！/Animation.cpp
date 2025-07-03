//==============================================================
//
//  ファイル名：Animation.cpp
//
//　　概要：
//	アニメーションの管理
//
//==============================================================

//---- インクルード部　----
#include "Animation.h"
#include "Defines.h"
#include "Input.h"

//==============================================================
//　関数名：CAnim::CAnim()
//	引数１：なし
//	戻り値：なし
//
//	概　要：アニメーションクラスのコンストラクタ
//		
//==============================================================
CAnim::CAnim()
	: m_size(100.0f, 100.0f),
	  m_pos((float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2, 0.0f),
	  m_PosTexCoord(0.0f, 0.0f),
	  m_SizeTexCoord(1.0f / (float)LOAD_ANIM_SPLIT_X, 1.0f / (float)LOAD_ANIM_SPLIT_Y),
	  m_fAngle(0.0f),
	  m_nFrame(0),
	  m_nCurrentAnimNo(0),
	  m_AnimData{ LOAD_ANIM_SPLIT_X, LOAD_ANIM_SPLIT_Y, LOAD_ANIM_FRAME, LOAD_ANIM_END },
	  m_nMoveframe(0),
	  m_nScaleframe(0),
	  m_nRotatframe(0),
	  m_bMoveAnim(true),
	  m_nClickAnimflg(shrink)
{

}

//==============================================================
//　関数名：CAnim::~CAnim()
//	引数１：なし
//	戻り値：なし
//
//	概　要：アニメーションクラスのデストラクタ
//		
//==============================================================
CAnim::~CAnim()
{
}

//==============================================================
//　関数名：CAnim::Animation_Move()
//	引数１：float MovePos(移動させる座標)
//	引数２：float Aroundframe(１周にかかるフレーム数)
//	引数２：float Distance(移動距離)
//	戻り値：sinf(DirectX::XMConvertToRadians(angle)) * moveDistance + cursorPosX;
//
//	概　要：横移動アニメーション
//		
//==============================================================
float CAnim::Animation_Move(float MovePos, float Aroundframe, float Distance)
{
	m_nMoveframe++;

	//１週にかかるフレームを０～１で表す
	float rate = (float)m_nMoveframe / Aroundframe;
	//現在の経過時間に応じた角度を求める
	float angle = 360.0f * rate;
	//カーソルが動く距離(sinが１～ー１のため増やしたい分だけここに入れる)
	float moveDistance = Distance;
	//カーソルの初期位置
	float cursorPosX = MovePos;

	return sinf(DirectX::XMConvertToRadians(angle)) * moveDistance + cursorPosX;
}

//==============================================================
//　関数名：CAnim::Animation_Scale()
//	引数１：float Aroundframe(１周にかかるフレーム数)
//	引数２：float ChangeScale(大きさの変化量)
//	引数３：float Minsize(最小の大きさ)
//	戻り値：sinScale * scaleRnage + minScale
//
//	概　要：回転アニメーション
//		
//==============================================================
float CAnim::Animation_Rotation(float Aroundframe, float swingangle)
{
	m_nRotatframe++;

	//１週にかかるフレームを０～１で表す
	float rate = (float)m_nRotatframe / Aroundframe;
	//現在の経過時間に応じた角度を求める
	float angle = 360.0f * rate;
	//揺れる角度
	float swinangle = swingangle;

	//揺れる角度は通常の角度の指定なので、ラジアン角に再度変換する
	return DirectX::XMConvertToRadians(sinf(DirectX::XMConvertToRadians(angle)) * swinangle);
}

//==============================================================
//　関数名：CAnim::Animation_Scale()
//	引数１：float Aroundframe(１周にかかるフレーム数)
//	引数２：float ChangeScale(大きさの変化量)
//	引数３：float Minsize(最小の大きさ)
//	戻り値：sinScale * scaleRnage + minScale
//
//	概　要：拡縮アニメーション
//		
//==============================================================
float CAnim::Animation_Scale(float Aroundframe, float ChangeScale, float Minsize)
{
	m_nScaleframe++;

	//１週にかかるフレームを０～１で表す
	float rate = (float)m_nScaleframe / Aroundframe;
	//現在の経過時間に応じた角度を求める
	float angle = 360.0f * rate;
	//１～ー１の範囲で拡縮すると画像が反転するので、０～１の間に収まるように変換する（* 0.5f + 0.5f）
	float sinScale = sinf(DirectX::XMConvertToRadians(angle)) * 0.5f + 0.5f;
	//拡縮の変化量
	float scaleRnage = ChangeScale;
	//最小スケール
	float minScale = Minsize;

	return sinScale * scaleRnage + minScale;
}

//==============================================================
//　関数名：CAnim::Animation_Click()
//	引数１：float MoveSize
//  引数２：float DefaultSize
//  引数３：float turnback
//  引数４：float movescale
//	戻り値：ReturnSize
//
//	概　要：何かを押したときのアニメーション
//		
//==============================================================
float CAnim::Animation_Click(float MoveSize, float DefaultSize, float turnback, float movescale)
{
	float ReturnSize = MoveSize;

	if (ReturnSize > turnback && m_nClickAnimflg == shrink)
	{
		ReturnSize -= movescale;
	}
	else
	{
		m_nClickAnimflg = expansion;
	}

	if (ReturnSize < DefaultSize && m_nClickAnimflg == expansion)
	{
		ReturnSize += movescale;
	}

	return ReturnSize;
}


//==============================================================
//　関数名：CAnim::TextureAnimation()
//	引数１：なし
//	戻り値：なし
//
//	概　要：テクスチャアニメーションの更新用
//		
//==============================================================
DirectX::XMFLOAT2 CAnim::TextureAnimation(bool Loop)
{
	// アニメーション番号の更新
	if (m_bMoveAnim)	// アニメーションを行うか
	{
		// アニメーションフレームの更新
		m_nFrame++;

		if (0 == m_nFrame % m_AnimData.nAnimeFrame)
		{
			m_nCurrentAnimNo++;	// 現在のコマ番号を更新

			// テクスチャ座標の更新
			m_PosTexCoord.x = m_SizeTexCoord.x * (m_nCurrentAnimNo % m_AnimData.nAnimeSplitX);
			m_PosTexCoord.y = m_SizeTexCoord.y * (m_nCurrentAnimNo / m_AnimData.nAnimeSplitX);
		}
	}

	if (Loop)
	{
		// ループアニメーション処理
		// アニメーションのリセット(最終フレームに到達したかの)チェック
		// 到達したら最初のコマへ戻る
		if (m_AnimData.nAnimeFrame * m_AnimData.nEndAnimNo <= m_nFrame)
		{
			m_PosTexCoord.x = 0;
			m_PosTexCoord.y = 0;
			m_nCurrentAnimNo = 0;
			m_nFrame = 0;
		}
	}
	else
	{
		// ループじゃないアニメーション
		// アニメーションのストップ(最終フレームに到達したかの)チェック
		// 到達したらアニメーションを止める
		if (m_AnimData.nAnimeFrame * m_AnimData.nEndAnimNo <= m_nFrame)
		{
			m_bMoveAnim = false;
		}
	}

	return m_PosTexCoord;
}

//==============================================================
//　関数名：CAnim::ResetUvPos()
//	引数１：なし
//	戻り値：なし
//
//	概　要：テクスチャアニメーションのUV座標のリセット
//		
//==============================================================
void CAnim::ResetUvPos()
{
	m_PosTexCoord = DirectX::XMFLOAT2(0.0f, 0.0f);
	m_nCurrentAnimNo = 0;
	m_nFrame = 0;
	m_bMoveAnim = true;
}

//==============================================================
//　関数名：CAnim::ResetMoveframe()
//	引数１：なし
//	戻り値：なし
//
//	概　要：横移動アニメーションのカウント用フレームのリセット
//		
//==============================================================
void CAnim::ResetMoveframe()
{
	m_nMoveframe = 0;
}

void CAnim::SetClickAnimkind()
{
	m_nClickAnimflg = shrink;
}

//==============================================================
//　関数名：CAnim::GetCurrentNo()
//	引数１：なし
//	戻り値：なし
//
//	概　要：テクスチャアニメーションのコマ番号を返す関数
//		
//==============================================================
int CAnim::GetCurrentNo()
{
	return m_nCurrentAnimNo;
}

//==============================================================
//　関数名：CAnim::SetAnime(AnimData Data)
//	引数１：アニメーションデータ
//	戻り値：なし
//
//	概　要：テクスチャアニメーションに関する値を設定する関数
//		
//==============================================================
void CAnim::SetAnime(AnimData Data)
{
	//---- 値の代入 ----
	m_AnimData = Data;

	//---- UVサイズの計算 ----
	m_SizeTexCoord.x = 1.0f / Data.nAnimeSplitX;
	m_SizeTexCoord.y = 1.0f / Data.nAnimeSplitY;
}

//==============================================================
//　関数名：CAnim::GetIsEnd()
//	引数１：なし
//	戻り値：アニメーションの終了の有無
//
//	概　要：テクスチャアニメーションが終了したかを返す関数
//		
//==============================================================
bool CAnim::GetIsEnd()
{
	return !m_bMoveAnim;
}
