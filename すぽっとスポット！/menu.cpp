//==============================================================
//
//  ファイル名：Menu.cpp
//
//	概要：
//	メニューUIを表示及び移動、メニューの選択を行った時の処理を行う
//
//	更新履歴:
//	日付	時間	氏名		内容
//	10/29	21:44	酒井蒼平	更新履歴の追加
//			21:45	酒井蒼平	コメントを追加
//	11/05	21:05	幡手要		UI表示の元オブジェクトを追加
//	11/08	23:17	幡手要		UI表示用オブジェクトの追加中
//	11/12	19:05	幡手要		不要部分の削除
//	11/14	09:55	幡手要		UIの表示方法をすべて3Dから2Dへ変更
//==============================================================

//==============================================================
//  インクルード
//==============================================================
#include "menu.h"
#include "Input.h"
#include "Main.h"
#include "SceneStageSelect.h"
#include <stdio.h>

// 定数定義
#define MENU_FADEMOVEX	(250)
#define MENU_FADEFRAME	(30)

using namespace std;

//==============================================================
//　関数名：Menu::Menu()
//	引数１：なし
//	戻り値：なし
//
//	概　要：Menuクラスのコンストラクタ	
//==============================================================
Menu::Menu()
	: m_nDrawNum(0),
	  m_MenuPosX{ -230.0f,1615.0f },
	  m_MenuSelectKind(E_CONTINU),
	  m_OldSelectMenu(E_CONTINU),
	  m_MenuKind(E_NONE),
	  m_MenuAnimKind(E_CONTINUE_LR),
	  m_GameUIPosX(-230.0f),
	  m_MenuAnim_UVPos{0.0f,0.0f},
	  m_MenuSelectSize(750.0f),
	  m_bMenu(false),
	  m_RetryFlg(false),
	  m_ReturnFlg(false),
	  m_ClickAnimflg(false),
	  m_pSEMenuSpeaker(nullptr),
	  m_pSEMenuMoveSpeaker(nullptr),
	  m_pSEMenuRetrySpeaker(nullptr)
{
	//---- テクスチャクラスの確保 ----
	for (int i = 0; i < MAX_TEXTURE; i++)
	{
		m_pTexture[i] = new Texture();
	}

	for (int i = 0; i < MAX_SECRET_TEX; i++)
	{
		m_pSecretTex[i] = new Texture();
	}

	for (int i = 0; i < MAX_ANIM_TEX; i++)
	{
		m_pAnimTex[i] = new Texture();
	}

	//---- テクスチャの読み込み ----
	//---- ゲーム画面内 ----
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Game/UI_Game_Pause_01.png")))
	{
		MessageBox(NULL, "UI_Game_Pause_01が読み込めませんでした", "Error", MB_OK);
	}

	//---- メニュー画面 ----
	// 背景
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_PauseBG_005.png")))
	{
		MessageBox(NULL, "UI_Pause_PauseBG_005.pngが読み込めませんでした", "Error", MB_OK);
	}
	// 続ける（小）
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Continue(Small)_001.png")))
	{
		MessageBox(NULL, "UI_Pause_Continue(Small)_001.pngが読み込めませんでした", "Error", MB_OK);
	}
	// 続ける（大）
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Continue(Big)_007.png")))
	{
		MessageBox(NULL, "UI_Pause_Continue(Big)WithA_001.pngが読み込めませんでした", "Error", MB_OK);
	}
	// リトライ（小）
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Restart(small)_001.png")))
	{
		MessageBox(NULL, "UI_Pause_Restart(small)_001が読み込めませんでした", "Error", MB_OK);
	}
	// リトライ（大）
	if (FAILED(m_pTexture[5]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Restart(Big)_007.png")))
	{
		MessageBox(NULL, "UI_Pause_Restart(Big)WithA_001が読み込めませんでした", "Error", MB_OK);
	}
	// ステージセレクトに戻る（小）
	if (FAILED(m_pTexture[6]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_GiveUp(small)_002.png")))
	{
		MessageBox(NULL, "UI_Pause_GiveUp(small)_002が読み込めませんでした", "Error", MB_OK);
	}
	// ステージセレクトに戻る（大）
	if (FAILED(m_pTexture[7]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_SelectBack(Big)_007.png")))
	{
		MessageBox(NULL, "UI_Pause_SelectBack(Big)WithA_001が読み込めませんでした", "Error", MB_OK);
	}
	// もどる
	if (FAILED(m_pTexture[8]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_BackB_004.png")))
	{
		MessageBox(NULL, "UI_Pause_BBack_002が読み込めませんでした", "Error", MB_OK);
	}
	// ステージナンバー（スプライトシート）
	if (FAILED(m_pTexture[9]->Create("Assets/Texture/UI/Game/Menu/UI_common_NoSpr_003.png")))
	{
		MessageBox(NULL, "UI_common_NoSpr_001が読み込めませんでした", "Error", MB_OK);
	}
	// 難易度（スプライトシート）
	if (FAILED(m_pTexture[10]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_StarSpr_003.png")))
	{
		MessageBox(NULL, "UI_Pause_StarSpr_003が読み込めませんでした", "Error", MB_OK);
	}
	// Tips（女の子「つづける」）
	if (FAILED(m_pTexture[11]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_king_tudukeru.png")))
	{
		MessageBox(NULL, "UI_Pause_king_001が読み込めませんでした", "Error", MB_OK);
	}
	// Tips（ひみつ）
	if (FAILED(m_pTexture[12]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Secret_001.png")))
	{
		MessageBox(NULL, "UI_Pause_Secret_001が読み込めませんでした", "Error", MB_OK);
	}
	// Tips（文字出すとこ）
	if (FAILED(m_pTexture[13]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_BlackPopUp_001.png")))
	{
		MessageBox(NULL, "UI_Pause_BlackPopUp_001が読み込めませんでした", "Error", MB_OK);
	}
	// 決定
	if (FAILED(m_pTexture[14]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_DecideA_002.png")))
	{
		MessageBox(NULL, "UI_Pause_DecideA_002が読み込めませんでした", "Error", MB_OK);
	}
	// 黒背景
	if (FAILED(m_pTexture[15]->Create("Assets/Texture/UI/Game/BlackGround.png")))
	{
		MessageBox(NULL, "BlackGroundが読み込めませんでした", "Error", MB_OK);
	}

	// Tips（女の子「やり直す」）
	if (FAILED(m_pTexture[16]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_king_yarinaosu.png")))
	{
		MessageBox(NULL, "UI_Pause_king_001が読み込めませんでした", "Error", MB_OK);
	}
	// Tips（女の子「セレクトに戻る」）
	if (FAILED(m_pTexture[17]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_king_selectnimodoru.png")))
	{
		MessageBox(NULL, "UI_Pause_king_001が読み込めませんでした", "Error", MB_OK);
	}

	//---- すぽいむの秘密 ----
	if (FAILED(m_pSecretTex[0]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_01.png")))
	{
		MessageBox(NULL, "すぽいむのひみつ１が読み込めませんでした", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[1]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_02.png")))
	{
		MessageBox(NULL, "すぽいむのひみつ２が読み込めませんでした", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[2]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_03.png")))
	{
		MessageBox(NULL, "すぽいむのひみつ３が読み込めませんでした", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[3]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_07.png")))
	{
		MessageBox(NULL, "すぽいむのひみつ４が読み込めませんでした", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[4]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_05.png")))
	{
		MessageBox(NULL, "すぽいむのひみつ５が読み込めませんでした", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[5]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_06.png")))
	{
		MessageBox(NULL, "すぽいむのひみつ６が読み込めませんでした", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[6]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_04.png")))
	{
		MessageBox(NULL, "すぽいむのひみつ７が読み込めませんでした", "Error", MB_OK);
	}

	//---- アニメーション用画像 ----
	// 左右(続ける)
	if (FAILED(m_pAnimTex[0]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_ContinueLfR_001.png")))
	{
		MessageBox(NULL, "コンテニュー左右アニメーションが読み込めませんでした", "Error", MB_OK);
	}
	// 上下(続ける)
	if (FAILED(m_pAnimTex[1]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_ContinueDfT_001.png")))
	{
		MessageBox(NULL, "コンテニュー上下アニメーションが読み込めませんでした", "Error", MB_OK);
	}
	// 上下(やりなおす・上から)
	if (FAILED(m_pAnimTex[2]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_RestartTfD_001.png")))
	{
		MessageBox(NULL, "やりなおす上下アニメーション１が読み込めませんでした", "Error", MB_OK);
	}
	// 上下(やりなおす・下から)
	if (FAILED(m_pAnimTex[3]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_RestartDft_001.png")))
	{
		MessageBox(NULL, "やりなおす上下アニメーション２が読み込めませんでした", "Error", MB_OK);
	}
	// 上下(セレクトに戻る)
	if (FAILED(m_pAnimTex[4]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_SelectBackTfD_001.png")))
	{
		MessageBox(NULL, "セレクトに戻る上下アニメーションが読み込めませんでした", "Error", MB_OK);
	}

	// 難易度(EX)
	m_pEXdifficulty = new Texture();
	if (FAILED(m_pEXdifficulty->Create("Assets/Texture/UI/Game/Menu/UI_Pause_StarRedSpr_001.png")))
	{
		MessageBox(NULL, "セレクトに戻る上下アニメーションが読み込めませんでした", "Error", MB_OK);
	}

	// イージングクラスの確保
	m_pEasing = new Easing();

	// イージングの初期化
	m_pEasing->ResetChangePowPlay();
	m_pEasing->ResetChangePowRevarse();

	// アニメーションクラスの確保
	m_pAnimation = new CAnim();

	// 初期アニメーションの設定
	AnimData MenuAnimData;
	MenuAnimData.nAnimeFrame  = MENU_ANIM_FRAME;
	MenuAnimData.nAnimeSplitX = MENU_ANIME_SPLIT_X;
	MenuAnimData.nAnimeSplitY = MENU_ANIME_SPLIT_Y;
	MenuAnimData.nEndAnimNo   = MENU_ANIME_END;

	m_pAnimation->SetAnime(MenuAnimData);

	//サウンドの読み込み
	m_pSEMenuOpen = LoadSound("Assets/SE/supotto_UI_menu_open_V1.wav");//メニューオープン
	m_pSEMenuClose = LoadSound("Assets/SE/supotto_UI_menu_close_V1.wav");//メニュークローズ
	m_pSEMenuDecision = LoadSound("Assets/SE/supotto_UI_kettei_V1.wav");//メニュー決定音
	m_pSEMenuMove = LoadSound("Assets/SE/supotto_UI_Move.wav");//メニュー移動音
	m_pSEMenuRetry = LoadSound("Assets/SE/supotto_UI_Retry.wav");//メニュー移動音
}

//==============================================================
//　関数名：Menu::~Menu()
//	引数１：なし
//	戻り値：なし
//
//	概　要：Menuクラスのデストラクタ
//==============================================================
Menu::~Menu()
{
	// テクスチャの開放
	if (m_pTexture)
	{
		for (int i = 0; i < MAX_TEXTURE; i++)
		{
			delete m_pTexture[i];
			m_pTexture[i] = nullptr;
		}
	}

	if (m_pSecretTex)
	{
		for (int i = 0; i < MAX_SECRET_TEX; i++)
		{
			delete m_pSecretTex[i];
			m_pSecretTex[i] = nullptr;
		}
	}

	if (m_pAnimTex)
	{
		for (int i = 0; i < MAX_ANIM_TEX; i++)
		{
			delete m_pAnimTex[i];
			m_pAnimTex[i] = nullptr;
		}
	}

	// イージングクラスの開放
	if (m_pEasing)
	{
		delete m_pEasing;
		m_pEasing = nullptr;
	}

	if (m_pAnimation)
	{
		delete m_pAnimation;
		m_pAnimation = nullptr;
	}
}

//==============================================================
//	関数名：void Menu::Update()
//	引数１：なし
//	引数２：なし
//	戻り値：なし
//
//	概要：メニューの更新処理
//==============================================================
void Menu::Update()
{
	// イージングのリセット
	if (m_MenuKind == E_NONE)
	{
		m_pEasing->ResetChangePowPlay();
		m_pEasing->ResetChangePowRevarse();
		m_pAnimation->SetClickAnimkind();
	}

	// メニューの開閉処理
	if (!m_pEasing->GetIsPlay() && IsKeyTrigger(VK_ESCAPE) && m_MenuKind == E_NONE ||!m_pEasing->GetIsPlay() && IsKeyTrigger(VK_ESCAPE) && m_MenuKind == E_CLOSE ||
		!m_pEasing->GetIsPlay() && IsButtonTrigger(BUTTON_START) && m_MenuKind == E_NONE || !m_pEasing->GetIsPlay() && IsButtonTrigger(BUTTON_START) && m_MenuKind == E_CLOSE)
	{
		PlaySEOpen();	//オープンSE再生
		m_nOldRandNo = m_RandomNo;

		// メニューを開く(最初の時)
		if (m_MenuKind == E_NONE)
		{
			m_MenuKind++;
		}

		// メニューを開く(メニューがしまっているとき)
		if (m_MenuKind == E_CLOSE)
		{
			m_MenuKind--;
		}

		// イージングのリセット
		m_pEasing->ResetChangePowRevarse();

		while (m_nOldRandNo == m_RandomNo)
		{
			if (GetStage() < STAGE_3_01)
				m_RandomNo = rand() % 5 + 1;
			else
				m_RandomNo = rand() % 6 + 1;
		}

		// メニューを開いてるか送るための切り替え
		m_bMenu = true;
	}
	else if(!m_pEasing->GetIsPlay() && IsKeyTrigger(VK_ESCAPE) && m_MenuKind == E_OPEN ||
		!m_pEasing->GetIsPlay() && IsButtonTrigger(BUTTON_START) && m_MenuKind == E_OPEN ||
		!m_pEasing->GetIsPlay() && IsButtonTrigger(BUTTON_B) && m_MenuKind == E_OPEN)
	{
		PlaySEClose();//クローズSE再生
		// メニューを閉じる
		m_MenuKind++;

		// イージングのリセット
		m_pEasing->ResetChangePowPlay();

		// メニューを開いてるか送るための切り替え
		m_bMenu = false;
	}

	// メニューの移動処理
	if (m_MenuKind == E_OPEN)	// trueならメニューが出てくる、falseならメニューが引っ込む
	{
		MoveUI();

		// イージングのリセット
		m_pEasing->ResetChangePowRevarse();
	}
	else if(m_MenuKind == E_CLOSE)
	{
		ResetUI();

		// イージングのリセット
		m_pEasing->ResetChangePowPlay();

		if (m_MenuPosX[0] <= -230.0f)
		{
			m_MenuSelectKind = E_CONTINU;
		}
	}

	// メニュー内の選択
	if (m_bMenu)
	{
		if (IsKeyTrigger('W') || IsButtonTrigger(BUTTON_UP) || IsButtonTrigger(STICK_UP))
		{
			// 過去の選択データを格納
			m_OldSelectMenu = m_MenuSelectKind;
			m_MenuSelectKind--;
			m_pAnimation->ResetUvPos();

			if (m_MenuSelectKind < E_CONTINU)
			{
				// 過去の選択データを格納
				m_OldSelectMenu = m_MenuSelectKind;
				m_MenuSelectKind = E_RETRUN;
				m_pAnimation->ResetUvPos();
			}

			if (m_bMenu) {
				//移動SE
				if (m_pSEMenuMoveSpeaker) {
					m_pSEMenuMoveSpeaker->DestroyVoice();
					m_pSEMenuMoveSpeaker = nullptr;
				}
				m_pSEMenuMoveSpeaker = PlaySound(m_pSEMenuMove);
			}
		}
		else if (IsKeyTrigger('S') || IsButtonTrigger(BUTTON_DOWN) || IsButtonTrigger(STICK_DOWN))
		{
			// 過去の選択データを格納
			m_OldSelectMenu = m_MenuSelectKind;
			m_MenuSelectKind++;
			m_pAnimation->ResetUvPos();

			if (m_MenuSelectKind > E_RETRUN)
			{
				// 過去の選択データを格納
				m_OldSelectMenu = m_MenuSelectKind;
				m_MenuSelectKind = E_CONTINU;
				m_pAnimation->ResetUvPos();
			}

			if (m_bMenu) {
				//移動SE
				if (m_pSEMenuMoveSpeaker) {
					m_pSEMenuMoveSpeaker->DestroyVoice();
					m_pSEMenuMoveSpeaker = nullptr;
				}
				m_pSEMenuMoveSpeaker = PlaySound(m_pSEMenuMove);
			}
		}

		// メニューを選択した後の処理
		if (m_bMenu && m_MenuSelectKind == E_RETRUN && IsKeyTrigger(VK_RETURN) && !IsKeyTrigger(VK_ESCAPE) ||
			m_bMenu && m_MenuSelectKind == E_RETRUN && IsButtonTrigger(BUTTON_A) && !IsKeyTrigger(VK_ESCAPE))
		{
			PlaySEDecision();	//決定SEの再生
			//リターンフラグの送信
			m_ReturnFlg = true;

			m_ClickAnimflg = true;

			// メニューの切り替え
			m_bMenu = false;
			m_MenuKind++;
		}
		else if (m_bMenu && m_MenuSelectKind == E_CONTINU && IsKeyTrigger(VK_RETURN) && !IsKeyTrigger(VK_ESCAPE) ||
			m_bMenu && m_MenuSelectKind == E_CONTINU && IsButtonTrigger(BUTTON_A) && !IsKeyTrigger(VK_ESCAPE))
		{
			PlaySEDecision();	//決定SEの再生

			m_ClickAnimflg = true;

			// メニューの切り替え
			m_bMenu = false;
			m_MenuKind++;
		}
		else if (m_bMenu && m_MenuSelectKind == E_RETRY && IsKeyTrigger(VK_RETURN) && !IsKeyTrigger(VK_ESCAPE) ||
			m_bMenu && m_MenuSelectKind == E_RETRY && IsButtonTrigger(BUTTON_A) && !IsKeyTrigger(VK_ESCAPE))
		{
			//	PlaySEDecision();	//決定SEの再生
			if (m_pSEMenuRetrySpeaker) {
				m_pSEMenuRetrySpeaker->DestroyVoice();
				m_pSEMenuRetrySpeaker = nullptr;
			}
			m_pSEMenuRetrySpeaker = PlaySound(m_pSEMenuRetry);
			m_pSEMenuRetrySpeaker->SetVolume(0.6f);

			m_ClickAnimflg = true;

			// リトライフラグの送信
			m_RetryFlg = true;

			// メニューの切り替え
			m_bMenu = false;
			m_MenuKind++;
		}
	}

	if (m_ClickAnimflg)
	{
		m_MenuSelectSize = m_pAnimation->Animation_Click(m_MenuSelectSize, 750.0f, 750.0f * 0.8f, 25.0f);
	}

	if (m_MenuPosX[0] <= -230.0f)
	{
		m_ClickAnimflg = false;
		// アニメーションのリセット
		m_pAnimation->SetClickAnimkind();
		m_MenuSelectSize = 750.0f;
	}

	if (m_bMenu)
	{
		// テクスチャアニメーション
		m_MenuAnim_UVPos = m_pAnimation->TextureAnimation(false);
	}
	else
	{
		m_pAnimation->ResetUvPos();
		m_OldSelectMenu = E_CONTINU;		
	}
}

//==============================================================
//	関数名：void Menu::Draw_GameUI()
//	引数１：なし
//	引数２：なし
//	戻り値：なし
//
//	概要：ゲーム内UIの描画処理の関数
//==============================================================
void Menu::Draw_GameUI()
{
	//---- ゲーム内UI ----
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_GameUIPosX, 650.0f, -1.0f);
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
	Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[0]);
	Sprite::Draw();
}

//==============================================================
//	関数名：void Menu::Draw_MenuUI()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニュー中UIの描画処理
//==============================================================
void Menu::Draw_MenuUI()
{
	//---- オプションUI ----
	DirectX::XMFLOAT4X4 mat[3];

	// 画面を暗くする画像
	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 0.55f));
	Sprite::SetTexture(m_pTexture[15]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_bMenu)	
	{
		Sprite::Draw();
	}

	// ポーズ背景
	world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 360.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_HEIGHT, SCREEN_HEIGHT));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[1]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// Tips(文字出るとこ)
	world = DirectX::XMMatrixTranslation(m_MenuPosX[1], 120.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(700.0f, 700.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[13]);
	Sprite::Draw();

	// 各選択肢を選んでいるときの描画
	if (m_MenuSelectKind == E_CONTINU)	// 続けるの時
	{
		if (m_OldSelectMenu == E_CONTINU && m_MenuSelectKind == E_CONTINU)
		{
			// 続ける
			world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 425.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_MenuSelectSize, m_MenuSelectSize));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pAnimTex[0]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f / (float)MENU_ANIME_SPLIT_X, 1.0f / (float)MENU_ANIME_SPLIT_Y));
			Sprite::SetUVPos(m_MenuAnim_UVPos);
			Sprite::UIDraw();
		}

		if (m_OldSelectMenu == E_RETRY && m_MenuSelectKind == E_CONTINU || m_OldSelectMenu == 3 && m_MenuSelectKind == E_CONTINU)
		{
			// 続ける
			world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 430.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_MenuSelectSize, m_MenuSelectSize));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pAnimTex[1]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f / (float)MENU_ANIME_SPLIT_X, 1.0f / (float)MENU_ANIME_SPLIT_Y));
			Sprite::SetUVPos(m_MenuAnim_UVPos);
			Sprite::UIDraw();
		}

		// やりなおす
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 200.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セレクトに戻る
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 115.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[6]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Tips(ひみつ)
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 225.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[12]);
		Sprite::Draw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 375.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(300.0f, 300.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[11]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();
	}
	else if (m_MenuSelectKind == E_RETRY)
	{
		// 続ける
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 565.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		if (m_OldSelectMenu == E_CONTINU && m_MenuSelectKind == E_RETRY)
		{
			// やりなおす
			world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 345.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_MenuSelectSize, m_MenuSelectSize));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pAnimTex[2]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f / (float)MENU_ANIME_SPLIT_X, 1.0f / (float)MENU_ANIME_SPLIT_Y));
			Sprite::SetUVPos(m_MenuAnim_UVPos);
			Sprite::UIDraw();
		}

		if (m_OldSelectMenu == E_RETRUN && m_MenuSelectKind == E_RETRY)
		{
			// やりなおす
			world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 345.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_MenuSelectSize, m_MenuSelectSize));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pAnimTex[3]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f / (float)MENU_ANIME_SPLIT_X, 1.0f / (float)MENU_ANIME_SPLIT_Y));
			Sprite::SetUVPos(m_MenuAnim_UVPos);
			Sprite::UIDraw();
		}

		// セレクトに戻る
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 115.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[6]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Tips(ひみつ)
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 225.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[12]);
		Sprite::Draw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 375.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(300.0f, 300.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[16]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();
	}
	else if(m_MenuSelectKind == E_RETRUN)
	{
		// 続ける
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 565.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// やりなおす
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 485.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セレクトに戻る
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 270.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_MenuSelectSize, m_MenuSelectSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pAnimTex[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f / (float)MENU_ANIME_SPLIT_X, 1.0f / (float)MENU_ANIME_SPLIT_Y));
		Sprite::SetUVPos(m_MenuAnim_UVPos);
		Sprite::UIDraw();

		// Tips(ひみつ)
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 225.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::SetTexture(m_pTexture[12]);
		Sprite::Draw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 375.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(300.0f, 300.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[17]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();
	}

	// もどる
	world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 27.5f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(150.0f, 150.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::Draw();

	// 決定
	world = DirectX::XMMatrixTranslation(m_MenuPosX[0] - 145.0f, 27.5f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(150.0f, 150.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[14]);
	Sprite::Draw();

	// ステージナンバー + 難易度
	Draw_StageNum();

	Draw_Secret(m_RandomNo);
}

//==============================================================
//	関数名：void Menu::Draw_StageNum(eWorldKind world)
//	引数１：eWorldKind playworld(どのステージにいるか)
//	戻り値：なし
//
//	概要：メニューのステージナンバー表示用関数
//==============================================================
void Menu::Draw_StageNum()
{
	// ステージ１
	if (GetStage() >= STAGE_1_01 && GetStage() <= STAGE_1_05)
	{
		//---- 基本情報 ----
		DirectX::XMFLOAT4X4 mat[3];

		// ワールドナンバー
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 195.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();

		// -
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 245.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.5f));
		Sprite::UIDraw();

		switch (GetStage())
		{
		case STAGE_1_01:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_1_02:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_1_03:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_1_04:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_1_05:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherEasy);
			break;

		default:
			break;
		}
	}

	// ステージ２
	if (GetStage() >= STAGE_2_01 && GetStage() <= STAGE_2_06)
	{
		//---- 基本情報 ----
		DirectX::XMFLOAT4X4 mat[3];

		// ワールドナンバー
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 185.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
		Sprite::UIDraw();

		// -
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 245.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.5f));
		Sprite::UIDraw();

		switch (GetStage())
		{
		case STAGE_2_01:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_2_02:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_2_03:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_2_04:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_2_05:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_2_06:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		default:
			break;
		}
	}

	// ステージ３
	if (GetStage() >= STAGE_3_01 && GetStage() <= STAGE_3_07)
	{
		//---- 基本情報 ----
		DirectX::XMFLOAT4X4 mat[3];

		// ワールドナンバー
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 180.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
		Sprite::UIDraw();

		// -
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 245.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.5f));
		Sprite::UIDraw();

		switch (GetStage())
		{
		case STAGE_3_01:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_3_02:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_3_03:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_3_04:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_3_05:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_3_06:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_3_07:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult);
			break;

		default:
			break;
		}
	}

	// ステージ４
	if (GetStage() >= STAGE_4_01 && GetStage() <= STAGE_4_08)
	{
		//---- 基本情報 ----
		DirectX::XMFLOAT4X4 mat[3];

		// ワールドナンバー
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 180.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
		Sprite::UIDraw();

		// -
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 245.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.5f));
		Sprite::UIDraw();

		switch (GetStage())
		{
		case STAGE_4_01:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_4_02:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_4_03:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_4_04:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_4_05:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_4_06:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_4_07:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_4_08:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult);
			break;

		default:
			break;
		}
	}

	// ステージ５
	if (GetStage() >= STAGE_5_01 && GetStage() <= STAGE_5_10)
	{
		// -
		//---- 基本情報 ----
		DirectX::XMFLOAT4X4 mat[3];
		DirectX::XMMATRIX world;

		if (GetStage() >= STAGE_5_01 && GetStage() < STAGE_5_10)
		{
			// ワールドナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 180.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 245.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.5f));
			Sprite::UIDraw();
		}

		if (GetStage() == STAGE_5_10)
		{
			// ワールドナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 150.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 210.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.5f));
			Sprite::UIDraw();
		}

		switch (GetStage())
		{
		case STAGE_5_01:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_5_02:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_5_03:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_5_04:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_5_05:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_06:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_07:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_08:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_09:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.5f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_10:
			// ステージナンバー(１０の位)
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 260.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// ステージナンバー(１の位)
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 320.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.5f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Difficult);
			break;

		
		default:
			break;
		}
	}

	// ステージEX
	if (GetStage() >= STAGE_EX_01 && GetStage() <= STAGE_EX_05)
	{
		// -
		//---- 基本情報 ----
		DirectX::XMFLOAT4X4 mat[3];
		DirectX::XMMATRIX world;

		// ワールドナンバー
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 120.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.5f));
		Sprite::UIDraw();

		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 185.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.75f));
		Sprite::UIDraw();

		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 245.0f, 660.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2((float)1.0f / 4, (float)1.0f / 4));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.5f));
		Sprite::UIDraw();

		switch (GetStage())
		{
		case STAGE_EX_01:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Easy_EX);
			break;

		case STAGE_EX_02:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherEasy_EX);
			break;

		case STAGE_EX_03:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Normal_EX);
			break;

		case STAGE_EX_04:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_RatherDifficult_EX);
			break;

		case STAGE_EX_05:
			// ステージナンバー
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// 難易度
			Draw_Difficulty(E_Difficult_EX);
			break;
		default:
			break;
		}
	}
}

//==============================================================
//	関数名：void Menu::Draw_Secret()
//	引数１：なし
//	戻り値：なし
//
//	概要：すぽいむの秘密の表示
//==============================================================
void Menu::Draw_Secret(int Secret)
{
	DirectX::XMFLOAT4X4 mat[3];
	DirectX::XMMATRIX world;

	switch (Secret)
	{
	case E_SERCRET01:
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1], 125.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(600.0f, 600.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::SetTexture(m_pSecretTex[0]);
		Sprite::UIDraw();
		break;

	case E_SERCRET02:
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1], 140.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(635.0f, 635.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::SetTexture(m_pSecretTex[1]);
		Sprite::UIDraw();
		break;

	case E_SERCRET03:
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1], 135.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(645.0f, 645.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::SetTexture(m_pSecretTex[2]);
		Sprite::UIDraw();
		break;

	case E_SERCRET04:
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] - 5.0f, 110.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(670.0f, 670.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::SetTexture(m_pSecretTex[3]);
		Sprite::UIDraw();
		break;

	case E_SERCRET05:
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1], 120.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(680.0f, 680.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::SetTexture(m_pSecretTex[4]);
		Sprite::UIDraw();
		break;

	case E_SERCRET06:
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1], 130.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(620.0f, 620.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::SetTexture(m_pSecretTex[5]);
		Sprite::UIDraw();
		break;

	case E_SERCRET07:
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1], 160.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(690.0f, 690.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::SetTexture(m_pSecretTex[6]);
		Sprite::UIDraw();
		break;
	default:
		break;
	}
}

void Menu::Draw_Difficulty(int difficulty)
{
	DirectX::XMFLOAT4X4 mat[3];
	DirectX::XMMATRIX world;

	switch (difficulty)
	{
	case E_Easy:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[10]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
		Sprite::Draw();
		break;

	case E_RatherEasy:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[10]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.2f));
		Sprite::Draw();
		break;

	case E_Normal:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[10]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.4f));
		Sprite::Draw();
		break;

	case E_RatherDifficult:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[10]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.6f));
		Sprite::Draw();
		break;

	case E_Difficult:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[10]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.8f));
		Sprite::Draw();
		break;

	case E_Easy_EX:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pEXdifficulty);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
		Sprite::Draw();
		break;

	case E_RatherEasy_EX:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pEXdifficulty);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.2f));
		Sprite::Draw();
		break;

	case E_Normal_EX:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pEXdifficulty);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.4f));
		Sprite::Draw();
		break;

	case E_RatherDifficult_EX:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pEXdifficulty);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.6f));
		Sprite::Draw();
		break;

	case E_Difficult_EX:
		// 難易度
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 575.0f, 1.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 80.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pEXdifficulty);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f / 5.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.8f));
		Sprite::Draw();
		break;

	default:
		break;
	}
}

