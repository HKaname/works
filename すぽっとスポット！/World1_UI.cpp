//==============================================================
//
//  ファイル名：World1_UI.cpp
//
//	概要：
//	ステージセレクト画面でのUIの描画及び更新を行う
//
//==============================================================

// インクルード部
#include "World1_UI.h"
#include "Main.h"
#include "SceneStageSelect.h"

//==============================================================
//　関数名：World1_UI::World1_UI()
//	引数１：なし
//	戻り値：なし
//
//	概　要：World1_UIクラスのコンストラクタ	
//==============================================================
World1_UI::World1_UI()
	: m_StageNamePos(-300.0f),
	  m_StageSelectPos(-350.0f),
	  m_PlayerCursorPos{590.0f,325.0f,175.0f,760.0f,615.0f,565.0f,425.0f,750.0f,900.0f,490.0f},
	  m_ButtonSize(75.0f),
	  m_pPopUpSize(0.0f)
{
	//---- テクスチャクラスの確保 ----
	for (int i = 0; i < W1_MAX_UI_TEX; i++)
	{
		m_pTexture[i] = new Texture();
	}

	//---- テクスチャの読み込み ----
	// ステージセレクト
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Select/UI_StageSelect_StageSelect_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_StageSelect_001.pngが読み込めませんでした", "Error", MB_OK);
	}
	// はじまりのさくら
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Select/UI_StageSelect_Stagename_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Stagename_001.pngが読み込めませんでした", "Error", MB_OK);
	}
	// 戻るボタン
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Select/UI_StageSelect_Back_003.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Back.pngが読み込めませんでした", "Error", MB_OK);
	}

	// ステージ
	// 1-1
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Select/Stage01/1-1.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_1).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 1-2
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Select/Stage01/1-2.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_2).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 1-3
	if (FAILED(m_pTexture[5]->Create("Assets/Texture/UI/Select/Stage01/1-3.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_3).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 1-4
	if (FAILED(m_pTexture[6]->Create("Assets/Texture/UI/Select/Stage01/1-4.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_4).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 1-5
	if (FAILED(m_pTexture[7]->Create("Assets/Texture/UI/Select/Stage01/1-5.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).pngが読み込めませんでした", "Error", MB_OK);
	}

	// クリア
	if (FAILED(m_pTexture[8]->Create("Assets/Texture/UI/Select/UI_StageSelect_ClearIcon_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_ClearIcon_002.pngが読み込めませんでした", "Error", MB_OK);
	}

	// 次のステージを示すカーソル
	if (FAILED(m_pTexture[9]->Create("Assets/Texture/UI/Select/UI_Title_Select.png")))
	{
		MessageBox(NULL, "UI_Title_Select.pngが読み込めませんでした", "Error", MB_OK);
	}

	// Aボタン
	m_pButtonTex = new Texture();
	if (FAILED(m_pButtonTex->Create("Assets/Texture/UI/Select/UI_common_ButtonA_003.png")))
	{
		MessageBox(NULL, "m_pButtonTexが読み込めませんでした", "Error", MB_OK);
	}

	// イージングクラスの確保
	m_pEasing = new Easing();
	m_pPopUpEase = new Easing();

	// アニメーションクラスの確保
	m_pAnim = new CAnim();
}

//==============================================================
//　関数名：World1_UI::~World1_UI()
//	引数１：なし
//	戻り値：なし
//
//	概　要：World1_UIクラスのデストラクタ
//==============================================================
World1_UI::~World1_UI()
{
	// テクスチャの開放
	if (m_pTexture)
	{
		for (int i = 0; i < W1_MAX_UI_TEX; i++)
		{
			delete m_pTexture[i];
			m_pTexture[i] = nullptr;
		}
	}

	if (m_pButtonTex)
	{
		delete m_pButtonTex;
		m_pButtonTex = nullptr;
	}

	// イージングクラスの開放
	if (m_pPopUpEase)
	{
		delete m_pPopUpEase;
		m_pPopUpEase = nullptr;
	}

	if (m_pEasing)
	{
		delete m_pEasing;
		m_pEasing = nullptr;
	}

	// アニメーションクラスの開放
	if (m_pAnim)
	{
		delete m_pAnim;
		m_pAnim = nullptr;
	}
}

void World1_UI::In_Other()
{
	m_StageSelectPos = m_pEasing->MoveEaseInOutBack(-350.0f, 225.0f, 0.01f, true);

	m_StageNamePos = m_pEasing->MoveEaseInOutBack(-300.0f, 150.0f, 0.01f, true);
}

void World1_UI::Out_StageName()
{
	m_StageNamePos = m_pEasing->MoveEaseOutBack(-300.0f, 150.0f, 0.02f, false);
}

//==============================================================
//　関数名：World1_UI::Draw_clear()
//	引数１：float PosX(描画位置ヨコ)
//	戻り値：float PosY(描画位置タテ)
//
//	概　要：ステージセレクトのクリアのUIの描画
//==============================================================
void World1_UI::Draw_clear(float PosX, float PosY)
{
	// クリア
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(PosX, PosY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(200.0f, 200.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();
}

//==============================================================
//　関数名：World1_UI::Draw_NextStageCursor()
//	引数１：float PosX(描画位置ヨコ)
//	戻り値：float PosY(描画位置タテ)
//
//	概　要：次のステージを示すUIの描画
//==============================================================
void World1_UI::Draw_NextCursor(int SelectStage, bool EX)
{
	DirectX::XMFLOAT4X4 mat[3];
	DirectX::XMMATRIX world;
	DirectX::XMMATRIX Mr;

	// ワールド行列の計量
	switch (SelectStage)
	{
	case STAGE_1_01:
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[0], 125.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();

		if (EX)
		{
			world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[9], 125.0f, 0.0f);
			Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(180.0f));
			world = Mr * world;
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::UIDraw();
		}
		break;

	case STAGE_1_02:
		// 上
		world = DirectX::XMMatrixTranslation(975.0f, m_PlayerCursorPos[1], 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_1_03:
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[4], 370.0f, 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(180.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_1_04:
		world = DirectX::XMMatrixTranslation(400.0f, m_PlayerCursorPos[5], 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_1_05:
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[8], 600.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;
	default:
		break;
	}
}

//==============================================================
//　関数名：World1_UI::Draw_Other()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトのステージ名などのUIの描画
//==============================================================
void World1_UI::Draw_Other()
{
	//---- ゲーム内UI ----
	// ステージセレクト（左上のやつ）
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_StageSelectPos, 680.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(670.0f, 670.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[0]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// ステージ名
	world = DirectX::XMMatrixTranslation(m_StageNamePos, 590.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[1]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// 戻るボタン
	world = DirectX::XMMatrixTranslation(1160.0f, 660.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(250.0f, 250.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();
}

void World1_UI::ResetEase()
{
	m_pPopUpEase->ResetChangePowPlay();
}

bool World1_UI::GetIsPlay()
{
	return m_pPopUpEase->GetIsPlay();
}

//==============================================================
//　関数名：World1_UI::Move_PlayerCursor1()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－１のUIのアニメーション処理
//==============================================================
void World1_UI::Move_PlayerCursor1()
{
	m_PlayerCursorPos[0] = m_pAnim->Animation_Move(590.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[9] = m_pAnim->Animation_Move(430.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f,300.0f,0.04f,true);
}

//==============================================================
//　関数名：World1_UI::Move_PlayerCursor2()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－２のUIのアニメーション処理
//==============================================================
void World1_UI::Move_PlayerCursor2()
{
	m_PlayerCursorPos[1] = m_pAnim->Animation_Move(325.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[2] = m_pAnim->Animation_Move(175.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//　関数名：World1_UI::Move_PlayerCursor3()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－３のUIのアニメーション処理
//==============================================================
void World1_UI::Move_PlayerCursor3()
{
	m_PlayerCursorPos[3] = m_pAnim->Animation_Move(760.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[4] = m_pAnim->Animation_Move(615.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//　関数名：World1_UI::Move_PlayerCursor4()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－４のUIのアニメーション処理
//==============================================================
void World1_UI::Move_PlayerCursor4()
{
	m_PlayerCursorPos[5] = m_pAnim->Animation_Move(565.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[6] = m_pAnim->Animation_Move(425.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//　関数名：World1_UI::Move_PlayerCursor5()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－５のUIのアニメーション処理
//==============================================================
void World1_UI::Move_PlayerCursor5()
{
	m_PlayerCursorPos[7] = m_pAnim->Animation_Move(750.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[8] = m_pAnim->Animation_Move(910.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//　関数名：World1_UI::Draw_Stage1()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－１のUIの描画
//==============================================================
void World1_UI::Draw_Stage1()
{
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(710.0f, 250.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_pPopUpSize, m_pPopUpSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[3]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	if (!m_pPopUpEase->GetIsPlay())
	{
		// Aボタン
		world = DirectX::XMMatrixTranslation(825.0f, 192.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();
	}
}

//==============================================================
//　関数名：World1_UI::Draw_Stage2()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－２のUIの描画
//==============================================================
void World1_UI::Draw_Stage2()
{
	// ステージセレクト（左上のやつ）
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(780.0f, 125.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_pPopUpSize, m_pPopUpSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[4]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// Aボタン
	world = DirectX::XMMatrixTranslation(900.0f, 65.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// 下
	world = DirectX::XMMatrixTranslation(975.0f, m_PlayerCursorPos[2], 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-90.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();
}

//==============================================================
//　関数名：World1_UI::Draw_Stage3()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－３のUIの描画
//==============================================================
void World1_UI::Draw_Stage3()
{
	// ステージセレクト（左上のやつ）
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(690.0f, 510.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_pPopUpSize, m_pPopUpSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[5]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// Aボタン
	world = DirectX::XMMatrixTranslation(805.0f, 452.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	//---- プレイヤー周りに出るカーソル
	// 右
	world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[3], 370.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();
}

//==============================================================
//　関数名：World1_UI::Draw_Stage4()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－４のUIの描画
//==============================================================
void World1_UI::Draw_Stage4()
{
	// ステージセレクト（左上のやつ）
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(220.0f, 440.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_pPopUpSize, m_pPopUpSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[6]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// Aボタン
	world = DirectX::XMMatrixTranslation(335.0f, 382.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// 下
	world = DirectX::XMMatrixTranslation(400.0f, m_PlayerCursorPos[6], 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-90.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();
}

//==============================================================
//　関数名：World1_UI::Draw_Stage5()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトの１－５のUIの描画
//==============================================================
void World1_UI::Draw_Stage5()
{
	// ステージセレクト（左上のやつ）
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(820.0f, 460.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_pPopUpSize, m_pPopUpSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[7]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// Aボタン
	world = DirectX::XMMatrixTranslation(935.0f, 402.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// プレイヤーの左側に出るカーソル
	world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[7], 600.0f, 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(180.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();
}
