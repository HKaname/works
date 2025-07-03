//==============================================================
//
//  ファイル名：UIdirection.cpp
//
//	概要：UI演出の処理を行う
//==============================================================

// インクルード部
#include "UIdirection.h"

//==============================================================
//　関数名：CDirection::CDirection()
//	引数１：なし
//	戻り値：なし
//
//	概　要：CDirectionクラスのコンストラクタ	
//==============================================================
CDirection::CDirection()
	: m_Di_UIPosX{ SCREEN_WIDTH / 2, 1450.0f , 450.0f },
	  m_alpha{ 0.0f, 1.0f , 1.0f },
	  m_bGoalDirection(true),
	  m_bStartDirection(false),
	  m_bEndFade(false),
	  m_DirextionSize(0.0f),
	  m_Directionframe(0),
	  m_LoadAnimframe(0),
	  m_StartUICnt(0),
	  m_bGoalSound(true),
	  m_nGoalSelectKind(E_NEXT),
	  m_angle(0.0f),
	  m_GoalTexangle(0.0f),
	  m_fGoalTexPos(900.0f),
	  m_ftime(0.0f),
	  m_fGoalButton_Return(450.0f),
	  m_fGoalButton_Next(450.0f)
{
	//---- テクスチャクラスの確保 ----
	for (int i = 0; i < MAX_DIRECTION_TEX; i++)
	{
		m_pTexture[i] = new Texture();
	}

	//---- テクスチャの読み込み ----
	// スタート演出用
	// 暗くするための黒塗り画像
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Game/BlackGround.png")))
	{
		MessageBox(NULL, "BlackGroundが読み込めませんでした", "Error", MB_OK);
	}
	// スタート！って書いてあるやつ
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Game/Animation/UI_start_text.PNG")))
	{
		MessageBox(NULL, "UI_start_text.PNGが読み込めませんでした", "Error", MB_OK);
	}
	// ヒメが息を吸い込んでる画像
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Game/Animation/UI_start_whistle01.PNG")))
	{
		MessageBox(NULL, "UI_start_whistle01が読み込めませんでした", "Error", MB_OK);
	}
	// ヒメが笛を吹いてる画像
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Game/Animation/UI_start_whistle02.PNG")))
	{
		MessageBox(NULL, "UI_start_whistle02が読み込めませんでした", "Error", MB_OK);
	}

	// ゴール演出用
	// クリアした時に表示する画像（青のみ）
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Game/Animation/UI_clear_blue.png")))
	{
		MessageBox(NULL, "UI_clearが読み込めませんでした", "Error", MB_OK);
	}
	// クリアした時に表示する画像（青赤）
	if (FAILED(m_pTexture[5]->Create("Assets/Texture/UI/Game/Animation/UI_clear_blue_pink.png")))
	{
		MessageBox(NULL, "UI_clearが読み込めませんでした", "Error", MB_OK);
	}
	// 次のステージへ（選択時）
	if (FAILED(m_pTexture[6]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_NextStage_A_001.png")))
	{
		MessageBox(NULL, "UI_Pause_NextStage_A_001が読み込めませんでした", "Error", MB_OK);
	}
	// セレクトに戻る（選択時）
	if (FAILED(m_pTexture[7]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_BackSelect_A_001.png")))
	{
		MessageBox(NULL, "UI_Pause_BackSelect_A_001が読み込めませんでした", "Error", MB_OK);
	}
	// 次のステージへ（非選択時）
	if (FAILED(m_pTexture[8]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_NextStage(Black)_001.png")))
	{
		MessageBox(NULL, "UI_Pause_NextStage(Black)_001が読み込めませんでした", "Error", MB_OK);
	}
	// セレクトに戻る（非選択時）
	if (FAILED(m_pTexture[9]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_BackSelect(Black)_001.png")))
	{
		MessageBox(NULL, "UI_Pause_BackSelect(Black)_001が読み込めませんでした", "Error", MB_OK);
	}
	// Aボタン
	if (FAILED(m_pTexture[10]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_BackSelect_A_001.png")))
	{
		MessageBox(NULL, "UI_Pause_BackSelect_A_001.pngが読み込めませんでした", "Error", MB_OK);
	}

	// ゴール光
	m_pGoalShineTex = new Texture();
	if (FAILED(m_pGoalShineTex->Create("Assets/Texture/UI/Game/Animation/UI_clear_shine.png")))
	{
		MessageBox(NULL, "m_pGoalShineTexが読み込めませんでした", "Error", MB_OK);
	}

	m_pGoalTextTex = new Texture();
	if (FAILED(m_pGoalTextTex->Create("Assets/Texture/UI/Game/Animation/UI_clear_text.png")))
	{
		MessageBox(NULL, "m_pGoalTextTexが読み込めませんでした", "Error", MB_OK);
	}

	m_pGoalEfectPS = new PixelShader();
	if (FAILED(m_pGoalEfectPS->Load("Assets/Shader/GloalEfect.cso")))
	{
		MessageBox(NULL, "m_pGoalTextTexが読み込めませんでした", "Error", MB_OK);
	}

	//サウンドデータの読み込み
	m_pSEDecision = LoadSound("Assets/SE/supotto_UI_kettei_V1.wav");//決定SE
	m_pSEStart = LoadSound("Assets/SE/supoimu_Start_V6.wav");		//スタート時のジングル
	m_pSEGoal = LoadSound("Assets/SE/supoimu_goal_re-take.wav");	//ゴール時のジングル

	// イージングの作成
	m_pEasing = new Easing();
	m_pTextEase = new Easing();

	// アニメーションの作成
	m_pAnim = new CAnim();
}

//==============================================================
//　関数名：CDirection::~CDirection()
//	引数１：なし
//	戻り値：なし
//
//	概　要：CDirectionクラスのデストラクタ	
//==============================================================
CDirection::~CDirection()
{
	// テクスチャの開放
	if (m_pTexture)
	{
		for (int i = 0; i < MAX_DIRECTION_TEX; i++)
		{
			delete m_pTexture[i];
			m_pTexture[i] = nullptr;
		}
	}

	if (m_pGoalShineTex)
	{
		delete m_pGoalShineTex;
		m_pGoalShineTex = nullptr;
	}
	if (m_pGoalEfectPS)
	{
		delete m_pGoalEfectPS;
		m_pGoalEfectPS = nullptr;
	}
	// イージングの開放
	delete m_pEasing; m_pEasing = nullptr;
	delete m_pTextEase; m_pTextEase = nullptr;

	// アニメーションの開放
	delete m_pAnim; m_pAnim = nullptr;
}

//==============================================================
//　関数名：CDirection::StartDirection_Ready()
//	引数１：なし
//	戻り値：なし
//
//	概　要：スタートUIの表示（ヒメ笛吹く前のやつ）
//===============================================================
void CDirection::StartDirection_Ready()
{
	// ヒメ（息吸い込んでる方）
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_Di_UIPosX[1], SCREEN_HEIGHT / 2 ,0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]); 
	Sprite::SetSize(DirectX::XMFLOAT2(390.0f, 390.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_alpha[1]));
	Sprite::SetTexture(m_pTexture[2]);
	Sprite::Draw();

	// 黒背景
	world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0], SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_HEIGHT));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_alpha[0]));
	Sprite::SetTexture(m_pTexture[0]);
	Sprite::Draw();
}

//==============================================================
//　関数名：CDirection::StartDirection_Start()
//	引数１：なし
//	戻り値：なし
//
//	概　要：スタートUIの表示（ヒメ笛吹いてるほう）
//===============================================================
void CDirection::StartDirection_Start()
{
	//ヒメ（笛吹いてるやつ）
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_Di_UIPosX[1], SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMMATRIX mr = DirectX::XMMatrixRotationZ(m_angle);
	world = mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]); 
	Sprite::SetSize(DirectX::XMFLOAT2(390.0f, 390.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_alpha[1]));
	Sprite::SetTexture(m_pTexture[3]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// 黒背景
	world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0], SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_HEIGHT));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_alpha[0]));
	Sprite::SetTexture(m_pTexture[0]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();
}

