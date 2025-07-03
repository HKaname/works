#include "Title_UI.h"
#include "Main.h"

Title_UI::Title_UI()
	: m_CursorPosY(125.0f),
	m_CursorPosX(70.0f),
	m_TitleKind(E_CONTINUE),
	m_UVPos{ 0.0f, 0.0f },
	m_CursorSize(90.0f),
	m_Alpha(0.0f),
	m_TitleAnimDelayframe(0),
	m_SelectSize_Start(250.0f),
	m_SelectSize_End(250.0f),
	m_ClickAnimflg(false),
	m_pSEJumpSpeaker(nullptr),
	m_pSEButtonSpeaker(nullptr),
	m_pSEMoveCursorSpeaker(nullptr)
{
	for (int i = 0; i < MAX_UI_TEXTURE; i++)
	{
		m_pUITex[i] = new Texture();
	}

	// タイトルロゴ
	m_pTitleTex = new Texture();
	if (FAILED(!m_pTitleTex->Create("Assets/Texture/UI/Title/title.png")))
	{
		MessageBox(NULL, "title.pngが読み込めませんでした", "Error", MB_OK);
	}

	// はじめる
	if (FAILED(!m_pUITex[0]->Create("Assets/Texture/UI/Title/UI_Title_Start.png")))
	{
		MessageBox(NULL, "UI_Title_Startが読み込めませんでした", "Error", MB_OK);
	}

	// 続きから
	if (FAILED(!m_pUITex[1]->Create("Assets/Texture/UI/Title/UI_Title_continued.png")))
	{
		MessageBox(NULL, "UI_Title_Endが読み込めませんでした", "Error", MB_OK);
	}

	// Aボタン
	if (FAILED(!m_pUITex[2]->Create("Assets/Texture/UI/Title/UI_Title_Select.png")))
	{
		MessageBox(NULL, "UI_Title_Aが読み込めませんでした", "Error", MB_OK);
	}

	// 白いやつ（始まる側）
	if (FAILED(!m_pUITex[3]->Create("Assets/Texture/UI/Title/UI_Title_Start_flash.png")))
	{
		MessageBox(NULL, "UI_Title_Start_flashが読み込めませんでした", "Error", MB_OK);
	}

	// 白いやつ（続ける側）
	if (FAILED(!m_pUITex[4]->Create("Assets/Texture/UI/Title/UI_Title_continued_flash.png")))
	{
		MessageBox(NULL, "UI_Title_End_flashが読み込めませんでした", "Error", MB_OK);
	}

	// ボタン（黒色）
	if (FAILED(!m_pUITex[5]->Create("Assets/Texture/UI/Title/UI_common_ButtonBlack_002.png")))
	{
		MessageBox(NULL, "UI_common_ButtonBlack_001が読み込めませんでした", "Error", MB_OK);
	}

	// Aを押してスタート
	if (FAILED(!m_pUITex[6]->Create("Assets/Texture/UI/Title/UI_Title_Push_002.png")))
	{
		MessageBox(NULL, "m_pUITex[6]が読み込めませんでした", "Error", MB_OK);
	}

	// 黒いやつ（始まる側）
	if (FAILED(!m_pUITex[7]->Create("Assets/Texture/UI/Title/UI_Title_Start_black.png")))
	{
		MessageBox(NULL, "UI_Title_Start_flashが読み込めませんでした", "Error", MB_OK);
	}

	// 黒いやつ（続ける側）
	if (FAILED(!m_pUITex[8]->Create("Assets/Texture/UI/Title/UI_Title_continued_black.png")))
	{
		MessageBox(NULL, "UI_Title_End_flashが読み込めませんでした", "Error", MB_OK);
	}

	m_pAnim = new CAnim();

	// アニメーションの設定
	AnimData Title_AnimData;

	Title_AnimData.nAnimeFrame = TITLE_ANIM_FRAME;
	Title_AnimData.nAnimeSplitX = TITLE_ANIME_SPLIT_X;
	Title_AnimData.nAnimeSplitY = TITLE_ANIME_SPLIT_Y;
	Title_AnimData.nEndAnimNo = TITLE_ANIME_END;

	m_pAnim->SetAnime(Title_AnimData);

	//サウンドデータ読み込み
	//SE
	m_pSEJump = LoadSound("Assets/SE/TitleScene_Logo_SE.wav");//ジャンプ
	m_pSEButton = LoadSound("Assets/SE/TitleScene_Buttom_SE.wav");	//ボタン
	m_pSEMoveCursor = LoadSound("Assets/SE/supotto_UI_Move.wav");	//メニュー移動音
}

