#include "WorldEX_UI.h"

//==============================================================
//　関数名：WorldEX_UI::WorldEX_UI()
//	引数１：なし
//	戻り値：なし
//
//	概　要：WorldEX_UIクラスのコンストラクタ	
//==============================================================
WorldEX_UI::WorldEX_UI()
	: m_StageNamePos(-300.0f),
	m_StageSelectPos(-350.0f),
	m_PlayerCursorPos{ EX_MOVECURSOR_STAGE1_1,
					   EX_MOVECURSOR_STAGE1_2,
					   EX_MOVECURSOR_STAGE2_1,
					   EX_MOVECURSOR_STAGE2_2,
					   EX_MOVECURSOR_STAGE3_1,
					   EX_MOVECURSOR_STAGE3_2,
					   EX_MOVECURSOR_STAGE4_1,
					   EX_MOVECURSOR_STAGE4_2,
					   EX_MOVECURSOR_STAGE5_1},
	m_ButtonSize(75.0f),
	m_fPopUpSize(0.0f)
{
	//---- テクスチャクW5_MOVECURSOR_STAGE10  ラスの確保 ----
	for (int i = 0; i < EX_MAX_UI_TEX; i++)
	{
		m_pTexture[i] = new Texture();
	}

	for (int i = 0; i < EX_STAGE_TEX; i++)
	{
		m_pStageTex[i] = new Texture();
	}

	//---- テクスチャの読み込み ----
	// ステージセレクト
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Select/UI_StageSelect_StageSelect_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_StageSelect_001.pngが読み込めませんでした", "Error", MB_OK);
	}
	// すぽいむのおしろ
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Select/UI_StageSelect_WExname_001.png")))
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
	// EX-1
	if (FAILED(m_pStageTex[0]->Create("Assets/Texture/UI/Select/StageEX/EX-1.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_1).pngが読み込めませんでした", "Error", MB_OK);
	}
	// EX-2
	if (FAILED(m_pStageTex[1]->Create("Assets/Texture/UI/Select/StageEX/EX-2.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_2).pngが読み込めませんでした", "Error", MB_OK);
	}
	// EX-3
	if (FAILED(m_pStageTex[2]->Create("Assets/Texture/UI/Select/StageEX/EX-3.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_3).pngが読み込めませんでした", "Error", MB_OK);
	}
	// EX-4
	if (FAILED(m_pStageTex[3]->Create("Assets/Texture/UI/Select/StageEX/EX-4.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_4).pngが読み込めませんでした", "Error", MB_OK);
	}
	// EX-5
	if (FAILED(m_pStageTex[4]->Create("Assets/Texture/UI/Select/StageEX/EX-5.png")))
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
//　関数名：WorldEX_UI::~WorldEX_UI()
//	引数１：なし
//	戻り値：なし
//
//	概　要：WorldEX_UIクラスのデストラクタ
//==============================================================
WorldEX_UI::~WorldEX_UI()
{
	// テクスチャの開放
	for (int i = 0; i < EX_MAX_UI_TEX; i++)
	{
		if (m_pTexture[i])
		{
			delete m_pTexture[i];
			m_pTexture[i] = nullptr;
		}
	}

	for (int i = 0; i < EX_STAGE_TEX; i++)
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

void WorldEX_UI::In_Other()
{
	m_StageSelectPos = m_pEasing->MoveEaseInOutBack(-350.0f, 225.0f, 0.01f, true);

	m_StageNamePos = m_pEasing->MoveEaseInOutBack(-300.0f, 150.0f, 0.01f, true);
}

void WorldEX_UI::Out_StageName()
{
	m_StageNamePos = m_pEasing->MoveEaseOutBack(-300.0f, 150.0f, 0.02f, false);
}

void WorldEX_UI::ResetEase()
{
	m_pPopUpEase->ResetChangePowPlay();
}

//==============================================================
//　関数名：WorldEX_UI::Draw_clear()
//	引数１：float PosX(描画位置ヨコ)
//	戻り値：float PosY(描画位置タテ)
//
//	概　要：ステージセレクトのクリアのUIの描画
//==============================================================
void WorldEX_UI::Draw_clear(float PosX, float PosY)
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
//　関数名：WorldEX_UI::Draw_NextStageCursor()
//	引数１：float PosX(描画位置ヨコ)
//	戻り値：float PosY(描画位置タテ)
//
//	概　要：次のステージを示すUIの描画
//==============================================================
void WorldEX_UI::Draw_NextCursor(int SelectStage)
{
	DirectX::XMFLOAT4X4 mat[3];
	DirectX::XMMATRIX world;
	DirectX::XMMATRIX Mr;

	// ワールド行列の計量
	switch (SelectStage)
	{
	case STAGE_EX_01:
		world = DirectX::XMMatrixTranslation(320.0f, m_PlayerCursorPos[1], 0.0f);
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

	case STAGE_EX_02:
		// 下
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[3], 595.0f, 0.0f);
		Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(0.0f));
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

	case STAGE_EX_03:
		// 下
		world = DirectX::XMMatrixTranslation(620.0f, m_PlayerCursorPos[5], 0.0f);
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

	case STAGE_EX_04:
		// 左
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[7], 140.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_EX_05:
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
	default:
		break;
	}
}

//==============================================================
//　関数名：WorldEX_UI::Draw_Other()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ステージセレクトのステージ名などのUIの描画
//==============================================================
void WorldEX_UI::Draw_Other()
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

void WorldEX_UI::Move_PlayerCursor(int SelectStage)
{
	switch (SelectStage)
	{
	case STAGE_EX_01:
		m_PlayerCursorPos[0] = m_pAnim->Animation_Move(EX_MOVECURSOR_STAGE1_1, 120.0f, 5.0f);
		m_PlayerCursorPos[1] = m_pAnim->Animation_Move(EX_MOVECURSOR_STAGE1_2, 120.0f, -5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_EX_02:
		m_PlayerCursorPos[2] = m_pAnim->Animation_Move(EX_MOVECURSOR_STAGE2_1, 120.0f, 5.0f);
		m_PlayerCursorPos[3] = m_pAnim->Animation_Move(EX_MOVECURSOR_STAGE2_2, 120.0f, -5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_EX_03:
		m_PlayerCursorPos[4] = m_pAnim->Animation_Move(EX_MOVECURSOR_STAGE3_1, 120.0f, -5.0f);
		m_PlayerCursorPos[5] = m_pAnim->Animation_Move(EX_MOVECURSOR_STAGE3_2, 120.0f, -5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_EX_04:
		m_PlayerCursorPos[6] = m_pAnim->Animation_Move(EX_MOVECURSOR_STAGE4_1, 120.0f, 5.0f);
		m_PlayerCursorPos[7] = m_pAnim->Animation_Move(EX_MOVECURSOR_STAGE4_2, 120.0f, 5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	case STAGE_EX_05:
		m_PlayerCursorPos[3] = m_pAnim->Animation_Move(EX_MOVECURSOR_STAGE5_1, 60.0f, 5.0f);

		m_fPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
		break;
	default:
		break;
	}

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);
}

void WorldEX_UI::Draw_Stage(int SelectStage)
{
	if (SelectStage == STAGE_EX_01)
	{
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(EX_STAGE_01_POSX, EX_STAGE_01_POSY, 0.0f);
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
		world = DirectX::XMMatrixTranslation(EX_STAGE_01_POSX + 120.0f, EX_STAGE_01_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// カーソル
		world = DirectX::XMMatrixTranslation(320.0f, m_PlayerCursorPos[0], 0.0f);
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

	if (SelectStage == STAGE_EX_02)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(EX_STAGE_02_POSX, EX_STAGE_02_POSY, 0.0f);
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
		world = DirectX::XMMatrixTranslation(EX_STAGE_02_POSX + 120.0f, EX_STAGE_02_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		//---- プレイヤー周りに出るカーソル
		world = DirectX::XMMatrixTranslation(340.0f, m_PlayerCursorPos[2], 0.0f);
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

	if (SelectStage == STAGE_EX_03)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(EX_STAGE_03_POSX, EX_STAGE_03_POSY, 0.0f);
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
		world = DirectX::XMMatrixTranslation(EX_STAGE_03_POSX + 120.0f, EX_STAGE_03_POSY - 60.0f, 0.0f);
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
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[4],595.0f, 0.0f);
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

	if (SelectStage == STAGE_EX_04)
	{
		// ステージセレクト（左上のやつ）
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(EX_STAGE_04_POSX, EX_STAGE_04_POSY, 0.0f);
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
		world = DirectX::XMMatrixTranslation(EX_STAGE_04_POSX + 120.0f, EX_STAGE_04_POSY - 60.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pButtonTex);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		//---- プレイヤー周りに出るカーソル
		world = DirectX::XMMatrixTranslation(615.0f, m_PlayerCursorPos[6], 0.0f);
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

	if (SelectStage == STAGE_EX_05)
	{
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(EX_STAGE_05_POSX, EX_STAGE_05_POSY, 0.0f);
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
		world = DirectX::XMMatrixTranslation(EX_STAGE_05_POSX + 120.0f, EX_STAGE_05_POSY - 60.0f, 0.0f);
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
		world = DirectX::XMMatrixTranslation(915.0f, m_PlayerCursorPos[3], 0.0f);
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