//==============================================================
//　関数名：CDirection::StartDirection_Alert()
//	引数１：なし
//	戻り値：なし
//
//	概　要：スタートUIの表示（スタート！の部分、後でここだけ消すために関数を分けてある）
//===============================================================
void CDirection::StartDirection_Alert()
{
	// スタート！ってかいてあるやつ
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_Di_UIPosX[2], SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(500.0f, 500.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[1]);
	Sprite::UIDraw();
}

//==============================================================
//　関数名：CDirection::DrawLoadAnim()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ロード中のNowLoadingの描画
//===============================================================
void CDirection::DrawLoadAnim()
{
	// スタート！ってかいてあるやつ
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(995.0f, 60.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(550.0f, 550.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[5]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f / (float)LOAD_ANIM_SPLIT_X, 1.0f / (float)LOAD_ANIM_SPLIT_Y));
	Sprite::SetUVPos(m_UvPos);
	Sprite::Draw();
}

//==============================================================
//　関数名：CDirection::GoalDirection()
//	引数１：なし
//	戻り値：なし
//
//	概　要：ゴールUIの表示
//===============================================================
void CDirection::GoalDirection(int Stage)
{
	Texture* pGoalTex = nullptr;

	if (Stage < STAGE_3_01 || Stage == STAGE_4_01 || Stage == STAGE_4_02 || Stage == STAGE_5_01 || Stage == STAGE_EX_04)
	{
		pGoalTex = m_pTexture[4];
	}
	else if (Stage >= STAGE_3_01 || Stage != STAGE_4_01 || Stage != STAGE_4_02 || Stage != STAGE_5_01 || Stage != STAGE_EX_04)
	{
		pGoalTex = m_pTexture[5];
	}
	
	// ゴールUI
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0], SCREEN_HEIGHT / 1.1f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::Settime(m_ftime);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 0.5f));
	Sprite::SetRotateSpeed(0.2f);
	Sprite::SetSize(DirectX::XMFLOAT2(m_DirextionSize*2.2f, m_DirextionSize*2.2f/2.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_alpha[2]));
	Sprite::SetTexture(m_pGoalShineTex);
	Sprite::SetPixelShader(m_pGoalEfectPS);
	SetBlendMode(OPACITY_BLEND_ALPHA);
	Sprite::GoalEfectDraw();
	SetBlendMode(BLEND_ALPHA);
	Sprite::SetPixelShader(nullptr);

	world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0], SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_DirextionSize, m_DirextionSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_alpha[2]));
	Sprite::SetTexture(pGoalTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0] + 200.0f, m_fGoalTexPos, 0.0f);
	DirectX::XMMATRIX TexMr = DirectX::XMMatrixRotationZ(-0.5f);
	world = TexMr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(300.0f, 300.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_alpha[2]));
	Sprite::SetTexture(m_pGoalTextTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	if (Stage < STAGE_1_05 ||
		Stage > STAGE_1_05 && Stage < STAGE_2_06 ||
		Stage > STAGE_2_06 && Stage < STAGE_3_07 ||
		Stage > STAGE_3_07 && Stage < STAGE_4_08 ||
		Stage > STAGE_4_08 && Stage < STAGE_5_10 ||
		Stage > STAGE_5_10 && Stage < STAGE_EX_05 && Stage > STAGE_EX_01)
	{
		if (m_Directionframe >= 300.0f)
		{
			if (m_nGoalSelectKind == E_NEXT)
			{	// 次のステージへ選択時
				// セレクトに戻る
				world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0] - 200.0f, SCREEN_HEIGHT / 2 - 265.0f, 0.0f);
				DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

				Sprite::SetWorld(mat[0]);
				Sprite::SetSize(DirectX::XMFLOAT2(m_fGoalButton_Return, m_fGoalButton_Return));
				Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
				Sprite::SetTexture(m_pTexture[9]);
				Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
				Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
				Sprite::Draw();

				// 次のステージへ
				world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0] + 200.0f, SCREEN_HEIGHT / 2 - 265.0f, 0.0f);
				DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

				Sprite::SetWorld(mat[0]);
				Sprite::SetSize(DirectX::XMFLOAT2(m_fGoalButton_Next, m_fGoalButton_Next));
				Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
				Sprite::SetTexture(m_pTexture[6]);
				Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
				Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
				Sprite::Draw();
			}
			else if (m_nGoalSelectKind == E_RETRUN_SELECT)
			{	// セレクトに戻る選択時
				// セレクトに戻る
				world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0] - 200.0f, SCREEN_HEIGHT / 2 - 265.0f, 0.0f);
				DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

				Sprite::SetWorld(mat[0]);
				Sprite::SetSize(DirectX::XMFLOAT2(m_fGoalButton_Return, m_fGoalButton_Return));
				Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
				Sprite::SetTexture(m_pTexture[7]);
				Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
				Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
				Sprite::Draw();

				// 次のステージへ
				world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0] + 200.0f, SCREEN_HEIGHT / 2 - 265.0f, 0.0f);
				DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

				Sprite::SetWorld(mat[0]);
				Sprite::SetSize(DirectX::XMFLOAT2(m_fGoalButton_Next, m_fGoalButton_Next));
				Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
				Sprite::SetTexture(m_pTexture[8]);
				Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
				Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
				Sprite::Draw();
			}
		}
	}

	if (Stage == STAGE_1_05 || Stage == STAGE_2_06 || Stage == STAGE_3_07 || Stage == STAGE_4_08 || Stage == STAGE_5_10 || Stage == STAGE_EX_05 || Stage == STAGE_EX_01)
	{
		if (m_Directionframe >= 300.0f)
		{
			// セレクトに戻る
			world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0], SCREEN_HEIGHT / 2 - 265.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_fGoalButton_Return, m_fGoalButton_Return));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[7]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::Draw();
		}
	}
}