Title_UI::~Title_UI()
{
	if (m_pAnim) { delete m_pAnim; m_pAnim = nullptr; }
	if (m_pUITex)
	{
		for (int i = 0; i < MAX_UI_TEXTURE; i++)
		{
			delete m_pUITex[i];
			m_pUITex[i] = nullptr;
		}
	}
	if (m_pTitleTex) { delete m_pTitleTex; m_pTitleTex = nullptr; }
}

void Title_UI::Update()
{
	m_TitleAnimDelayframe++;

	if (GetIsSaveData())
	{
		

		if (m_TitleKind == E_CONTINUE && IsKeyTrigger('A') ||
			m_TitleKind == E_CONTINUE && IsButtonTrigger(BUTTON_LEFT) ||
			m_TitleKind == E_CONTINUE && IsButtonTrigger(STICK_LEFT))
		{
			m_TitleKind--;
			m_CursorPosX = 65.0f;
			//SE再生
			if (m_pSEMoveCursorSpeaker) {
				m_pSEMoveCursorSpeaker->DestroyVoice();
				m_pSEMoveCursorSpeaker = nullptr;
			}
			m_pSEMoveCursorSpeaker = PlaySound(m_pSEMoveCursor);//SE再生
		}
		else if (GetIsSaveData() && (m_TitleKind == E_START && IsKeyTrigger('D') ||
			m_TitleKind == E_START && IsButtonTrigger(BUTTON_RIGHT) ||
			m_TitleKind == E_START && IsButtonTrigger(STICK_RIGHT)))
		{
			m_TitleKind++;
			m_CursorPosX = 385.0f;
			//SE再生
			if (m_pSEMoveCursorSpeaker) {
				m_pSEMoveCursorSpeaker->DestroyVoice();
				m_pSEMoveCursorSpeaker = nullptr;
			}
			m_pSEMoveCursorSpeaker = PlaySound(m_pSEMoveCursor);//SE再生
		}

		if (m_TitleKind == E_START)
			m_CursorPosX = m_pAnim->Animation_Move(45.0f, 60.0f, 10.0f);
		else if (m_TitleKind == E_CONTINUE)
			m_CursorPosX = m_pAnim->Animation_Move(365.0f, 60.0f, 10.0f);
	}
	else
	{
		m_TitleKind = E_START;

		m_CursorPosX = m_pAnim->Animation_Move(185.0f, 60.0f, 10.0f);
	}

	if (IsKeyTrigger(VK_RETURN) || IsButtonTrigger(BUTTON_A))
	{
		m_ClickAnimflg = true;
		if (!m_pSEButtonSpeaker) {
			m_pSEButtonSpeaker = PlaySound(m_pSEButton);//ボタンSE再生
			m_pSEButtonSpeaker->SetVolume(0.6f);//音量
		}
	}

	if (m_TitleKind == E_START && m_ClickAnimflg)
	{
		m_SelectSize_Start = m_pAnim->Animation_Click(m_SelectSize_Start, 250.0f, 250.0f * 0.75f, 5.0f);
	}
	else if (m_TitleKind == E_CONTINUE && m_ClickAnimflg)
	{
		m_SelectSize_End = m_pAnim->Animation_Click(m_SelectSize_End, 250.0f, 250.0f * 0.75f, 5.0f);
	}

	m_Alpha = m_pAnim->Animation_Scale(120.0f, 1.0f, 0.0f);

	// タイトルのアニメーション
	if (m_TitleAnimDelayframe < TITLE_ANIME_END * TITLE_ANIM_FRAME)
		m_UVPos = m_pAnim->TextureAnimation(true);

	if (m_TitleAnimDelayframe > TITLE_ANIME_DELAYFRAME)
	{
		m_TitleAnimDelayframe = 0;
	}

	// タイトルロゴのジャンプSE
	if (m_pAnim->GetCurrentNo() == 13) {
		//データ破棄
		if (m_pSEJumpSpeaker) {
			m_pSEJumpSpeaker->DestroyVoice();
			m_pSEJumpSpeaker = nullptr;
		}
		m_pSEJumpSpeaker = PlaySound(m_pSEJump);//再生
	}
}

