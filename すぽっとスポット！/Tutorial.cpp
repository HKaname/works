//==============================================================
//
//�t�@�C�����FTutorial.cpp
//
//����ҁF����v
//
//�T�v�F�`���[�g���A���̕`��y�шړ�
//==============================================================

// �C���N���[�h��
#include "Tutorial.h"

// �R���X�g���N�^
Tutorial::Tutorial()
	: m_PrincessPos(-500.0f),
	  m_BubblePos(-500.0f),
	  m_AnimDelay(0),
	  m_ButtonSize(90.0f)
{
	//---- �e�N�X�`���N���X�̊m�� ----
	for (int i = 0; i < MAX_TUTORIAL_TEX; i++)
	{
		m_pTexture[i] = new Texture();
	}

	for (int i = 0; i < 9; i++)
	{
		m_pWordsTex[i] = new Texture();
		m_pPrincessTex[i] = new Texture();
	}

	//---- �e�N�X�`���̓ǂݍ��� ----
	//----- �q�� -----
	// �r�グ�i�ڂ����j
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king03.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�グ�i�ڕ��j
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king01.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king01���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�����i�ڂ����j
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king04.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king04���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�����i�ڕ��j
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king02.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king02���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�g�݁i�ڂ����j
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_uzai.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king_uzai���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�g�݁i�ڕ��j
	if (FAILED(m_pTexture[5]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_happy.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king_happy���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	//---- �q���i�~�ߑ��j----
	// �ҋ@�i�ʏ�j
	if (FAILED(m_pPrincessTex[0]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king06.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �ҋ@�i�Ί�j
	if (FAILED(m_pPrincessTex[1]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king05.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �ҋ@�i���������j
	if (FAILED(m_pPrincessTex[2]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_uzai03.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�グ�i�ʏ�j
	if (FAILED(m_pPrincessTex[3]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king03.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�グ�i�Ί�j
	if (FAILED(m_pPrincessTex[4]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king01.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�グ�i���������j
	if (FAILED(m_pPrincessTex[5]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_uzai01.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�����i�ʏ�j
	if (FAILED(m_pPrincessTex[6]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king04.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�����i�Ί�j
	if (FAILED(m_pPrincessTex[7]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_winter_king02.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �r�����i���������j
	if (FAILED(m_pPrincessTex[8]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_king_uzai02.PNG")))
	{
		MessageBox(NULL, "UI_tutorial_king03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	//----- �_ -----
	// ������
	if (FAILED(m_pTexture[6]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_stick_rong.png")))
	{
		MessageBox(NULL, "UI_tutorial_stick_rong���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z����
	if (FAILED(m_pTexture[7]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_stick_short.png")))
	{
		MessageBox(NULL, "UI_tutorial_stick_short���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	//----- ���̑� -----
	// �����o��
	if (FAILED(m_pTexture[8]->Create("Assets/Texture/UI/Tutorial/UI_tutorial_balloon06.png")))
	{
		MessageBox(NULL, "UI_tutorial_balloon06���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// A�{�^��
	if (FAILED(m_pTexture[9]->Create("Assets/Texture/UI/Tutorial/UI_common_ButtonA_003.png")))
	{
		MessageBox(NULL, "UI_common_ButtonA_003���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �X�e�[�W���ƂɈقȂ�f��
	//----- �Z���t -----
	// �Z���t�P�i�P�|�P�j
	if (FAILED(m_pTexture[10]->Create("Assets/Texture/UI/Tutorial/1-1/Word01.png")))
	{
		MessageBox(NULL, "Word01���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�Q�i�P�|�P�j
	if (FAILED(m_pTexture[11]->Create("Assets/Texture/UI/Tutorial/1-1/Word02.png")))
	{
		MessageBox(NULL, "Word02���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�R�i�P�|�P�j
	if (FAILED(m_pTexture[12]->Create("Assets/Texture/UI/Tutorial/1-1/Word03.png")))
	{
		MessageBox(NULL, "Word03���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�S�i�P�|�P�j
	if (FAILED(m_pTexture[13]->Create("Assets/Texture/UI/Tutorial/1-1/Word04.png")))
	{
		MessageBox(NULL, "Word04���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �Z���t�P�i�P�|�Q�j
	if (FAILED(m_pTexture[14]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_01.png")))
	{
		MessageBox(NULL, "UI_Word1-2_01.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�Q�i�P�|�Q�j
	if (FAILED(m_pTexture[15]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_02.png")))
	{
		MessageBox(NULL, "UI_Word1-2_02.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�R�i�P�|�Q�j
	if (FAILED(m_pTexture[16]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_03.png")))
	{
		MessageBox(NULL, "UI_Word1-2_03.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�S�i�P�|�Q�j
	if (FAILED(m_pTexture[17]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_04.png")))
	{
		MessageBox(NULL, "UI_Word1-2_04.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�T�i�P�|�Q�j
	if (FAILED(m_pTexture[18]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_05.png")))
	{
		MessageBox(NULL, "UI_Word1-2_05.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�U�i�P�|�Q�j
	if (FAILED(m_pTexture[19]->Create("Assets/Texture/UI/Tutorial/1-2/UI_Word1-2_06.png")))
	{
		MessageBox(NULL, "UI_Word1-2_06.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �Z���t�P�i�R�|�P�j
	if (FAILED(m_pWordsTex[0]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_01.png")))
	{
		MessageBox(NULL, "UI_Word3-1_01.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�Q�i�R�|�P�j
	if (FAILED(m_pWordsTex[1]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_02.png")))
	{
		MessageBox(NULL, "UI_Word3-1_02.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�R�i�R�|�P�j
	if (FAILED(m_pWordsTex[2]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_03.png")))
	{
		MessageBox(NULL, "UI_Word3-1_03.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�S�i�R�|�P�j
	if (FAILED(m_pWordsTex[3]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_04.png")))
	{
		MessageBox(NULL, "UI_Word3-1_04.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�T�i�R�|�P�j
	if (FAILED(m_pWordsTex[4]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_05.png")))
	{
		MessageBox(NULL, "UI_Word3-1_05.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�U�i�R�|�P�j
	if (FAILED(m_pWordsTex[5]->Create("Assets/Texture/UI/Tutorial/3-1/UI_Word_3-1_06.png")))
	{
		MessageBox(NULL, "UI_Word3-1_06.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �Z���t�P�i�S�|�P�j
	if (FAILED(m_pWordsTex[6]->Create("Assets/Texture/UI/Tutorial/4-1/UI_Word_4-1_01.png")))
	{
		MessageBox(NULL, "UI_Word4-1_01.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�Q�i�S�|�P�j
	if (FAILED(m_pWordsTex[7]->Create("Assets/Texture/UI/Tutorial/4-1/UI_Word_4-1_02.png")))
	{
		MessageBox(NULL, "UI_Word4-1_02.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���t�R�i�S�|�P�j
	if (FAILED(m_pWordsTex[8]->Create("Assets/Texture/UI/Tutorial/4-1/UI_Word_4-1_03.png")))
	{
		MessageBox(NULL, "UI_Word4-1_03.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �C�[�W���O�N���X�̊m��
	m_pEasing = new Easing();
	m_pEasing->ResetChangePowPlay();

	// �A�j���[�V�����N���X�̊m��
	m_pAnim = new CAnim();
}

// �f�X�g���N�^
Tutorial::~Tutorial()
{
	// �e�N�X�`���̊J��
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
		//---- �`���[�g���A��UI ----
		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �q��
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
		//---- �`���[�g���A��UI ----
		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �q��
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
	//---- �`���[�g���A��UI ----
	// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �_
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

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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
	//---- �`���[�g���A��UI ----
	// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, 295.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �_
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

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, 195.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[1]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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
	//---- �`���[�g���A��UI ----
	// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �_
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

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, 195.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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
	//---- �`���[�g���A��UI ----
	// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �_
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

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[1]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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

//----- �P�[�Q�`���[�g���A�� -----
void Tutorial::Draw_Step1_2()
{
	//---- �`���[�g���A��UI ----
	// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �_
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

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[3]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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
	//---- �`���[�g���A��UI ----
	// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[4]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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
	//---- �`���[�g���A��UI ----
	// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �_
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

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[3]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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
	//---- �`���[�g���A��UI ----
// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �_
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

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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
	//---- �`���[�g���A��UI ----
	// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[4]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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
	//---- �`���[�g���A��UI ----
	// �����o��
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::UIDraw();

	// �_
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

	// �q��
	world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[0]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �Z���t
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

	// A�{�^��
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
		//---- �`���[�g���A��UI ----

		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �q��
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[1]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���t
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

		// A�{�^��
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
		//---- �`���[�g���A��UI ----

		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �q��
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[0]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���t
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

		// A�{�^��
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
		//---- �`���[�g���A��UI ----

		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �q��
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���t
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

		// A�{�^��
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
		//---- �`���[�g���A��UI ----

		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �_
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

		// �q��
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[3]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���t
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

		// A�{�^��
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
		//---- �`���[�g���A��UI ----

		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �_
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

		// �q��
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���t
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

		// A�{�^��
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
		//---- �`���[�g���A��UI ----

		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �q��
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pPrincessTex[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���t
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

		// A�{�^��
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
		//---- �`���[�g���A��UI ----

		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �q��
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���t
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

		// A�{�^��
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
		//---- �`���[�g���A��UI ----

		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �q��
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[5]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���t
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

		// A�{�^��
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
		//---- �`���[�g���A��UI ----

		// �����o��
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�s��̌v��
		DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, m_BubblePos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		// �r���[���W
		mat[1] = m_pCamera->GetViewMatrix2D();

		// �v���W�F�N�V�������W
		mat[2] = m_pCamera->GetProjectionMatrix2D();

		Sprite::SetWorld(mat[0]);
		Sprite::SetView(mat[1]);
		Sprite::SetProjection(mat[2]);
		Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_WIDTH / 2));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[8]);
		Sprite::UIDraw();

		// �q��
		world = DirectX::XMMatrixTranslation(1100.0f, m_PrincessPos, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���t
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

		// A�{�^��
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