//==============================================================
//　関数名：CDirection::MoveUI_In()
//	引数１：なし
//	戻り値：なし
//
//	概　要：スタートUIの移動処理(入ってくるとき)
//===============================================================
void CDirection::MoveUI_In()
{
	m_Di_UIPosX[1] = m_pEasing->MoveEaseOutCubic(1400.0f, 800.0f, 0.02f, true);
}

//==============================================================
//　関数名：CDirection::MoveUI_Out()
//	引数１：なし
//	戻り値：なし
//
//	概　要：スタートUIの移動処理(抜けてく時)
//===============================================================
void CDirection::MoveUI_Out()
{
	m_Di_UIPosX[1] = m_pEasing->MoveEaseOutQuart(-500.0f, 800.0f, 0.04f, false);
}

//==============================================================
//　関数名：CDirection::ChangeUISize()
//	引数１：ゲームが終了したか
//	戻り値：なし
//
//	概　要：ゴールUIの表示する処理
//===============================================================
void CDirection::ChangeUISize(bool bEndGame, int Stage)
{
/*	m_bGoalFlag = false;*///ゴール時フラグ
	m_Directionframe++;

	if (m_Directionframe < 230.0f)
		m_pEasing->ResetChangePowPlay();

	// 移動およびUIを濃くして表示していく
	if (m_Directionframe >= 230.0f)
	{
		m_DirextionSize = m_pEasing->MoveEaseOutBack(0.0f, 800.0f, 0.05f, true);

		if (m_bGoalSound == true) {//最初尾1回目のみ
			m_pSEGoalSpeaker = PlaySound(m_pSEGoal);//ゴールジングル再生
			m_bGoalSound = false;
		}
	}

	if (m_Directionframe > 250.0f && m_Directionframe < 320.0f)
		m_fGoalTexPos = m_pTextEase->MoveEaseOutBounce(900.0f, 490.0f, 0.0175f, true);

	if (m_Directionframe > 250.0f)
		m_GoalTexangle += 0.01f;
	
	if (Stage < STAGE_1_05 ||
		Stage > STAGE_1_05 && Stage < STAGE_2_06 ||
		Stage > STAGE_2_06 && Stage < STAGE_3_07 ||
		Stage > STAGE_3_07 && Stage < STAGE_4_08 ||
		Stage > STAGE_4_08 && Stage < STAGE_5_10 ||
		Stage > STAGE_5_10 && Stage < STAGE_EX_05 && Stage > STAGE_EX_01)
	{
		m_ftime++;

		// 「次のステージへ」へ動く
		if (IsKeyTrigger('D') || IsButtonTrigger(BUTTON_RIGHT) || IsButtonTrigger(STICK_RIGHT))
		{
			if (m_nGoalSelectKind > 0)
			{
				m_nGoalSelectKind--;
			}
		}

		// 「ステージセレクトに戻る」へ動く
		if (IsKeyTrigger('A') || IsButtonTrigger(BUTTON_LEFT) || IsButtonTrigger(STICK_LEFT))
		{
			if (m_nGoalSelectKind < 1)
			{
				m_nGoalSelectKind++;
			}
		}

		// 「次のステージへ」を選んだ時
		if (m_nGoalSelectKind == E_NEXT && bEndGame && IsKeyTrigger(VK_RETURN) ||
			m_nGoalSelectKind == E_NEXT && bEndGame && IsButtonTrigger(BUTTON_A))
		{
			if (m_bGoalDirection) {//最初の1回目のみ
				m_pSESpeaker = PlaySound(m_pSEDecision);//決定SE
			}

			if (m_alpha[2] >= 1.0f && !m_bGoalFlag)
			{
				m_bGoalFlag = true;//ゴール時フラグ
			}

			m_bGoalDirection = false; // UIを消す処理

			m_Directionframe = 0;
		}

		// 選択時アニメーション
		if (m_nGoalSelectKind == E_NEXT)
			m_fGoalButton_Next = m_pAnim->Animation_Scale(60.0f,20.0f,450.0f);

		// 「セレクトに戻る」を選んだ時
		if (m_nGoalSelectKind == E_RETRUN_SELECT && bEndGame && IsKeyTrigger(VK_RETURN) ||
			m_nGoalSelectKind == E_RETRUN_SELECT && IsButtonTrigger(BUTTON_A))
		{
			if (m_bGoalDirection) {//最初の1回目のみ
				m_pSESpeaker = PlaySound(m_pSEDecision);//決定SE
			}

			if (m_alpha[2] >= 1.0f && !m_bGoalFlag)
			{
				m_bGoalFlag = true;//ゴール時フラグ
			}

			m_bGoalDirection = false; // UIを消す処理

			m_Directionframe = 0;
		}

		// 選択時アニメーション
		if (m_nGoalSelectKind == E_RETRUN_SELECT)
			m_fGoalButton_Return = m_pAnim->Animation_Scale(60.0f, 20.0f, 450.0f);
	}

	// 各ワールド最終ステージの時の処理
	if (Stage == STAGE_1_05 || Stage == STAGE_2_06 || Stage == STAGE_3_07 || Stage == STAGE_4_08 || Stage == STAGE_5_10 || Stage == STAGE_EX_01 || Stage == STAGE_EX_05)
	{
		m_ftime++;

		m_nGoalSelectKind = E_RETRUN_SELECT;

		// 選択時アニメーション
		m_fGoalButton_Return = m_pAnim->Animation_Scale(60.0f, 20.0f, 450.0f);

		// 「セレクトに戻る」を選んだ時
		if (bEndGame && IsKeyTrigger(VK_RETURN) || bEndGame && IsButtonTrigger(BUTTON_A))
		{
			if (m_bGoalDirection) {//最初の1回目のみ
				m_pSESpeaker = PlaySound(m_pSEDecision);//決定SE
			}

			if (m_alpha[2] >= 1.0f && !m_bGoalFlag)
			{
				m_bGoalFlag = true;//ゴール時フラグ
			}

			m_bGoalDirection = false; // UIを消す処理
		}
	}
}

