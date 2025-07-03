//==============================================================
//
//  �t�@�C�����FWorld2_UI.cpp
//
//	�T�v�F
//	�X�e�[�W�Z���N�g��ʂł�UI�̕`��y�эX�V���s��
//
//==============================================================

// �C���N���[�h��
#include "World2_UI.h"
#include "Main.h"
#include "SceneStageSelect.h"

//==============================================================
//�@�֐����FWorld2_UI::World2_UI()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FWorld2_UI�N���X�̃R���X�g���N�^	
//==============================================================
World2_UI::World2_UI()
	: m_StageNamePos(-300.0f),
	m_StageSelectPos(-350.0f),
	m_PlayerCursorPos{ MOVECURSOR_POS1,
					   MOVECURSOR_POS2,
					   MOVECURSOR_POS3,
					   MOVECURSOR_POS4,
					   MOVECURSOR_POS5,
					   MOVECURSOR_POS6,
					   MOVECURSOR_POS7,
					   MOVECURSOR_POS8,
					   MOVECURSOR_POS9,
					   MOVECURSOR_POS10,
					   MOVECURSOR_POS11,
					   MOVECURSOR_POS_NEXT },
	m_ButtonSize(75.0f),
	m_fPopupSize(0.0f)
{
	//---- �e�N�X�`���N���X�̊m�� ----
	for (int i = 0; i < W2_MAX_UI_TEX; i++)
	{
		m_pTexture[i] = new Texture();
	}

	for (int i = 0; i < W2_STAGE_TEX; i++)
	{
		m_pStageTex[i] = new Texture();
	}

	//---- �e�N�X�`���̓ǂݍ��� ----
	// �X�e�[�W�Z���N�g
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Select/UI_StageSelect_StageSelect_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_StageSelect_001.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �h�L�h�L�r�[�`
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Select/UI_StageSelect_S2name_001.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Stagename_001.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �߂�{�^��
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Select/UI_StageSelect_Back_003.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Back.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �N���A
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Select/UI_StageSelect_ClearIcon_002.png")))
	{
		MessageBox(NULL, "UI_StageSelect_ClearIcon_002.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ���̃X�e�[�W�������J�[�\��
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Select/UI_Title_Select.png")))
	{
		MessageBox(NULL, "UI_Title_Select.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �X�e�[�W
	// 2-1
	if (FAILED(m_pStageTex[0]->Create("Assets/Texture/UI/Select/Stage02/2-1.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_1).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// 2-2
	if (FAILED(m_pStageTex[1]->Create("Assets/Texture/UI/Select/Stage02/2-2.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_2).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// 2-3
	if (FAILED(m_pStageTex[2]->Create("Assets/Texture/UI/Select/Stage02/2-3.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_3).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// 2-4
	if (FAILED(m_pStageTex[3]->Create("Assets/Texture/UI/Select/Stage02/2-4.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_4).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// 2-5
	if (FAILED(m_pStageTex[4]->Create("Assets/Texture/UI/Select/Stage02/2-5.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// 2-6
	if (FAILED(m_pStageTex[5]->Create("Assets/Texture/UI/Select/Stage02/2-6.png")))
	{
		MessageBox(NULL, "UI_StageSelect_Popup(1_5).png���ǂݍ��߂܂���ł���", "Error", MB_OK);
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
//�@�֐����FWorld2_UI::~World2_UI()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FWorld2_UI�N���X�̃f�X�g���N�^
//==============================================================
World2_UI::~World2_UI()
{
	// �e�N�X�`���̊J��
	if (m_pTexture)
	{
		for (int i = 0; i < W2_MAX_UI_TEX; i++)
		{
			delete m_pTexture[i];
			m_pTexture[i] = nullptr;
		}
	}

	if (m_pStageTex)
	{
		for (int i = 0; i < W2_STAGE_TEX; i++)
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

void World2_UI::In_Other()
{
	m_StageSelectPos = m_pEasing->MoveEaseInOutBack(-350.0f, 225.0f, 0.01f, true);

	m_StageNamePos = m_pEasing->MoveEaseInOutBack(-300.0f, 150.0f, 0.01f, true);
}

void World2_UI::Out_StageName()
{
	m_StageNamePos = m_pEasing->MoveEaseOutBack(-300.0f, 150.0f, 0.02f, false);
}

//==============================================================
//�@�֐����FWorld2_UI::Draw_clear()
//	�����P�Ffloat PosX(�`��ʒu���R)
//	�߂�l�Ffloat PosY(�`��ʒu�^�e)
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̃N���A��UI�̕`��
//==============================================================
void World2_UI::Draw_clear(float PosX, float PosY)
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
	Sprite::SetTexture(m_pTexture[3]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();
}

//==============================================================
//�@�֐����FWorld2_UI::Draw_NextStageCursor()
//	�����P�Fint SelectStage�i���ǂ��ɂ��邩�j
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F���̃X�e�[�W������UI�̕`��
//==============================================================
void World2_UI::Draw_NextCursor(int SelectStage)
{
	DirectX::XMFLOAT4X4 mat[3];
	DirectX::XMMATRIX world;
	DirectX::XMMATRIX Mr;

	// ���[���h�s��̌v��
	switch (SelectStage)
	{
	case STAGE_2_01:
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[0], 490.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_2_02:
		// �E
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[2], 350.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_2_03:
		world = DirectX::XMMatrixTranslation(540.0f, m_PlayerCursorPos[4], 0.0f);
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

	case STAGE_2_04:
		// �E
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[5], 200.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::UIDraw();
		break;

	case STAGE_2_05:
		// ��
		world = DirectX::XMMatrixTranslation(870.0f, m_PlayerCursorPos[7], 0.0f);
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

	case STAGE_2_06:
		world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[11], 350.0f, 0.0f);
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
//�@�֐����FWorld2_UI::Draw_Other()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̃X�e�[�W���Ȃǂ�UI�̕`��
//==============================================================
void World2_UI::Draw_Other()
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

void World2_UI::ResetEase()
{
	m_pPopUpEase->ResetChangePowPlay();
}

//==============================================================
//�@�֐����FWorld2_UI::Move_PlayerCursor1()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂Q�|�P��UI�̃A�j���[�V��������
//==============================================================
void World2_UI::Move_PlayerCursor1()
{
	m_PlayerCursorPos[0] = m_pAnim->Animation_Move(MOVECURSOR_POS1, 120.0f, 5.0f);

	m_PlayerCursorPos[4] = m_pAnim->Animation_Move(MOVECURSOR_POS10, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);

	m_fPopupSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld2_UI::Move_PlayerCursor2()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�Q��UI�̃A�j���[�V��������
//==============================================================
void World2_UI::Move_PlayerCursor2()
{
	m_PlayerCursorPos[1] = m_pAnim->Animation_Move(MOVECURSOR_POS2, 120.0f, 5.0f);

	m_PlayerCursorPos[2] = m_pAnim->Animation_Move(MOVECURSOR_POS3, 120.0f, 5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);
	m_fPopupSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld2_UI::Move_PlayerCursor3()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�R��UI�̃A�j���[�V��������
//==============================================================
void World2_UI::Move_PlayerCursor3()
{
	m_PlayerCursorPos[3] = m_pAnim->Animation_Move(MOVECURSOR_POS4, 120.0f, 5.0f);

	m_PlayerCursorPos[4] = m_pAnim->Animation_Move(MOVECURSOR_POS5, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);
	m_fPopupSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld2_UI::Move_PlayerCursor4()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�S��UI�̃A�j���[�V��������
//==============================================================
void World2_UI::Move_PlayerCursor4()
{
	m_PlayerCursorPos[5] = m_pAnim->Animation_Move(MOVECURSOR_POS6, 120.0f, 5.0f);

	m_PlayerCursorPos[6] = m_pAnim->Animation_Move(MOVECURSOR_POS7, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);
	m_fPopupSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld2_UI::Move_PlayerCursor5()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�T��UI�̃A�j���[�V��������
//==============================================================
void World2_UI::Move_PlayerCursor5()
{
	m_PlayerCursorPos[7] = m_pAnim->Animation_Move(MOVECURSOR_POS8, 120.0f, 5.0f);

	m_PlayerCursorPos[3] = m_pAnim->Animation_Move(MOVECURSOR_POS9, 120.0f, -5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);
	m_fPopupSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld2_UI::Move_PlayerCursor6()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�U��UI�̃A�j���[�V��������
//==============================================================
void World2_UI::Move_PlayerCursor6()
{
	m_PlayerCursorPos[10] = m_pAnim->Animation_Move(MOVECURSOR_POS11, 120.0f, -5.0f);

	m_PlayerCursorPos[11] = m_pAnim->Animation_Move(MOVECURSOR_POS_NEXT, 120.0f, 5.0f);

	m_ButtonSize = m_pAnim->Animation_Scale(120.0f, 10.0f, 75.0f);
	m_fPopupSize = m_pPopUpEase->MoveEaseOutBack(0.0f, 300.0f, 0.04f, true);
}

//==============================================================
//�@�֐����FWorld2_UI::Draw_Stage1()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂Q�|�P��UI�̕`��
//==============================================================
void World2_UI::Draw_Stage1()
{
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(STAGE_01_POSX, STAGE_01_POSY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_fPopupSize, m_fPopupSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pStageTex[0]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// A�{�^��
	world = DirectX::XMMatrixTranslation(STAGE_01_POSX + 120.0f, STAGE_01_POSY - 60.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �J�[�\����
	world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[4], 490.0f, 0.0f);
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

//==============================================================
//�@�֐����FWorld2_UI::Draw_Stage2()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�Q��UI�̕`��
//==============================================================
void World2_UI::Draw_Stage2()
{
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(STAGE_02_POSX, STAGE_02_POSY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_fPopupSize, m_fPopupSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pStageTex[1]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// A�{�^��
	world = DirectX::XMMatrixTranslation(STAGE_02_POSX + 120.0f, STAGE_02_POSY - 60.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	//---- �v���C���[����ɏo��J�[�\��
	// ��
	world = DirectX::XMMatrixTranslation(375.0f, m_PlayerCursorPos[1], 0.0f);
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

//==============================================================
//�@�֐����FWorld2_UI::Draw_Stage3()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�R��UI�̕`��
//==============================================================
void World2_UI::Draw_Stage3()
{
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(STAGE_03_POSX, STAGE_03_POSY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_fPopupSize, m_fPopupSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pStageTex[2]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// A�{�^��
	world = DirectX::XMMatrixTranslation(STAGE_03_POSX + 120.0f, STAGE_03_POSY - 60.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	//---- �v���C���[����ɏo��J�[�\��
	// ��
	world = DirectX::XMMatrixTranslation(540.0f, m_PlayerCursorPos[3], 0.0f);
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

//==============================================================
//�@�֐����FWorld2_UI::Draw_Stage4()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�S��UI�̕`��
//==============================================================
void World2_UI::Draw_Stage4()
{
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(STAGE_04_POSX, STAGE_04_POSY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_fPopupSize, m_fPopupSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pStageTex[3]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// A�{�^��
	world = DirectX::XMMatrixTranslation(STAGE_04_POSX + 120.0f, STAGE_04_POSY - 60.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	//---- �v���C���[����ɏo��J�[�\��
	// ��
	world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[6], 200.0f, 0.0f);
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

//==============================================================
//�@�֐����FWorld2_UI::Draw_Stage5()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂P�|�T��UI�̕`��
//==============================================================
void World2_UI::Draw_Stage5()
{
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(STAGE_05_POSX, STAGE_05_POSY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_fPopupSize, m_fPopupSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pStageTex[4]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// A�{�^��
	world = DirectX::XMMatrixTranslation(STAGE_05_POSX + 120.0f, STAGE_05_POSY - 60.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	//---- �v���C���[����ɏo��J�[�\��
	// ��
	world = DirectX::XMMatrixTranslation(870.0f, m_PlayerCursorPos[3], 0.0f);
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

//==============================================================
//�@�֐����FWorld2_UI::Draw_Stage6()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�e�[�W�Z���N�g�̂Q�|�U��UI�̕`��
//==============================================================
void World2_UI::Draw_Stage6()
{
	// �X�e�[�W�Z���N�g�i����̂�j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(STAGE_06_POSX, STAGE_06_POSY, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
	mat[2] = m_pCamera->GetProjectionMatrix2D();

	Sprite::SetWorld(mat[0]);
	Sprite::SetView(mat[1]);
	Sprite::SetProjection(mat[2]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_fPopupSize, m_fPopupSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pStageTex[5]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// A�{�^��
	world = DirectX::XMMatrixTranslation(STAGE_06_POSX + 120.0f, STAGE_06_POSY - 60.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(m_ButtonSize, m_ButtonSize));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pButtonTex);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// �v���C���[�̍����ɏo��J�[�\��
	world = DirectX::XMMatrixTranslation(m_PlayerCursorPos[10], 350.0f, 0.0f);
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