//==============================================================
//	関数名：void Menu::MoveStartUI()
//	引数１：なし
//	戻り値：なし
//
//	概要：スタート演出中の右上UIの移動処理
//==============================================================
void Menu::MoveStartUI()
{
	m_GameUIPosX = m_pEasing->MoveEaseOutQuad(-230.0f, 75.0f, 0.02f, true);
}

//==============================================================
//	関数名：void Menu::MoveEndUI()
//	引数１：なし
//	戻り値：なし
//
//	概要：ゴール演出中の右上UIの移動処理
//==============================================================
void Menu::MoveEndUI()
{
	m_GameUIPosX = m_pEasing->MoveEaseOutQuad(-230.0f, 75.0f, 0.02f, false);
}

//==============================================================
//	関数名：void Menu::MoveUI()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニューを開いたときの移動処理
//==============================================================
void Menu::MoveUI()
{
	m_MenuPosX[0] = m_pEasing->MoveEaseOutBack(-230.0f, 220.0f, 0.025f, true);

	m_MenuPosX[1] = m_pEasing->MoveEaseOutBack(1615.0f, 905.0f, 0.045f, true);
}

//==============================================================
//	関数名：void Menu::ResetUI()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニューを閉じたときの移動処理
//==============================================================
void Menu::ResetUI()
{
	m_MenuPosX[0] = m_pEasing->MoveEaseOutBack(-230.0f, 220.0f, 0.025f, false);

	m_MenuPosX[1] = m_pEasing->MoveEaseOutBack(1615.0f, 905.0f, 0.045f, false);
}

