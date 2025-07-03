//==============================================================
//
//  �t�@�C�����FUIdirection.cpp
//
//	�T�v�FUI���o�̏������s��
//==============================================================

// �C���N���[�h��
#include "UIdirection.h"

//==============================================================
//�@�֐����FCDirection::CDirection()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FCDirection�N���X�̃R���X�g���N�^	
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
	//---- �e�N�X�`���N���X�̊m�� ----
	for (int i = 0; i < MAX_DIRECTION_TEX; i++)
	{
		m_pTexture[i] = new Texture();
	}

	//---- �e�N�X�`���̓ǂݍ��� ----
	// �X�^�[�g���o�p
	// �Â����邽�߂̍��h��摜
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Game/BlackGround.png")))
	{
		MessageBox(NULL, "BlackGround���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �X�^�[�g�I���ď����Ă�����
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Game/Animation/UI_start_text.PNG")))
	{
		MessageBox(NULL, "UI_start_text.PNG���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �q���������z������ł�摜
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Game/Animation/UI_start_whistle01.PNG")))
	{
		MessageBox(NULL, "UI_start_whistle01���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �q�����J�𐁂��Ă�摜
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Game/Animation/UI_start_whistle02.PNG")))
	{
		MessageBox(NULL, "UI_start_whistle02���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �S�[�����o�p
	// �N���A�������ɕ\������摜�i�̂݁j
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Game/Animation/UI_clear_blue.png")))
	{
		MessageBox(NULL, "UI_clear���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �N���A�������ɕ\������摜�i�ԁj
	if (FAILED(m_pTexture[5]->Create("Assets/Texture/UI/Game/Animation/UI_clear_blue_pink.png")))
	{
		MessageBox(NULL, "UI_clear���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ���̃X�e�[�W�ցi�I�����j
	if (FAILED(m_pTexture[6]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_NextStage_A_001.png")))
	{
		MessageBox(NULL, "UI_Pause_NextStage_A_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���N�g�ɖ߂�i�I�����j
	if (FAILED(m_pTexture[7]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_BackSelect_A_001.png")))
	{
		MessageBox(NULL, "UI_Pause_BackSelect_A_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ���̃X�e�[�W�ցi��I�����j
	if (FAILED(m_pTexture[8]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_NextStage(Black)_001.png")))
	{
		MessageBox(NULL, "UI_Pause_NextStage(Black)_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �Z���N�g�ɖ߂�i��I�����j
	if (FAILED(m_pTexture[9]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_BackSelect(Black)_001.png")))
	{
		MessageBox(NULL, "UI_Pause_BackSelect(Black)_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// A�{�^��
	if (FAILED(m_pTexture[10]->Create("Assets/Texture/UI/Game/Animation/UI_Pause_BackSelect_A_001.png")))
	{
		MessageBox(NULL, "UI_Pause_BackSelect_A_001.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �S�[����
	m_pGoalShineTex = new Texture();
	if (FAILED(m_pGoalShineTex->Create("Assets/Texture/UI/Game/Animation/UI_clear_shine.png")))
	{
		MessageBox(NULL, "m_pGoalShineTex���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	m_pGoalTextTex = new Texture();
	if (FAILED(m_pGoalTextTex->Create("Assets/Texture/UI/Game/Animation/UI_clear_text.png")))
	{
		MessageBox(NULL, "m_pGoalTextTex���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	m_pGoalEfectPS = new PixelShader();
	if (FAILED(m_pGoalEfectPS->Load("Assets/Shader/GloalEfect.cso")))
	{
		MessageBox(NULL, "m_pGoalTextTex���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	//�T�E���h�f�[�^�̓ǂݍ���
	m_pSEDecision = LoadSound("Assets/SE/supotto_UI_kettei_V1.wav");//����SE
	m_pSEStart = LoadSound("Assets/SE/supoimu_Start_V6.wav");		//�X�^�[�g���̃W���O��
	m_pSEGoal = LoadSound("Assets/SE/supoimu_goal_re-take.wav");	//�S�[�����̃W���O��

	// �C�[�W���O�̍쐬
	m_pEasing = new Easing();
	m_pTextEase = new Easing();

	// �A�j���[�V�����̍쐬
	m_pAnim = new CAnim();
}

//==============================================================
//�@�֐����FCDirection::~CDirection()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FCDirection�N���X�̃f�X�g���N�^	
//==============================================================
CDirection::~CDirection()
{
	// �e�N�X�`���̊J��
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
	// �C�[�W���O�̊J��
	delete m_pEasing; m_pEasing = nullptr;
	delete m_pTextEase; m_pTextEase = nullptr;

	// �A�j���[�V�����̊J��
	delete m_pAnim; m_pAnim = nullptr;
}

//==============================================================
//�@�֐����FCDirection::StartDirection_Ready()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�^�[�gUI�̕\���i�q���J�����O�̂�j
//===============================================================
void CDirection::StartDirection_Ready()
{
	// �q���i���z������ł���j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_Di_UIPosX[1], SCREEN_HEIGHT / 2 ,0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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

	// ���w�i
	world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0], SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_WIDTH, SCREEN_HEIGHT));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_alpha[0]));
	Sprite::SetTexture(m_pTexture[0]);
	Sprite::Draw();
}

//==============================================================
//�@�֐����FCDirection::StartDirection_Start()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�^�[�gUI�̕\���i�q���J�����Ă�ق��j
//===============================================================
void CDirection::StartDirection_Start()
{
	//�q���i�J�����Ă��j
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_Di_UIPosX[1], SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMMATRIX mr = DirectX::XMMatrixRotationZ(m_angle);
	world = mr * world;
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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

	// ���w�i
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
//�@�֐����FCDirection::StartDirection_Alert()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�^�[�gUI�̕\���i�X�^�[�g�I�̕����A��ł��������������߂Ɋ֐��𕪂��Ă���j
//===============================================================
void CDirection::StartDirection_Alert()
{
	// �X�^�[�g�I���Ă����Ă�����
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_Di_UIPosX[2], SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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
//�@�֐����FCDirection::DrawLoadAnim()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F���[�h����NowLoading�̕`��
//===============================================================
void CDirection::DrawLoadAnim()
{
	// �X�^�[�g�I���Ă����Ă�����
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(995.0f, 60.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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
//�@�֐����FCDirection::GoalDirection()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�S�[��UI�̕\��
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
	
	// �S�[��UI
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0], SCREEN_HEIGHT / 1.1f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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
			{	// ���̃X�e�[�W�֑I����
				// �Z���N�g�ɖ߂�
				world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0] - 200.0f, SCREEN_HEIGHT / 2 - 265.0f, 0.0f);
				DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

				Sprite::SetWorld(mat[0]);
				Sprite::SetSize(DirectX::XMFLOAT2(m_fGoalButton_Return, m_fGoalButton_Return));
				Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
				Sprite::SetTexture(m_pTexture[9]);
				Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
				Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
				Sprite::Draw();

				// ���̃X�e�[�W��
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
			{	// �Z���N�g�ɖ߂�I����
				// �Z���N�g�ɖ߂�
				world = DirectX::XMMatrixTranslation(m_Di_UIPosX[0] - 200.0f, SCREEN_HEIGHT / 2 - 265.0f, 0.0f);
				DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

				Sprite::SetWorld(mat[0]);
				Sprite::SetSize(DirectX::XMFLOAT2(m_fGoalButton_Return, m_fGoalButton_Return));
				Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
				Sprite::SetTexture(m_pTexture[7]);
				Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
				Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
				Sprite::Draw();

				// ���̃X�e�[�W��
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
			// �Z���N�g�ɖ߂�
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
//�@�֐����FCDirection::MoveUI_In()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�^�[�gUI�̈ړ�����(�����Ă���Ƃ�)
//===============================================================
void CDirection::MoveUI_In()
{
	m_Di_UIPosX[1] = m_pEasing->MoveEaseOutCubic(1400.0f, 800.0f, 0.02f, true);
}

//==============================================================
//�@�֐����FCDirection::MoveUI_Out()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�^�[�gUI�̈ړ�����(�����Ă���)
//===============================================================
void CDirection::MoveUI_Out()
{
	m_Di_UIPosX[1] = m_pEasing->MoveEaseOutQuart(-500.0f, 800.0f, 0.04f, false);
}

//==============================================================
//�@�֐����FCDirection::ChangeUISize()
//	�����P�F�Q�[�����I��������
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�S�[��UI�̕\�����鏈��
//===============================================================
void CDirection::ChangeUISize(bool bEndGame, int Stage)
{
/*	m_bGoalFlag = false;*///�S�[�����t���O
	m_Directionframe++;

	if (m_Directionframe < 230.0f)
		m_pEasing->ResetChangePowPlay();

	// �ړ������UI��Z�����ĕ\�����Ă���
	if (m_Directionframe >= 230.0f)
	{
		m_DirextionSize = m_pEasing->MoveEaseOutBack(0.0f, 800.0f, 0.05f, true);

		if (m_bGoalSound == true) {//�ŏ���1��ڂ̂�
			m_pSEGoalSpeaker = PlaySound(m_pSEGoal);//�S�[���W���O���Đ�
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

		// �u���̃X�e�[�W�ցv�֓���
		if (IsKeyTrigger('D') || IsButtonTrigger(BUTTON_RIGHT) || IsButtonTrigger(STICK_RIGHT))
		{
			if (m_nGoalSelectKind > 0)
			{
				m_nGoalSelectKind--;
			}
		}

		// �u�X�e�[�W�Z���N�g�ɖ߂�v�֓���
		if (IsKeyTrigger('A') || IsButtonTrigger(BUTTON_LEFT) || IsButtonTrigger(STICK_LEFT))
		{
			if (m_nGoalSelectKind < 1)
			{
				m_nGoalSelectKind++;
			}
		}

		// �u���̃X�e�[�W�ցv��I�񂾎�
		if (m_nGoalSelectKind == E_NEXT && bEndGame && IsKeyTrigger(VK_RETURN) ||
			m_nGoalSelectKind == E_NEXT && bEndGame && IsButtonTrigger(BUTTON_A))
		{
			if (m_bGoalDirection) {//�ŏ���1��ڂ̂�
				m_pSESpeaker = PlaySound(m_pSEDecision);//����SE
			}

			if (m_alpha[2] >= 1.0f && !m_bGoalFlag)
			{
				m_bGoalFlag = true;//�S�[�����t���O
			}

			m_bGoalDirection = false; // UI����������

			m_Directionframe = 0;
		}

		// �I�����A�j���[�V����
		if (m_nGoalSelectKind == E_NEXT)
			m_fGoalButton_Next = m_pAnim->Animation_Scale(60.0f,20.0f,450.0f);

		// �u�Z���N�g�ɖ߂�v��I�񂾎�
		if (m_nGoalSelectKind == E_RETRUN_SELECT && bEndGame && IsKeyTrigger(VK_RETURN) ||
			m_nGoalSelectKind == E_RETRUN_SELECT && IsButtonTrigger(BUTTON_A))
		{
			if (m_bGoalDirection) {//�ŏ���1��ڂ̂�
				m_pSESpeaker = PlaySound(m_pSEDecision);//����SE
			}

			if (m_alpha[2] >= 1.0f && !m_bGoalFlag)
			{
				m_bGoalFlag = true;//�S�[�����t���O
			}

			m_bGoalDirection = false; // UI����������

			m_Directionframe = 0;
		}

		// �I�����A�j���[�V����
		if (m_nGoalSelectKind == E_RETRUN_SELECT)
			m_fGoalButton_Return = m_pAnim->Animation_Scale(60.0f, 20.0f, 450.0f);
	}

	// �e���[���h�ŏI�X�e�[�W�̎��̏���
	if (Stage == STAGE_1_05 || Stage == STAGE_2_06 || Stage == STAGE_3_07 || Stage == STAGE_4_08 || Stage == STAGE_5_10 || Stage == STAGE_EX_01 || Stage == STAGE_EX_05)
	{
		m_ftime++;

		m_nGoalSelectKind = E_RETRUN_SELECT;

		// �I�����A�j���[�V����
		m_fGoalButton_Return = m_pAnim->Animation_Scale(60.0f, 20.0f, 450.0f);

		// �u�Z���N�g�ɖ߂�v��I�񂾎�
		if (bEndGame && IsKeyTrigger(VK_RETURN) || bEndGame && IsButtonTrigger(BUTTON_A))
		{
			if (m_bGoalDirection) {//�ŏ���1��ڂ̂�
				m_pSESpeaker = PlaySound(m_pSEDecision);//����SE
			}

			if (m_alpha[2] >= 1.0f && !m_bGoalFlag)
			{
				m_bGoalFlag = true;//�S�[�����t���O
			}

			m_bGoalDirection = false; // UI����������
		}
	}
}

//==============================================================
//�@�֐����FCDirection::StartUIDirection()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�F�X�^�[�g����UI���o
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
		if (m_StartUICnt == 56) m_pSEStartSpeaker = PlaySound(m_pSEStart);//�X�^�[�g�W���O���Đ�
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
//�@�֐����FCDirection::GetPosX()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�Fm_Di_UIPosX[1]�̍��W��Ԃ��֐�
//===============================================================
float CDirection::GetPosX()
{
	return m_Di_UIPosX[1];
}

//==============================================================
//�@�֐����FCDirection::GetbDirection()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�Fm_bGoalDirection�̏�Ԃ�Ԃ��֐�
//===============================================================
bool CDirection::GetbDirection()
{
	return m_bStartDirection;
}

//==============================================================
//�@�֐����FCDirection::GetEndFade()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�Fm_bEndFade�̏�Ԃ�Ԃ��֐�
//===============================================================
bool CDirection::GetEndFade()
{
	return m_bEndFade;
}

//==============================================================
//�@�֐����FCDirection::GetGoalFlag()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FGetGoalFlag�̏�Ԃ�Ԃ��֐�
//===============================================================
bool CDirection::GetGoalFlag()
{
	return m_bGoalFlag;
}

//==============================================================
//�@�֐����FCDirection::GetStartCnt()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FStartUICnt�̏�Ԃ�Ԃ��֐�
//===============================================================
int CDirection::GetStartCnt()
{
	return m_StartUICnt;
}

//==============================================================
//�@�֐����FCDirection::GetGoalSelectKind()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FGoalSelectKind�̏�Ԃ�Ԃ��֐�
//===============================================================
int CDirection::GetGoalSelectKind()
{
	return m_nGoalSelectKind;
}

//�S�[�����̃T�E���h�t���O��Ԃ�
bool CDirection::GetGoalSound()
{
	return m_bGoalSound;
}

//�S�[����Ɍ���{�^������������
bool CDirection::GetGoalDirection()
{
	return m_bGoalDirection;
}
