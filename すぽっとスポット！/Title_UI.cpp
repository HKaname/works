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

	// �^�C�g�����S
	m_pTitleTex = new Texture();
	if (FAILED(!m_pTitleTex->Create("Assets/Texture/UI/Title/title.png")))
	{
		MessageBox(NULL, "title.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �͂��߂�
	if (FAILED(!m_pUITex[0]->Create("Assets/Texture/UI/Title/UI_Title_Start.png")))
	{
		MessageBox(NULL, "UI_Title_Start���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// ��������
	if (FAILED(!m_pUITex[1]->Create("Assets/Texture/UI/Title/UI_Title_continued.png")))
	{
		MessageBox(NULL, "UI_Title_End���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// A�{�^��
	if (FAILED(!m_pUITex[2]->Create("Assets/Texture/UI/Title/UI_Title_Select.png")))
	{
		MessageBox(NULL, "UI_Title_A���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// ������i�n�܂鑤�j
	if (FAILED(!m_pUITex[3]->Create("Assets/Texture/UI/Title/UI_Title_Start_flash.png")))
	{
		MessageBox(NULL, "UI_Title_Start_flash���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// ������i�����鑤�j
	if (FAILED(!m_pUITex[4]->Create("Assets/Texture/UI/Title/UI_Title_continued_flash.png")))
	{
		MessageBox(NULL, "UI_Title_End_flash���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �{�^���i���F�j
	if (FAILED(!m_pUITex[5]->Create("Assets/Texture/UI/Title/UI_common_ButtonBlack_002.png")))
	{
		MessageBox(NULL, "UI_common_ButtonBlack_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// A�������ăX�^�[�g
	if (FAILED(!m_pUITex[6]->Create("Assets/Texture/UI/Title/UI_Title_Push_002.png")))
	{
		MessageBox(NULL, "m_pUITex[6]���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// ������i�n�܂鑤�j
	if (FAILED(!m_pUITex[7]->Create("Assets/Texture/UI/Title/UI_Title_Start_black.png")))
	{
		MessageBox(NULL, "UI_Title_Start_flash���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// ������i�����鑤�j
	if (FAILED(!m_pUITex[8]->Create("Assets/Texture/UI/Title/UI_Title_continued_black.png")))
	{
		MessageBox(NULL, "UI_Title_End_flash���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	m_pAnim = new CAnim();

	// �A�j���[�V�����̐ݒ�
	AnimData Title_AnimData;

	Title_AnimData.nAnimeFrame = TITLE_ANIM_FRAME;
	Title_AnimData.nAnimeSplitX = TITLE_ANIME_SPLIT_X;
	Title_AnimData.nAnimeSplitY = TITLE_ANIME_SPLIT_Y;
	Title_AnimData.nEndAnimNo = TITLE_ANIME_END;

	m_pAnim->SetAnime(Title_AnimData);

	//�T�E���h�f�[�^�ǂݍ���
	//SE
	m_pSEJump = LoadSound("Assets/SE/TitleScene_Logo_SE.wav");//�W�����v
	m_pSEButton = LoadSound("Assets/SE/TitleScene_Buttom_SE.wav");	//�{�^��
	m_pSEMoveCursor = LoadSound("Assets/SE/supotto_UI_Move.wav");	//���j���[�ړ���
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
			//SE�Đ�
			if (m_pSEMoveCursorSpeaker) {
				m_pSEMoveCursorSpeaker->DestroyVoice();
				m_pSEMoveCursorSpeaker = nullptr;
			}
			m_pSEMoveCursorSpeaker = PlaySound(m_pSEMoveCursor);//SE�Đ�
		}
		else if (GetIsSaveData() && (m_TitleKind == E_START && IsKeyTrigger('D') ||
			m_TitleKind == E_START && IsButtonTrigger(BUTTON_RIGHT) ||
			m_TitleKind == E_START && IsButtonTrigger(STICK_RIGHT)))
		{
			m_TitleKind++;
			m_CursorPosX = 385.0f;
			//SE�Đ�
			if (m_pSEMoveCursorSpeaker) {
				m_pSEMoveCursorSpeaker->DestroyVoice();
				m_pSEMoveCursorSpeaker = nullptr;
			}
			m_pSEMoveCursorSpeaker = PlaySound(m_pSEMoveCursor);//SE�Đ�
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
			m_pSEButtonSpeaker = PlaySound(m_pSEButton);//�{�^��SE�Đ�
			m_pSEButtonSpeaker->SetVolume(0.6f);//����
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

	// �^�C�g���̃A�j���[�V����
	if (m_TitleAnimDelayframe < TITLE_ANIME_END * TITLE_ANIM_FRAME)
		m_UVPos = m_pAnim->TextureAnimation(true);

	if (m_TitleAnimDelayframe > TITLE_ANIME_DELAYFRAME)
	{
		m_TitleAnimDelayframe = 0;
	}

	// �^�C�g�����S�̃W�����vSE
	if (m_pAnim->GetCurrentNo() == 13) {
		//�f�[�^�j��
		if (m_pSEJumpSpeaker) {
			m_pSEJumpSpeaker->DestroyVoice();
			m_pSEJumpSpeaker = nullptr;
		}
		m_pSEJumpSpeaker = PlaySound(m_pSEJump);//�Đ�
	}
}

void Title_UI::Draw()
{
	//---- �Q�[����UI ----
	DirectX::XMFLOAT4X4 mat[3];

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	// ���[���h�s��̌v��
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
		// �����z�i�n�߂�j
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

		// �͂��߂���
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

	if (GetIsSaveData()) // �Z�[�u�f�[�^�����鎞�̂ݕ`��
	{
		if (m_TitleKind == E_START)
		{
			// �����z�i�n�߂�j
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

			// �͂��߂���
			world = DirectX::XMMatrixTranslation(200.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_Start, m_SelectSize_Start));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pUITex[0]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::UIDraw();

			// �Â�����
			world = DirectX::XMMatrixTranslation(525.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_End, m_SelectSize_End));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pUITex[1]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::UIDraw();

			// �����z
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

		// ������i�����j
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

			// �͂��߂�
			world = DirectX::XMMatrixTranslation(200.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_Start, m_SelectSize_Start));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pUITex[0]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::UIDraw();

			// �Â�����
			world = DirectX::XMMatrixTranslation(525.0f, 125.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(m_SelectSize_End, m_SelectSize_End));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pUITex[1]);
			Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
			Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
			Sprite::UIDraw();

			// �����z
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

	// A�{�^��
	world = DirectX::XMMatrixTranslation(m_CursorPosX, m_CursorPosY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_CursorSize, m_CursorSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pUITex[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::UIDraw();

	// A�������ăX�^�[�g
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