void Menu::ResetRetryflg()
{
	m_RetryFlg = false;
}

//==============================================================
//	関数名：void Menu::SetMenuSelectKind()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニューを閉じたときにメニューの選択をリセットする処理
//==============================================================
int  Menu::SetMenuSelectContinu()
{
	return m_MenuSelectKind = E_CONTINU;
}

//==============================================================
//	関数名：void Menu::GetMenuSelectKind()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニューの状態を渡す処理（選択状態）
//==============================================================
int Menu::GetMenuSelectKind()
{
	return m_MenuSelectKind;
}

//==============================================================
//	関数名：void Menu::GetMenuSelectKind()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニューの状態を渡す処理（メニューが開かれてるか）
//==============================================================
int Menu::GetMenuKined()
{
	return m_MenuKind;
}

//==============================================================
//	関数名：void Menu::GetbMenu()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニューUIを開いているかどうか返す関数
//==============================================================
bool Menu::GetbMenu()
{
	return m_bMenu;
}

//==============================================================
//	関数名：void Menu::GetRetryFlg()
//	引数１：なし
//	戻り値：なし
//
//	概要：リトライが選ばれているか返す関数
//==============================================================
bool Menu::GetRetryFlg()
{
	return m_RetryFlg;
}

//==============================================================
//	関数名：void Menu::GetReturnFlg()
//	引数１：なし
//	戻り値：なし
//
//	概要：セレクトに戻るが選ばれているか返す関数
//==============================================================
bool Menu::GetReturnFlg()
{
	return m_ReturnFlg;
}