//==============================================================
//　関数名：CDirection::StartUIDirection()
//	引数１：なし
//	戻り値：なし
//
//	概　要：スタート時のUI演出
//===============================================================
void CDirection::StartUIDirection()
{
	m_StartUICnt++;

	if (m_StartUICnt < 45)
	{
		MoveUI_In();

		if (m_alpha[0] <= 0.6f)
		{
			m_alpha[0] += 0.2f;
		}
	}

	if (m_StartUICnt > 55 && m_StartUICnt < 105)
	{
		if (m_StartUICnt == 56) m_pSEStartSpeaker = PlaySound(m_pSEStart);//スタートジングル再生
		m_Di_UIPosX[1] = m_pAnim->Animation_Move(800.0f, 5.0f, 5.0f);
		m_angle = m_pAnim->Animation_Rotation(5.0f, 2.5f);
		m_bStartDirection = true;
	}

	if (m_StartUICnt > 105)
	{
		MoveUI_Out();

		if (m_alpha[0] >= 0.0f)
		{
			m_alpha[0] -= 0.015f;
		}
	}
}

//==============================================================
//　関数名：CDirection::GetPosX()
//	引数１：なし
//	戻り値：なし
//
//	概　要：m_Di_UIPosX[1]の座標を返す関数
//===============================================================
float CDirection::GetPosX()
{
	return m_Di_UIPosX[1];
}