void Title_UI::Draw()
{
	//---- ゲーム内UI ----
	DirectX::XMFLOAT4X4 mat[3];

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation((float)350.0f, (float)350.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(1000.0f, 800.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTitleTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f / (float)TITLE_ANIME_SPLIT_X, 1.0f / (float)TITLE_ANIME_SPLIT_Y));
	Sprite::SetUVPos(m_UVPos);
	SetBlendMode(OPACITY_BLEND_ALPHA);
	Sprite::Draw();
	SetBlendMode(BLEND_ALPHA);

	if (!GetIsSaveData())
	{
		// 白い奴（始める）
		world = DirectX::XMMatrixTranslation(350.0f, 125.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_Start + 10.0f, m_SelectSize_Start + 10.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_Alpha));
		Sprite::SetTexture(m_pUITex[3]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		SetBlendMode(OPACITY_BLEND_ALPHA);
		Sprite::UIDraw();
		SetBlendMode(BLEND_ALPHA);

		// はじめから
		world = DirectX::XMMatrixTranslation(350.0f, 125.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_Start, m_SelectSize_Start));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pUITex[0]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
	}

	if (GetIsSaveData()) // セーブデータがある時のみ描画
	{
		if (m_TitleKind == E_START)
		{
			// 白い奴（始める）
			world = DirectX::XMMatrixTranslation(200.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_Start + 10.0f, m_SelectSize_Start + 10.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_Alpha));
			Sprite::SetTexture(m_pUITex[3]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			SetBlendMode(OPACITY_BLEND_ALPHA);
			Sprite::UIDraw();
			SetBlendMode(BLEND_ALPHA);

			// はじめから
			world = DirectX::XMMatrixTranslation(200.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_Start, m_SelectSize_Start));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pUITex[0]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::UIDraw();

			// つづきから
			world = DirectX::XMMatrixTranslation(525.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_End, m_SelectSize_End));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pUITex[1]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::UIDraw();

			// 黒い奴
			world = DirectX::XMMatrixTranslation(525.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_End, m_SelectSize_End));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 0.3f));
			Sprite::SetTexture(m_pUITex[8]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			SetBlendMode(OPACITY_BLEND_ALPHA);
			Sprite::UIDraw();
			SetBlendMode(BLEND_ALPHA);
		}

		// 白いやつ（おわる）
		if (m_TitleKind == E_CONTINUE)
		{
			world = DirectX::XMMatrixTranslation(525.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_End + 10.0f, m_SelectSize_End + 10.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_Alpha));
			Sprite::SetTexture(m_pUITex[4]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			SetBlendMode(OPACITY_BLEND_ALPHA);
			Sprite::UIDraw();
			SetBlendMode(BLEND_ALPHA);

			// はじめる
			world = DirectX::XMMatrixTranslation(200.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_Start, m_SelectSize_Start));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pUITex[0]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::UIDraw();

			// つづきから
			world = DirectX::XMMatrixTranslation(525.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_End, m_SelectSize_End));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pUITex[1]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::UIDraw();

			// 黒い奴
			world = DirectX::XMMatrixTranslation(200.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_Start, m_SelectSize_Start));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 0.3f));
			Sprite::SetTexture(m_pUITex[7]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			SetBlendMode(OPACITY_BLEND_ALPHA);
			Sprite::UIDraw();
			SetBlendMode(BLEND_ALPHA);
		}
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(m_CursorPosX, m_CursorPosY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_CursorSize, m_CursorSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pUITex[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// Aを押してスタート
	world = DirectX::XMMatrixTranslation(350.0f, 55.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(300.0f, 300.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_Alpha));
	Sprite::SetTexture(m_pUITex[6]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	SetBlendMode(OPACITY_BLEND_ALPHA);
	Sprite::UIDraw();
	SetBlendMode(BLEND_ALPHA);
}