//オープンSE再生
void Menu::PlaySEOpen()
{
	if (m_pSEMenuSpeaker) {
		m_pSEMenuSpeaker->DestroyVoice();
		m_pSEMenuSpeaker = nullptr;
	}
	m_pSEMenuSpeaker = PlaySound(m_pSEMenuOpen);//オープンSE再生
}

//クローズSE再生
void Menu::PlaySEClose()
{
	if (m_pSEMenuSpeaker) {
		m_pSEMenuSpeaker->DestroyVoice();
		m_pSEMenuSpeaker = nullptr;
	}
	m_pSEMenuSpeaker = PlaySound(m_pSEMenuClose);//クローズSE再生
}

//決定SE再生
void Menu::PlaySEDecision()
{
	if (m_pSEMenuSpeaker) {
		m_pSEMenuSpeaker->DestroyVoice();
		m_pSEMenuSpeaker = nullptr;
	}
	m_pSEMenuSpeaker = PlaySound(m_pSEMenuDecision);//決定SE再生
}

//==============================================================
//	関数名：void Menu::SetMotionLess()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニューが動かないようにする関数
//==============================================================
int Menu::SetMotionLess()
{
	return m_MenuKind = E_MOTIONLESS;
}

//==============================================================
//	関数名：void Menu::SetNone()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニューが動くにする関数
//==============================================================
int Menu::SetNone()
{
	return m_MenuKind = E_NONE;
}

//==============================================================
//	関数名：void Menu::GetPos()
//	引数１：なし
//	戻り値：なし
//
//	概要：メニューUIの現在座標を渡す処理
//==============================================================
float Menu::GetPos()
{
	return m_MenuPosX[0];
}

//==============================================================
//	関数名：void CObject::SetCamera(CameraBase * pCamera)
//	引数１：カメラのポインタ
//	戻り値：なし
//	概要：カメラのポインタの受け渡し
//==============================================================
void Menu::SetCamera(CameraBase * pCamera)
{
	m_pCamera = pCamera;
}