//==============================================================
//　関数名：CDirection::GetbDirection()
//	引数１：なし
//	戻り値：なし
//
//	概　要：m_bGoalDirectionの状態を返す関数
//===============================================================
bool CDirection::GetbDirection()
{
	return m_bStartDirection;
}

//==============================================================
//　関数名：CDirection::GetEndFade()
//	引数１：なし
//	戻り値：なし
//
//	概　要：m_bEndFadeの状態を返す関数
//===============================================================
bool CDirection::GetEndFade()
{
	return m_bEndFade;
}

//==============================================================
//　関数名：CDirection::GetGoalFlag()
//	引数１：なし
//	戻り値：なし
//
//	概　要：GetGoalFlagの状態を返す関数
//===============================================================
bool CDirection::GetGoalFlag()
{
	return m_bGoalFlag;
}

//==============================================================
//　関数名：CDirection::GetStartCnt()
//	引数１：なし
//	戻り値：なし
//
//	概　要：StartUICntの状態を返す関数
//===============================================================
int CDirection::GetStartCnt()
{
	return m_StartUICnt;
}

//==============================================================
//　関数名：CDirection::GetGoalSelectKind()
//	引数１：なし
//	戻り値：なし
//
//	概　要：GoalSelectKindの状態を返す関数
//===============================================================
int CDirection::GetGoalSelectKind()
{
	return m_nGoalSelectKind;
}

//ゴール時のサウンドフラグを返す
bool CDirection::GetGoalSound()
{
	return m_bGoalSound;
}

//ゴール後に決定ボタンを押したか
bool CDirection::GetGoalDirection()
{
	return m_bGoalDirection;
}
