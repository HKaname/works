//==============================================================
//
//ファイル名：Tutorial.cpp
//
//制作者：幡手要
//
//概要：チュートリアルの描画及び移動
//==============================================================

// インクルード部
#include "Tutorial.h"

// コンストラクタ
Tutorial::Tutorial()
	: m_PrincessPos(-500.0f),
	  m_BubblePos(-500.0f),
	  m_AnimDelay(0),
	  m_ButtonSize(90.0f)
{
	//---- テクスチャクラスの確保 ----
	for (int i = 0; i < MAX_TUTORIAL_TEX; i++)
	{
		m_pTexture[i] = new Texture();
	}

	for (int i = 0; i < 9; i++)
	{
		m_pWordsTex[i] = new Texture();
		m_pPrincessTex[i] = new Texture();
	}

	//---- テクスチャの読み込み ----
	//----- ヒメ -----
	// 腕上げ（目あき）
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king03.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}
	// 腕上げ（目閉じ）
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king01.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king01が読み込めませんでした", "Error", MB_OK);
	}
	// 腕下げ（目あき）
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king04.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king04が読み込めませんでした", "Error", MB_OK);
	}
	// 腕下げ（目閉じ）
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king02.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king02が読み込めませんでした", "Error", MB_OK);
	}
	// 腕組み（目あき）
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_uzai.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king_uzaiが読み込めませんでした", "Error", MB_OK);
	}
	// 腕組み（目閉じ）
	if (FAILED(m_pTexture[5]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_happy.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king_happyが読み込めませんでした", "Error", MB_OK);
	}

	//---- ヒメ（冬衣装）----
	// 待機（通常）
	if (FAILED(m_pPrincessTex[0]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king06.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}
	// 待機（笑顔）
	if (FAILED(m_pPrincessTex[1]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king05.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}
	// 待機（うざかお）
	if (FAILED(m_pPrincessTex[2]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_uzai03.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}
	// 腕上げ（通常）
	if (FAILED(m_pPrincessTex[3]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king03.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}
	// 腕上げ（笑顔）
	if (FAILED(m_pPrincessTex[4]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king01.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}
	// 腕上げ（うざかお）
	if (FAILED(m_pPrincessTex[5]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_uzai01.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}
	// 腕下げ（通常）
	if (FAILED(m_pPrincessTex[6]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king04.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}
	// 腕下げ（笑顔）
	if (FAILED(m_pPrincessTex[7]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king02.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}
	// 腕下げ（うざかお）
	if (FAILED(m_pPrincessTex[8]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_uzai02.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03が読み込めませんでした", "Error", MB_OK);
	}

	//----- 棒 -----
	// 長い方
	if (FAILED(m_pTexture[6]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_stick_rong.png")))
	{
		MessageBox(NULL, "UI_tutorial_stick_rongが読み込めませんでした", "Error", MB_OK);
	}
	// 短い方
	if (FAILED(m_pTexture[7]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_stick_short.png")))
	{
		MessageBox(NULL, "UI_tutorial_stick_shortが読み込めませんでした", "Error", MB_OK);
	}

	//----- その他 -----
	// 吹き出し
	if (FAILED(m_pTexture[8]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_balloon06.png")))
	{
		MessageBox(NULL, "UI_tutorial_balloon06が読み込めませんでした", "Error", MB_OK);
	}
	// Aボタン
	if (FAILED(m_pTexture[9]->Create("Assets/Texture/UI/Tutorial/UI_common_ButtonA_003.png")))
	{
		MessageBox(NULL, "UI_common_ButtonA_003が読み込めませんでした", "Error", MB_OK);
	}

	// ステージごとに異なる素材
	//----- セリフ -----
	// セリフ１（１－１）
	if (FAILED(m_pTexture[10]->Create("Assets/Texture/UI/Tutorial/1-1/Word01.png")))
	{
		MessageBox(NULL, "Word01が読み込めませんでした", "Error", MB_OK);
	}
	// セリフ２（１－１）
	if (FAILED(m_pTexture[11]->Create("Assets/Texture/UI/Tutorial/1-1/Word02.png")))
	{
		MessageBox(NULL, "Word02が読み込めませんでした", "Error", MB_OK);
	}
	// セリフ３（１－１）
	if (FAILED(m_pTexture[12]->Create("Assets/Texture/UI/Tutorial/1-1/Word03.png")))
	{
		MessageBox(NULL, "Word03が読み込めませんでした", "Error", MB_OK);
	}
	// セリフ４（１－１）
	if (FAILED(m_pTexture[13]->Create("Assets/Texture/UI/Tutorial/1-1/Word04.png")))
	{
		MessageBox(NULL, "Word04が読み込めませんでした", "Error", MB_OK);
	}

	// セリフ１（１－２）
	if (FAILED(m_pTexture[14]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_01.png")))
	{
		MessageBox(NULL, "UI_Word1-2_01.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ２（１－２）
	if (FAILED(m_pTexture[15]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_02.png")))
	{
		MessageBox(NULL, "UI_Word1-2_02.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ３（１－２）
	if (FAILED(m_pTexture[16]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_03.png")))
	{
		MessageBox(NULL, "UI_Word1-2_03.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ４（１－２）
	if (FAILED(m_pTexture[17]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_04.png")))
	{
		MessageBox(NULL, "UI_Word1-2_04.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ５（１－２）
	if (FAILED(m_pTexture[18]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_05.png")))
	{
		MessageBox(NULL, "UI_Word1-2_05.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ６（１－２）
	if (FAILED(m_pTexture[19]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_06.png")))
	{
		MessageBox(NULL, "UI_Word1-2_06.pngが読み込めませんでした", "Error", MB_OK);
	}

	// セリフ１（３－１）
	if (FAILED(m_pWordsTex[0]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_01.png")))
	{
		MessageBox(NULL, "UI_Word3-1_01.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ２（３－１）
	if (FAILED(m_pWordsTex[1]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_02.png")))
	{
		MessageBox(NULL, "UI_Word3-1_02.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ３（３－１）
	if (FAILED(m_pWordsTex[2]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_03.png")))
	{
		MessageBox(NULL, "UI_Word3-1_03.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ４（３－１）
	if (FAILED(m_pWordsTex[3]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_04.png")))
	{
		MessageBox(NULL, "UI_Word3-1_04.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ５（３－１）
	if (FAILED(m_pWordsTex[4]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_05.png")))
	{
		MessageBox(NULL, "UI_Word3-1_05.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ６（３－１）
	if (FAILED(m_pWordsTex[5]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_06.png")))
	{
		MessageBox(NULL, "UI_Word3-1_06.pngが読み込めませんでした", "Error", MB_OK);
	}

	// セリフ１（４－１）
	if (FAILED(m_pWordsTex[6]->Create("Assets/Texture/UI/Tutorial/4-1/UI_Word_4-1_01.png")))
	{
		MessageBox(NULL, "UI_Word4-1_01.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ２（４－１）
	if (FAILED(m_pWordsTex[7]->Create("Assets/Texture/UI/Tutorial/4-1/UI_Word_4-1_02.png")))
	{
		MessageBox(NULL, "UI_Word4-1_02.pngが読み込めませんでした", "Error", MB_OK);
	}
	// セリフ３（４－１）
	if (FAILED(m_pWordsTex[8]->Create("Assets/Texture/UI/Tutorial/4-1/UI_Word_4-1_03.png")))
	{
		MessageBox(NULL, "UI_Word4-1_03.pngが読み込めませんでした", "Error", MB_OK);
	}

	// イージングクラスの確保
	m_pEasing = new Easing();
	m_pEasing->ResetChangePowPlay();

	// アニメーションクラスの確保
	m_pAnim = new CAnim();
}

// デストラクタ
Tutorial::~Tutorial()
{
	// テクスチャの開放
	if (m_pTexture)
	{
		for (int i = 0; i < MAX_TUTORIAL_TEX; i++)
		{
			delete m_pTexture[i];
			m_pTexture[i] = nullptr;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (m_pWordsTex[i])
		{
			delete m_pWordsTex[i];
			m_pWordsTex[i] = nullptr;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (m_pPrincessTex[i])
		{
			delete m_pPrincessTex[i];
			m_pPrincessTex[i] = nullptr;
		}
	}

	if (m_pEasing)
	{
		delete m_pEasing;
		m_pEasing = nullptr;
	}

	if (m_pAnim)
	{
		delete m_pAnim;
		m_pAnim = nullptr;
	}
}

bool Tutorial::GetIsPlayEase()
{
	return m_pEasing->GetIsPlay();
}

void Tutorial::ButtonAnim()
{
	m_ButtonSize = m_pAnim->Animation_Scale(60.0f, 10.0f, 90.0f);
}

void Tutorial::InTutorial()
{
	m_PrincessPos = m_pEasing->MoveEaseOutBack(-500.0f, 195.0f, 0.02f, true);

	m_BubblePos = m_pEasing->MoveEaseOutBack(-500.0f, 295.0f, 0.02f, true);

	m_pEasing->ResetChangePowRevarse();
}

void Tutorial::OutTutorial()
{
	m_PrincessPos = m_pEasing->MoveEaseOutBack(-500.0f, 195.0f, 0.02f, false);

	m_BubblePos = m_pEasing->MoveEaseOutBack(-500.0f, 295.0f, 0.02f, false);

	m_pEasing->ResetChangePowPlay();
}

void Tutorial::InMessageBox()
{
	m_BubblePos = m_pEasing->MoveEaseOutBack(-500.0f, 295.0f, 0.03f, true);

	m_pEasing->ResetChangePowRevarse();
}

void Tutorial::OutMessageBox()
{
	m_BubblePos = m_pEasing->MoveEaseOutBack(-500.0f, 295.0f, 0.04f, false);

	m_pEasing->ResetChangePowPlay();
}

void Tutorial::Princess_Standby(int princesskind)
{
	if (princesskind == Normal)
	{
		//---- チュートリアルUI ----
		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();
	}

	if (princesskind == Winter)
	{
		//---- チュートリアルUI ----
		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();
	}
}

void Tutorial::Draw_Step1_1()
{
	//---- チュートリアルUI ----
	// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// 棒
	world = DirectX::XMMatrixTranslation(775.0f, m_PrincessPos, 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(20.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(325.0f, 325.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[6]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, 101.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[10]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

void Tutorial::Draw_Step2_1()
{
	//---- チュートリアルUI ----
	// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, 295.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// 棒
	world = DirectX::XMMatrixTranslation(875.0f, 275.0f, 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-10.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(325.0f, 325.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[7]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, 195.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[1]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, 125.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[11]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

void Tutorial::Draw_Step3_1()
{
	//---- チュートリアルUI ----
	// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// 棒
	world = DirectX::XMMatrixTranslation(810.0f, 215.0f, 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(10.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(325.0f, 325.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[7]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, 195.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, 125.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[12]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

void Tutorial::Draw_Step4_1()
{
	//---- チュートリアルUI ----
	// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// 棒
	world = DirectX::XMMatrixTranslation(865.0f, m_PrincessPos + 85.0f, 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-10.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(325.0f, 325.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[7]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[1]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, 120.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[13]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

//----- １ー２チュートリアル -----
void Tutorial::Draw_Step1_2()
{
	//---- チュートリアルUI ----
	// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// 棒
	world = DirectX::XMMatrixTranslation(750.0f, m_PrincessPos + 20.0f, 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(17.5f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[6]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[3]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 220.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(800.0f, 800.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[14]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

void Tutorial::Draw_Step2_2()
{
	//---- チュートリアルUI ----
	// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[4]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, 80.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[15]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

void Tutorial::Draw_Step3_2()
{
	//---- チュートリアルUI ----
	// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// 棒
	world = DirectX::XMMatrixTranslation(825.0f, 175.0f, 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(18.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[7]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[3]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, 90.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[16]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

void Tutorial::Draw_Step4_2()
{
	//---- チュートリアルUI ----
// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// 棒
	world = DirectX::XMMatrixTranslation(750.0f, 195.0f, 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(25.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[6]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, 90.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[17]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

void Tutorial::Draw_Step5_2()
{
	//---- チュートリアルUI ----
	// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[4]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, 115.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[18]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

void Tutorial::Draw_Step6_2()
{
	//---- チュートリアルUI ----
	// 吹き出し
	DirectX::XMFLOAT4X4 mat[3];

	// ワールド行列の計量
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// ビュー座標
	mat[1] = m_pCamera->GetViewMatrix2D();

	// プロジェクション座標
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// 棒
	world = DirectX::XMMatrixTranslation(885.0f, m_PrincessPos + 130.0f, 0.0f);
	DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-20.0f));
	world = Mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(325.0f, 325.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[6]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// ヒメ
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[0]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// セリフ
	world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 220.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[19]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}

	// Aボタン
	world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[9]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
	{
		Sprite::UIDraw();
	}
}

void Tutorial::Draw_Tutorial_3(int TutoStep)
{
	if (TutoStep == TUTO_Step1)
	{
		//---- チュートリアルUI ----

		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[1]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セリフ
		world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 220.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pWordsTex[0]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}

		// Aボタン
		world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}
	}

	if (TutoStep == TUTO_Step2)
	{
		//---- チュートリアルUI ----

		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[0]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セリフ
		world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 220.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pWordsTex[1]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}

		// Aボタン
		world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}
	}

	if (TutoStep == TUTO_Step3)
	{
		//---- チュートリアルUI ----

		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セリフ
		world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 220.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pWordsTex[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}

		// Aボタン
		world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}
	}

	if (TutoStep == TUTO_Step4)
	{
		//---- チュートリアルUI ----

		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// 棒
		world = DirectX::XMMatrixTranslation(870.0f, m_PrincessPos + 130.0f, 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-20.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(325.0f, 325.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[6]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[3]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セリフ
		world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 220.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pWordsTex[3]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}

		// Aボタン
		world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}
	}

	if (TutoStep == TUTO_Step5)
	{
		//---- チュートリアルUI ----

		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// 棒
		world = DirectX::XMMatrixTranslation(870.0f, m_PrincessPos + 130.0f, 0.0f);
		DirectX::XMMATRIX Mr = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(-20.0f));
		world = Mr * world;
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(325.0f, 325.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[6]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セリフ
		world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 120.0f, m_BubblePos - 230.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(1000.0f, 1000.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pWordsTex[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}

		// Aボタン
		world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}
	}

	if (TutoStep == TUTO_Step6)
	{
		//---- チュートリアルUI ----

		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セリフ
		world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 195.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pWordsTex[5]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}

		// Aボタン
		world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}
	}
}

void Tutorial::Draw_Tutorial_4(int TutoStep)
{
	if (TutoStep == TUTO_Step1)
	{
		//---- チュートリアルUI ----

		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セリフ
		world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 220.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pWordsTex[6]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}

		// Aボタン
		world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}
	}

	if (TutoStep == TUTO_Step2)
	{
		//---- チュートリアルUI ----

		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[5]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セリフ
		world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 220.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(900.0f, 900.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pWordsTex[7]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}

		// Aボタン
		world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}
	}

	if (TutoStep == TUTO_Step3)
	{
		//---- チュートリアルUI ----

		// 吹き出し
		DirectX::XMFLOAT4X4 mat[3];

		// ワールド行列の計量
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// ビュー座標
		mat[1] = m_pCamera->GetViewMatrix2D();

		// プロジェクション座標
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// ヒメ
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// セリフ
		world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2 - 100.0f, m_BubblePos - 180.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(750.0f, 750.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pWordsTex[8]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}

		// Aボタン
		world = DirectX::XMMatrixTranslation(1210, 50.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[9]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		if (m_BubblePos >= 295.0f && m_BubblePos < 297.0f)
		{
			Sprite::UIDraw();
		}
	}
}
