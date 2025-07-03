#include "World5_UI.h"

//==============================================================
//　関数名：World5_UI::World5_UI()
//	引数１：なし
//	戻り値：なし
//
//	概　要：World5_UIクラスのコンストラクタ	
//==============================================================
World5_UI::World5_UI()
	: m_StageNamePos(-300.0f),
	m_StageSelectPos(-350.0f),
	m_PlayerCursorPos{ W5_MOVECURSOR_STAGE1_1,
					   W5_MOVECURSOR_STAGE1_2,
					   W5_MOVECURSOR_STAGE2_1,
					   W5_MOVECURSOR_STAGE2_2,
					   W5_MOVECURSOR_STAGE3_1,
					   W5_MOVECURSOR_STAGE3_2,
					   W5_MOVECURSOR_STAGE4_1,
					   W5_MOVECURSOR_STAGE4_2,
					   W5_MOVECURSOR_STAGE5_1,
					   W5_MOVECURSOR_STAGE5_2,
					   W5_MOVECURSOR_STAGE6_1,
					   W5_MOVECURSOR_STAGE6_2,
					   W5_MOVECURSOR_STAGE7_1,
					   W5_MOVECURSOR_STAGE7_2,
					   W5_MOVECURSOR_STAGE8_1,
					   W5_MOVECURSOR_STAGE8_2,
					   W5_MOVECURSOR_STAGE9_1,
					   W5_MOVECURSOR_STAGE9_2,
					   W5_MOVECURSOR_STAGE10  },
	m_ButtonSize(75.0f),
	m_fPopUpSize(0.0f)
{ 
	//---- テクスチャクW5_MOVECURSOR_STAGE10  ラスの確保 ----
	for (int i = 0; i < W5_MAX_UI_TEX; i++)
	{
		m_pTexture[i] = new Texture();
	}

	for (int i = 0; i < W5_STAGE_TEX; i++)
	{
		m_pStageTex[i] = new Texture();
	}

	//---- テクスチャの読み込み ----
	// ステージセレクト
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Select/UI_StageSelect_StageSelect_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_StageSelect_001.pngが読み込めませんでした", "Error", MB_OK);
	}
	// さいはてかざん
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Select/UI_StageSelect_S5name_001.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Stagename_001.pngが読み込めませんでした", "Error", MB_OK);
	}
	// 戻るボタン
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Select/UI_StageSelect_Back_003.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Back.pngが読み込めませんでした", "Error", MB_OK);
	}
	// クリア
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Select/UI_StageSelect_ClearIcon_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_ClearIcon_002.pngが読み込めませんでした", "Error", MB_OK);
	}
	// 次のステージを示すカーソル
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Select/UI_Title_Select.png")))
	{
		MessageBox(NULL, "UI_Title_Select.pngが読み込めませんでした", "Error", MB_OK);
	}

	// ステージ
	// 5-1
	if (FAILED(m_pStageTex[0]->Create("Assets/Texture/UI/Select/Stage05/5-1.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_1).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 5-2
	if (FAILED(m_pStageTex[1]->Create("Assets/Texture/UI/Select/Stage05/5-2.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_2).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 5-3
	if (FAILED(m_pStageTex[2]->Create("Assets/Texture/UI/Select/Stage05/5-3.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_3).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 5-4
	if (FAILED(m_pStageTex[3]->Create("Assets/Texture/UI/Select/Stage05/5-4.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_4).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 5-5
	if (FAILED(m_pStageTex[4]->Create("Assets/Texture/UI/Select/Stage05/5-5.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 5-6
	if (FAILED(m_pStageTex[5]->Create("Assets/Texture/UI/Select/Stage05/5-6.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 5-7
	if (FAILED(m_pStageTex[6]->Create("Assets/Texture/UI/Select/Stage05/5-7.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 5-8
	if (FAILED(m_pStageTex[7]->Create("Assets/Texture/UI/Select/Stage05/5-8.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 5-9
	if (FAILED(m_pStageTex[8]->Create("Assets/Texture/UI/Select/Stage05/5-9.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).pngが読み込めませんでした", "Error", MB_OK);
	}
	// 5-10
	if (FAILED(m_pStageTex[9]->Create("Assets/Texture/UI/Select/Stage05/5-10.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).pngが読み込めませんでした", "Error", MB_OK);
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
//　関数名：World5_UI::~World5_UI()
//	引数１：なし
//	戻り値：なし
//
//	概　要：World5_UIクラスのデストラクタ
//==============================================================
World5_UI::~World5_UI()
{
	// テクスチャの開放
	for (int i = 0; i < W5_MAX_UI_TEX; i++)
	{
		if (m_pTexture[i])
		{
			delete m_pTexture[i];
			m_pTexture[i] = nullptr;
		}
	}

	for (int i = 0; i < W5_STAGE_TEX; i++)
	{
		if (m_pStageTex[i])
		{
			delete m_pStageTex[i];
			m_pStageTex[i] = nullptr;
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

void World5_UI::In_Other()
{
	m_StageSelectPos = m_pEasing->MoveEaseInOutBack(-350.0f, 225.0f, 0.01f, true);

	m_StageNamePos = m_pEasing->MoveEaseInOutBack(-300.0f, 150.0f, 0.01f, true);
}

void World5_UI::Out_StageName()
{
	m_StageNamePos = m_pEasing->MoveEaseOutBack(-300.0f, 150.0f, 0.02f, false);
}

void World5_UI::ResetEase()
{
	m_pPopUpEase->ResetChangePowPlay();
}

//==============================================================
//　関数名：World5_UI::Draw_clear()
//	引数１：float PosX(描画位置ヨコ)
//	戻り値：float PosY(描画位置タテ)
//
//	概　要：ステージセレクトのクリアのUIの描画
//==============================================================
void World5_UI::Draw_clear(float PosX, float PosY)
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
	Sprite::SetTexture(m_pTexture[3]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();
}

//==============================================================
//　関数名：World5_UI::Draw_NextStageCursor()
//	引数１：float PosX(描画位置ヨコ)
//	戻り値：float PosY(描画位置タテ)
//
//	概　要：次のステージを示すUIの描画
//==============================================================
void World5_UI::Draw_NextCursor(int SelectStage)
{
	DirectX::XMFLOAT4X4 mat[3];
	DirectX::XMMATRIX world;
	DirectX::XMMATRIX Mr;

	// ワールド行列の計量
	switch (SelectStage)
	{
	case STAGE_5_01:
		world = DirectX::XMMatrixTranslation(195.0f, m_PlayerCursorPos[1], 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_5_02:
		// 下
		world = DirectX::XMMatrixTranslation(205.0f, m_PlayerCursorPos[3], 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_5_03:
		// 下
		world = DirectX::XMMatrixTranslation(215.0f, m_PlayerCursorPos[5], 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_5_04:
		// 左
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[7], 550.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_5_05:
		// 上
		world = DirectX::XMMatrixTranslation(1090.0f, m_PlayerCursorPos[4], 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_5_06:
		world = DirectX::XMMatrixTranslation(1100.0f, m_PlayerCursorPos[11], 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_5_07:
		// 下
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[13], 55.0f, 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(180.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_5_08:
		world = DirectX::XMMatrixTranslation(558.0f, m_PlayerCursorPos[15], 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_5_09:
		world = DirectX::XMMatrixTranslation(390.0f, m_PlayerCursorPos[17], 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;
	default:
		break;
	}
}

//==============================================================
//　関数名：World5_UI::Draw_Other()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトのステージ名などのUIの描画
//==============================================================
void World5_UI::Draw_Other()
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

void World5_UI::Move_PlayerCursor(int SelectStage)
{
	switch (SelectStage)
	{
	case STAGE_5_01:
		m_PlayerCursorPos[0] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE1_1, 120.0f, 5.0f);
		m_PlayerCursorPos[1] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE1_2, 120.0f, -5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_5_02:
		m_PlayerCursorPos[2] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE2_1, 120.0f, 5.0f);
		m_PlayerCursorPos[3] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE2_2, 120.0f, -5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_5_03:
		m_PlayerCursorPos[4] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE3_1, 120.0f, 5.0f);
		m_PlayerCursorPos[5] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE3_2, 120.0f, -5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_5_04:
		m_PlayerCursorPos[6] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE4_1, 120.0f, 5.0f);
		m_PlayerCursorPos[7] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE4_2, 120.0f, -5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_5_05:
		m_PlayerCursorPos[3] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE5_1, 120.0f, 5.0f);
		m_PlayerCursorPos[4] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE5_2, 120.0f, -5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_5_06:
		m_PlayerCursorPos[10] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE6_1, 120.0f, -5.0f);
		m_PlayerCursorPos[11] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE6_2, 120.0f, 5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_5_07:
		m_PlayerCursorPos[12] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE7_1, 120.0f, -5.0f);
		m_PlayerCursorPos[13] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE7_2, 120.0f, 5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_5_08:
		m_PlayerCursorPos[14] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE8_1, 120.0f, 5.0f);
		m_PlayerCursorPos[15] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE8_2, 120.0f, 5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_5_09:
		m_PlayerCursorPos[16] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE9_1, 120.0f, -5.0f);
		m_PlayerCursorPos[17] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE9_2, 120.0f, 5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_5_10:
		m_PlayerCursorPos[18] = m_pAnim->Animation_Move(W5_MOVECURSOR_STAGE10, 60.0f, -5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	default:
		break;
	}

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);
}

void World5_UI::Draw_Stage(int SelectStage)
{
	if (SelectStage == STAGE_5_01)
	{
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_01_POSX, W5_STAGE_01_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[0]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_01_POSX + 120.0f, W5_STAGE_01_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// カーソル
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[0], 69.0f, 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(180.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (SelectStage == STAGE_5_02)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_02_POSX, W5_STAGE_02_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[1]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_02_POSX + 120.0f, W5_STAGE_02_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		//---- プレイヤー周りに出るカーソル
		// 左
		world = DirectX::XMMatrixTranslation(205.0f, m_PlayerCursorPos[2], 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (SelectStage == STAGE_5_03)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_03_POSX, W5_STAGE_03_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_03_POSX + 120.0f, W5_STAGE_03_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		//---- プレイヤー周りに出るカーソル
		// 上
		world = DirectX::XMMatrixTranslation(215.0f, m_PlayerCursorPos[4], 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (SelectStage == STAGE_5_04)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_04_POSX, W5_STAGE_04_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[3]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_04_POSX + 120.0f, W5_STAGE_04_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		//---- プレイヤー周りに出るカーソル
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[6], 550.0f, 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(180.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (SelectStage == STAGE_5_05)
	{
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_05_POSX, W5_STAGE_05_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_05_POSX + 120.0f, W5_STAGE_05_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		//---- プレイヤー周りに出るカーソル
		// 下
		world = DirectX::XMMatrixTranslation(1075.0f, m_PlayerCursorPos[3], 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (SelectStage == STAGE_5_06)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_06_POSX, W5_STAGE_06_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[5]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_06_POSX + 120.0f, W5_STAGE_06_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// プレイヤーの左側に出るカーソル
		// 下
		world = DirectX::XMMatrixTranslation(1090.0f, m_PlayerCursorPos[10], 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (SelectStage == STAGE_5_07)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_07_POSX, W5_STAGE_07_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[6]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_07_POSX + 120.0f, W5_STAGE_07_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// 下
		world = DirectX::XMMatrixTranslation(1105.0f, m_PlayerCursorPos[12], 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (SelectStage == STAGE_5_08)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_08_POSX, W5_STAGE_08_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[7]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_08_POSX + 120.0f, W5_STAGE_08_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// 下
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[14], 55.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (SelectStage == STAGE_5_09)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_09_POSX, W5_STAGE_09_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[8]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_09_POSX + 120.0f, W5_STAGE_09_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// 下
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[16], 470.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (SelectStage == STAGE_5_10)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(W5_STAGE_10_POSX, W5_STAGE_10_POSY, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_fPopUpSize, m_fPopUpSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pStageTex[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Aボタン
		world = DirectX::XMMatrixTranslation(W5_STAGE_10_POSX + 120.0f, W5_STAGE_10_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// 下
		world = DirectX::XMMatrixTranslation(635.0f, m_PlayerCursorPos[18], 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-90.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}
}