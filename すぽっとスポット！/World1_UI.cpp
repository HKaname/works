//==============================================================
//
//  �t�@�C�����FWorld1_UI.cpp
//
//	�T�v�F
//	�X�e�[�W�Z���N�g��ʂł�UI�̕`��y�эX�V���s��
//
//==============================================================

// �C���N���[�h��
#include "World1_UI.h"
#include "Main.h"
#include "SceneStageSelect.h"

//==============================================================
//�@�֐����FWorld1_UI::World1_UI()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FWorld1_UI�N���X�̃R���X�g���N�^	
//==============================================================
World1_UI::World1_UI()
	: m_StageNamePos(-300.0f),
	  m_StageSelectPos(-350.0f),
	  m_PlayerCursorPos{590.0f,325.0f,175.0f,760.0f,615.0f,565.0f,425.0f,750.0f,900.0f,490.0f},
	  m_ButtonSize(75.0f),
	  m_pPopUpSize(0.0f)
{
	//---- �e�N�X�`���N���X�̊m�� ----
	for (int i = 0; i < W1_MAX_UI_TEX; i++)
	{
		m_pTexture[i] = new Texture();
	}

	//---- �e�N�X�`���̓ǂݍ��� ----
	// �X�e�[�W�Z���N�g
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Select/UI_StageSelect_StageSelect_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_StageSelect_001.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �͂��܂�̂�����
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Select/UI_StageSelect_Stagename_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Stagename_001.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �߂�{�^��
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Select/UI_StageSelect_Back_003.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Back.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �X�e�[�W
	// 1-1
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Select/Stage01/1-1.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_1).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// 1-2
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Select/Stage01/1-2.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_2).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// 1-3
	if (FAILED(m_pTexture[5]->Create("Assets/Texture/UI/Select/Stage01/1-3.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_3).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// 1-4
	if (FAILED(m_pTexture[6]->Create("Assets/Texture/UI/Select/Stage01/1-4.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_4).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// 1-5
	if (FAILED(m_pTexture[7]->Create("Assets/Texture/UI/Select/Stage01/1-5.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �N���A
	if (FAILED(m_pTexture[8]->Create("Assets/Texture/UI/Select/UI_StageSelect_ClearIcon_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_ClearIcon_002.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// ���̃X�e�[�W�������J�[�\��
	if (FAILED(m_pTexture[9]->Create("Assets/Texture/UI/Select/UI_Title_Select.png")))
	{
		MessageBox(NULL, "UI_Title_Select.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// A�{�^��
	m_pButtonTex = new Texture();
	if (FAILED(m_pButtonTex->Create("Assets/Texture/UI/Select/UI_common_ButtonA_003.png")))
	{
		MessageBox(NULL, "m_pButtonTex���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �C�[�W���O�N���X�̊m��
	m_pEasing = new Easing();
	m_pPopUpEase = new Easing();

	// �A�j���[�V�����N���X�̊m��
	m_pAnim = new CAnim();
}

//==============================================================
//�@�֐����FWorld1_UI::~World1_UI()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FWorld1_UI�N���X�̃f�X�g���N�^
//==============================================================
World1_UI::~World1_UI()
{
	// �e�N�X�`���̊J��
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

	// �C�[�W���O�N���X�̊J��
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

	// �A�j���[�V�����N���X�̊J��
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
//�@�֐����FWorld1_UI::Draw_clear()
//	�����P�Ffloat PosX(�`��ʒu���R)
//	�߂�l�Ffloat PosY(�`��ʒu�^�e)
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̃N���A��UI�̕`��
//==============================================================
void World1_UI::Draw_clear(float PosX, float PosY)
{
	// �N���A
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(PosX, PosY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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
//�@�֐����FWorld1_UI::Draw_NextStageCursor()
//	�����P�Ffloat PosX(�`��ʒu���R)
//	�߂�l�Ffloat PosY(�`��ʒu�^�e)
//
//	�T�@�v�F���̃X�e�[�W������UI�̕`��
//==============================================================
void World1_UI::Draw_NextCursor(int SelectStage, bool EX)
{
	DirectX::XMFLOAT4X4 mat[3];
	DirectX::XMMATRIX world;
	DirectX::XMMATRIX Mr;

	// ���[���h�s��̌v��
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
		// ��
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
//�@�֐����FWorld1_UI::Draw_Other()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̃X�e�[�W���Ȃǂ�UI�̕`��
//==============================================================
void World1_UI::Draw_Other()
{
	//---- �Q�[����UI ----
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_StageSelectPos, 680.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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

	// �X�e�[�W��
	world = DirectX::XMMatrixTranslation(m_StageNamePos, 590.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(400.0f, 400.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[1]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �߂�{�^��
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
//�@�֐����FWorld1_UI::Move_PlayerCursor1()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�P��UI�̃A�j���[�V��������
//==============================================================
void World1_UI::Move_PlayerCursor1()
{
	m_PlayerCursorPos[0] = m_pAnim->Animation_Move(590.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[9] = m_pAnim->Animation_Move(430.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f,300.0f,0.04f,true);
}

//==============================================================
//�@�֐����FWorld1_UI::Move_PlayerCursor2()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�Q��UI�̃A�j���[�V��������
//==============================================================
void World1_UI::Move_PlayerCursor2()
{
	m_PlayerCursorPos[1] = m_pAnim->Animation_Move(325.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[2] = m_pAnim->Animation_Move(175.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld1_UI::Move_PlayerCursor3()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�R��UI�̃A�j���[�V��������
//==============================================================
void World1_UI::Move_PlayerCursor3()
{
	m_PlayerCursorPos[3] = m_pAnim->Animation_Move(760.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[4] = m_pAnim->Animation_Move(615.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld1_UI::Move_PlayerCursor4()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�S��UI�̃A�j���[�V��������
//==============================================================
void World1_UI::Move_PlayerCursor4()
{
	m_PlayerCursorPos[5] = m_pAnim->Animation_Move(565.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[6] = m_pAnim->Animation_Move(425.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld1_UI::Move_PlayerCursor5()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�T��UI�̃A�j���[�V��������
//==============================================================
void World1_UI::Move_PlayerCursor5()
{
	m_PlayerCursorPos[7] = m_pAnim->Animation_Move(750.0f, 120.0f, 5.0f);

	m_PlayerCursorPos[8] = m_pAnim->Animation_Move(910.0f, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_pPopUpSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld1_UI::Draw_Stage1()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�P��UI�̕`��
//==============================================================
void World1_UI::Draw_Stage1()
{
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(710.0f, 250.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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
		// A�{�^��
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
//�@�֐����FWorld1_UI::Draw_Stage2()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�Q��UI�̕`��
//==============================================================
void World1_UI::Draw_Stage2()
{
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(780.0f, 125.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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

	// A�{�^��
	world = DirectX::XMMatrixTranslation(900.0f, 65.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// ��
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
//�@�֐����FWorld1_UI::Draw_Stage3()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�R��UI�̕`��
//==============================================================
void World1_UI::Draw_Stage3()
{
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(690.0f, 510.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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

	// A�{�^��
	world = DirectX::XMMatrixTranslation(805.0f, 452.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	//---- �v���C���[����ɏo��J�[�\��
	// �E
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
//�@�֐����FWorld1_UI::Draw_Stage4()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�S��UI�̕`��
//==============================================================
void World1_UI::Draw_Stage4()
{
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(220.0f, 440.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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

	// A�{�^��
	world = DirectX::XMMatrixTranslation(335.0f, 382.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// ��
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
//�@�֐����FWorld1_UI::Draw_Stage5()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�T��UI�̕`��
//==============================================================
void World1_UI::Draw_Stage5()
{
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(820.0f, 460.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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

	// A�{�^��
	world = DirectX::XMMatrixTranslation(935.0f, 402.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �v���C���[�̍����ɏo��J�[�\��
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
