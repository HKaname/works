//==============================================================
//
//  �t�@�C�����FMenu.cpp
//
//	�T�v�F
//	���j���[UI��\���y�шړ��A���j���[�̑I�����s�������̏������s��
//
//	�X�V����:
//	���t	����	����		���e
//	10/29	21:44	���䑓��	�X�V�����̒ǉ�
//			21:45	���䑓��	�R�����g��ǉ�
//	11/05	21:05	����v		UI�\���̌��I�u�W�F�N�g��ǉ�
//	11/08	23:17	����v		UI�\���p�I�u�W�F�N�g�̒ǉ���
//	11/12	19:05	����v		�s�v�����̍폜
//	11/14	09:55	����v		UI�̕\�����@�����ׂ�3D����2D�֕ύX
//==============================================================

//==============================================================
//  �C���N���[�h
//==============================================================
#include "menu.h"
#include "Input.h"
#include "Main.h"
#include "SceneStageSelect.h"
#include <stdio.h>

// �萔��`
#define MENU_FADEMOVEX	(250)
#define MENU_FADEFRAME	(30)

using namespace std;

//==============================================================
//�@�֐����FMenu::Menu()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FMenu�N���X�̃R���X�g���N�^	
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
	//---- �e�N�X�`���N���X�̊m�� ----
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

	//---- �e�N�X�`���̓ǂݍ��� ----
	//---- �Q�[����ʓ� ----
	if (FAILED(m_pTexture[0]->Create("Assets/Texture/UI/Game/UI_Game_Pause_01.png")))
	{
		MessageBox(NULL, "UI_Game_Pause_01���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	//---- ���j���[��� ----
	// �w�i
	if (FAILED(m_pTexture[1]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_PauseBG_005.png")))
	{
		MessageBox(NULL, "UI_Pause_PauseBG_005.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ������i���j
	if (FAILED(m_pTexture[2]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Continue(Small)_001.png")))
	{
		MessageBox(NULL, "UI_Pause_Continue(Small)_001.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ������i��j
	if (FAILED(m_pTexture[3]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Continue(Big)_007.png")))
	{
		MessageBox(NULL, "UI_Pause_Continue(Big)WithA_001.png���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ���g���C�i���j
	if (FAILED(m_pTexture[4]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Restart(small)_001.png")))
	{
		MessageBox(NULL, "UI_Pause_Restart(small)_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ���g���C�i��j
	if (FAILED(m_pTexture[5]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Restart(Big)_007.png")))
	{
		MessageBox(NULL, "UI_Pause_Restart(Big)WithA_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �X�e�[�W�Z���N�g�ɖ߂�i���j
	if (FAILED(m_pTexture[6]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_GiveUp(small)_002.png")))
	{
		MessageBox(NULL, "UI_Pause_GiveUp(small)_002���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �X�e�[�W�Z���N�g�ɖ߂�i��j
	if (FAILED(m_pTexture[7]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_SelectBack(Big)_007.png")))
	{
		MessageBox(NULL, "UI_Pause_SelectBack(Big)WithA_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ���ǂ�
	if (FAILED(m_pTexture[8]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_BackB_004.png")))
	{
		MessageBox(NULL, "UI_Pause_BBack_002���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �X�e�[�W�i���o�[�i�X�v���C�g�V�[�g�j
	if (FAILED(m_pTexture[9]->Create("Assets/Texture/UI/Game/Menu/UI_common_NoSpr_003.png")))
	{
		MessageBox(NULL, "UI_common_NoSpr_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ��Փx�i�X�v���C�g�V�[�g�j
	if (FAILED(m_pTexture[10]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_StarSpr_003.png")))
	{
		MessageBox(NULL, "UI_Pause_StarSpr_003���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// Tips�i���̎q�u�Â���v�j
	if (FAILED(m_pTexture[11]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_king_tudukeru.png")))
	{
		MessageBox(NULL, "UI_Pause_king_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// Tips�i�Ђ݂j
	if (FAILED(m_pTexture[12]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_Secret_001.png")))
	{
		MessageBox(NULL, "UI_Pause_Secret_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// Tips�i�����o���Ƃ��j
	if (FAILED(m_pTexture[13]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_BlackPopUp_001.png")))
	{
		MessageBox(NULL, "UI_Pause_BlackPopUp_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ����
	if (FAILED(m_pTexture[14]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_DecideA_002.png")))
	{
		MessageBox(NULL, "UI_Pause_DecideA_002���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// ���w�i
	if (FAILED(m_pTexture[15]->Create("Assets/Texture/UI/Game/BlackGround.png")))
	{
		MessageBox(NULL, "BlackGround���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// Tips�i���̎q�u��蒼���v�j
	if (FAILED(m_pTexture[16]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_king_yarinaosu.png")))
	{
		MessageBox(NULL, "UI_Pause_king_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// Tips�i���̎q�u�Z���N�g�ɖ߂�v�j
	if (FAILED(m_pTexture[17]->Create("Assets/Texture/UI/Game/Menu/UI_Pause_king_selectnimodoru.png")))
	{
		MessageBox(NULL, "UI_Pause_king_001���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	//---- ���ۂ��ނ̔閧 ----
	if (FAILED(m_pSecretTex[0]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_01.png")))
	{
		MessageBox(NULL, "���ۂ��ނ̂Ђ݂P���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[1]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_02.png")))
	{
		MessageBox(NULL, "���ۂ��ނ̂Ђ݂Q���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[2]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_03.png")))
	{
		MessageBox(NULL, "���ۂ��ނ̂Ђ݂R���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[3]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_07.png")))
	{
		MessageBox(NULL, "���ۂ��ނ̂Ђ݂S���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[4]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_05.png")))
	{
		MessageBox(NULL, "���ۂ��ނ̂Ђ݂T���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[5]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_06.png")))
	{
		MessageBox(NULL, "���ۂ��ނ̂Ђ݂U���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	if (FAILED(m_pSecretTex[6]->Create("Assets/Texture/UI/Game/Menu/Secret/menu_Text_04.png")))
	{
		MessageBox(NULL, "���ۂ��ނ̂Ђ݂V���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	//---- �A�j���[�V�����p�摜 ----
	// ���E(������)
	if (FAILED(m_pAnimTex[0]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_ContinueLfR_001.png")))
	{
		MessageBox(NULL, "�R���e�j���[���E�A�j���[�V�������ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �㉺(������)
	if (FAILED(m_pAnimTex[1]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_ContinueDfT_001.png")))
	{
		MessageBox(NULL, "�R���e�j���[�㉺�A�j���[�V�������ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �㉺(���Ȃ����E�ォ��)
	if (FAILED(m_pAnimTex[2]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_RestartTfD_001.png")))
	{
		MessageBox(NULL, "���Ȃ����㉺�A�j���[�V�����P���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �㉺(���Ȃ����E������)
	if (FAILED(m_pAnimTex[3]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_RestartDft_001.png")))
	{
		MessageBox(NULL, "���Ȃ����㉺�A�j���[�V�����Q���ǂݍ��߂܂���ł���", "Error", MB_OK);
	}
	// �㉺(�Z���N�g�ɖ߂�)
	if (FAILED(m_pAnimTex[4]->Create("Assets/Texture/UI/Game/Menu/Animation/UI_Pause_SelectBackTfD_001.png")))
	{
		MessageBox(NULL, "�Z���N�g�ɖ߂�㉺�A�j���[�V�������ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// ��Փx(EX)
	m_pEXdifficulty = new Texture();
	if (FAILED(m_pEXdifficulty->Create("Assets/Texture/UI/Game/Menu/UI_Pause_StarRedSpr_001.png")))
	{
		MessageBox(NULL, "�Z���N�g�ɖ߂�㉺�A�j���[�V�������ǂݍ��߂܂���ł���", "Error", MB_OK);
	}

	// �C�[�W���O�N���X�̊m��
	m_pEasing = new Easing();

	// �C�[�W���O�̏�����
	m_pEasing->ResetChangePowPlay();
	m_pEasing->ResetChangePowRevarse();

	// �A�j���[�V�����N���X�̊m��
	m_pAnimation = new CAnim();

	// �����A�j���[�V�����̐ݒ�
	AnimData MenuAnimData;
	MenuAnimData.nAnimeFrame  = MENU_ANIM_FRAME;
	MenuAnimData.nAnimeSplitX = MENU_ANIME_SPLIT_X;
	MenuAnimData.nAnimeSplitY = MENU_ANIME_SPLIT_Y;
	MenuAnimData.nEndAnimNo   = MENU_ANIME_END;

	m_pAnimation->SetAnime(MenuAnimData);

	//�T�E���h�̓ǂݍ���
	m_pSEMenuOpen = LoadSound("Assets/SE/supotto_UI_menu_open_V1.wav");//���j���[�I�[�v��
	m_pSEMenuClose = LoadSound("Assets/SE/supotto_UI_menu_close_V1.wav");//���j���[�N���[�Y
	m_pSEMenuDecision = LoadSound("Assets/SE/supotto_UI_kettei_V1.wav");//���j���[���艹
	m_pSEMenuMove = LoadSound("Assets/SE/supotto_UI_Move.wav");//���j���[�ړ���
	m_pSEMenuRetry = LoadSound("Assets/SE/supotto_UI_Retry.wav");//���j���[�ړ���
}

//==============================================================
//�@�֐����FMenu::~Menu()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�@�v�FMenu�N���X�̃f�X�g���N�^
//==============================================================
Menu::~Menu()
{
	// �e�N�X�`���̊J��
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

	// �C�[�W���O�N���X�̊J��
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
//	�֐����Fvoid Menu::Update()
//	�����P�F�Ȃ�
//	�����Q�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[�̍X�V����
//==============================================================
void Menu::Update()
{
	// �C�[�W���O�̃��Z�b�g
	if (m_MenuKind == E_NONE)
	{
		m_pEasing->ResetChangePowPlay();
		m_pEasing->ResetChangePowRevarse();
		m_pAnimation->SetClickAnimkind();
	}

	// ���j���[�̊J����
	if (!m_pEasing->GetIsPlay() && IsKeyTrigger(VK_ESCAPE) && m_MenuKind == E_NONE ||!m_pEasing->GetIsPlay() && IsKeyTrigger(VK_ESCAPE) && m_MenuKind == E_CLOSE ||
		!m_pEasing->GetIsPlay() && IsButtonTrigger(BUTTON_START) && m_MenuKind == E_NONE || !m_pEasing->GetIsPlay() && IsButtonTrigger(BUTTON_START) && m_MenuKind == E_CLOSE)
	{
		PlaySEOpen();	//�I�[�v��SE�Đ�
		m_nOldRandNo = m_RandomNo;

		// ���j���[���J��(�ŏ��̎�)
		if (m_MenuKind == E_NONE)
		{
			m_MenuKind++;
		}

		// ���j���[���J��(���j���[�����܂��Ă���Ƃ�)
		if (m_MenuKind == E_CLOSE)
		{
			m_MenuKind--;
		}

		// �C�[�W���O�̃��Z�b�g
		m_pEasing->ResetChangePowRevarse();

		while (m_nOldRandNo == m_RandomNo)
		{
			if (GetStage() < STAGE_3_01)
				m_RandomNo = rand() % 5 + 1;
			else
				m_RandomNo = rand() % 6 + 1;
		}

		// ���j���[���J���Ă邩���邽�߂̐؂�ւ�
		m_bMenu = true;
	}
	else if(!m_pEasing->GetIsPlay() && IsKeyTrigger(VK_ESCAPE) && m_MenuKind == E_OPEN ||
		!m_pEasing->GetIsPlay() && IsButtonTrigger(BUTTON_START) && m_MenuKind == E_OPEN ||
		!m_pEasing->GetIsPlay() && IsButtonTrigger(BUTTON_B) && m_MenuKind == E_OPEN)
	{
		PlaySEClose();//�N���[�YSE�Đ�
		// ���j���[�����
		m_MenuKind++;

		// �C�[�W���O�̃��Z�b�g
		m_pEasing->ResetChangePowPlay();

		// ���j���[���J���Ă邩���邽�߂̐؂�ւ�
		m_bMenu = false;
	}

	// ���j���[�̈ړ�����
	if (m_MenuKind == E_OPEN)	// true�Ȃ烁�j���[���o�Ă���Afalse�Ȃ烁�j���[����������
	{
		MoveUI();

		// �C�[�W���O�̃��Z�b�g
		m_pEasing->ResetChangePowRevarse();
	}
	else if(m_MenuKind == E_CLOSE)
	{
		ResetUI();

		// �C�[�W���O�̃��Z�b�g
		m_pEasing->ResetChangePowPlay();

		if (m_MenuPosX[0] <= -230.0f)
		{
			m_MenuSelectKind = E_CONTINU;
		}
	}

	// ���j���[���̑I��
	if (m_bMenu)
	{
		if (IsKeyTrigger('W') || IsButtonTrigger(BUTTON_UP) || IsButtonTrigger(STICK_UP))
		{
			// �ߋ��̑I���f�[�^���i�[
			m_OldSelectMenu = m_MenuSelectKind;
			m_MenuSelectKind--;
			m_pAnimation->ResetUvPos();

			if (m_MenuSelectKind < E_CONTINU)
			{
				// �ߋ��̑I���f�[�^���i�[
				m_OldSelectMenu = m_MenuSelectKind;
				m_MenuSelectKind = E_RETRUN;
				m_pAnimation->ResetUvPos();
			}

			if (m_bMenu) {
				//�ړ�SE
				if (m_pSEMenuMoveSpeaker) {
					m_pSEMenuMoveSpeaker->DestroyVoice();
					m_pSEMenuMoveSpeaker = nullptr;
				}
				m_pSEMenuMoveSpeaker = PlaySound(m_pSEMenuMove);
			}
		}
		else if (IsKeyTrigger('S') || IsButtonTrigger(BUTTON_DOWN) || IsButtonTrigger(STICK_DOWN))
		{
			// �ߋ��̑I���f�[�^���i�[
			m_OldSelectMenu = m_MenuSelectKind;
			m_MenuSelectKind++;
			m_pAnimation->ResetUvPos();

			if (m_MenuSelectKind > E_RETRUN)
			{
				// �ߋ��̑I���f�[�^���i�[
				m_OldSelectMenu = m_MenuSelectKind;
				m_MenuSelectKind = E_CONTINU;
				m_pAnimation->ResetUvPos();
			}

			if (m_bMenu) {
				//�ړ�SE
				if (m_pSEMenuMoveSpeaker) {
					m_pSEMenuMoveSpeaker->DestroyVoice();
					m_pSEMenuMoveSpeaker = nullptr;
				}
				m_pSEMenuMoveSpeaker = PlaySound(m_pSEMenuMove);
			}
		}

		// ���j���[��I��������̏���
		if (m_bMenu && m_MenuSelectKind == E_RETRUN && IsKeyTrigger(VK_RETURN) && !IsKeyTrigger(VK_ESCAPE) ||
			m_bMenu && m_MenuSelectKind == E_RETRUN && IsButtonTrigger(BUTTON_A) && !IsKeyTrigger(VK_ESCAPE))
		{
			PlaySEDecision();	//����SE�̍Đ�
			//���^�[���t���O�̑��M
			m_ReturnFlg = true;

			m_ClickAnimflg = true;

			// ���j���[�̐؂�ւ�
			m_bMenu = false;
			m_MenuKind++;
		}
		else if (m_bMenu && m_MenuSelectKind == E_CONTINU && IsKeyTrigger(VK_RETURN) && !IsKeyTrigger(VK_ESCAPE) ||
			m_bMenu && m_MenuSelectKind == E_CONTINU && IsButtonTrigger(BUTTON_A) && !IsKeyTrigger(VK_ESCAPE))
		{
			PlaySEDecision();	//����SE�̍Đ�

			m_ClickAnimflg = true;

			// ���j���[�̐؂�ւ�
			m_bMenu = false;
			m_MenuKind++;
		}
		else if (m_bMenu && m_MenuSelectKind == E_RETRY && IsKeyTrigger(VK_RETURN) && !IsKeyTrigger(VK_ESCAPE) ||
			m_bMenu && m_MenuSelectKind == E_RETRY && IsButtonTrigger(BUTTON_A) && !IsKeyTrigger(VK_ESCAPE))
		{
			//	PlaySEDecision();	//����SE�̍Đ�
			if (m_pSEMenuRetrySpeaker) {
				m_pSEMenuRetrySpeaker->DestroyVoice();
				m_pSEMenuRetrySpeaker = nullptr;
			}
			m_pSEMenuRetrySpeaker = PlaySound(m_pSEMenuRetry);
			m_pSEMenuRetrySpeaker->SetVolume(0.6f);

			m_ClickAnimflg = true;

			// ���g���C�t���O�̑��M
			m_RetryFlg = true;

			// ���j���[�̐؂�ւ�
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
		// �A�j���[�V�����̃��Z�b�g
		m_pAnimation->SetClickAnimkind();
		m_MenuSelectSize = 750.0f;
	}

	if (m_bMenu)
	{
		// �e�N�X�`���A�j���[�V����
		m_MenuAnim_UVPos = m_pAnimation->TextureAnimation(false);
	}
	else
	{
		m_pAnimation->ResetUvPos();
		m_OldSelectMenu = E_CONTINU;		
	}
}

//==============================================================
//	�֐����Fvoid Menu::Draw_GameUI()
//	�����P�F�Ȃ�
//	�����Q�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F�Q�[����UI�̕`�揈���̊֐�
//==============================================================
void Menu::Draw_GameUI()
{
	//---- �Q�[����UI ----
	DirectX::XMFLOAT4X4 mat[3];

	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(m_GameUIPosX, 650.0f, -1.0f);
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
	Sprite::SetSize(DirectX::XMFLOAT2(100.0f, 100.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[0]);
	Sprite::Draw();
}

//==============================================================
//	�֐����Fvoid Menu::Draw_MenuUI()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[��UI�̕`�揈��
//==============================================================
void Menu::Draw_MenuUI()
{
	//---- �I�v�V����UI ----
	DirectX::XMFLOAT4X4 mat[3];

	// ��ʂ��Â�����摜
	// ���[���h�s��̌v��
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	// �r���[���W
	mat[1] = m_pCamera->GetViewMatrix2D();

	// �v���W�F�N�V�������W
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

	// �|�[�Y�w�i
	world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 360.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(SCREEN_HEIGHT, SCREEN_HEIGHT));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[1]);
	Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
	Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
	Sprite::Draw();

	// Tips(�����o��Ƃ�)
	world = DirectX::XMMatrixTranslation(m_MenuPosX[1], 120.0f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(700.0f, 700.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[13]);
	Sprite::Draw();

	// �e�I������I��ł���Ƃ��̕`��
	if (m_MenuSelectKind == E_CONTINU)	// ������̎�
	{
		if (m_OldSelectMenu == E_CONTINU && m_MenuSelectKind == E_CONTINU)
		{
			// ������
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
			// ������
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

		// ���Ȃ���
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 200.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���N�g�ɖ߂�
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 115.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[6]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Tips(�Ђ݂�)
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 225.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[12]);
		Sprite::Draw();

		// �q��
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
		// ������
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
			// ���Ȃ���
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
			// ���Ȃ���
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

		// �Z���N�g�ɖ߂�
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 115.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[6]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// Tips(�Ђ݂�)
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 225.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[12]);
		Sprite::Draw();

		// �q��
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
		// ������
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 565.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[2]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// ���Ȃ���
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 485.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pTexture[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::Draw();

		// �Z���N�g�ɖ߂�
		world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 270.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(m_MenuSelectSize, m_MenuSelectSize));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetTexture(m_pAnimTex[4]);
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f / (float)MENU_ANIME_SPLIT_X, 1.0f / (float)MENU_ANIME_SPLIT_Y));
		Sprite::SetUVPos(m_MenuAnim_UVPos);
		Sprite::UIDraw();

		// Tips(�Ђ݂�)
		world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 165.0f, 225.0f, 0.0f);
		DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

		Sprite::SetWorld(mat[0]);
		Sprite::SetSize(DirectX::XMFLOAT2(350.0f, 350.0f));
		Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
		Sprite::SetUVScale(DirectX::XMFLOAT2(1.0f, 1.0f));
		Sprite::SetUVPos(DirectX::XMFLOAT2(0, 0));
		Sprite::SetTexture(m_pTexture[12]);
		Sprite::Draw();

		// �q��
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

	// ���ǂ�
	world = DirectX::XMMatrixTranslation(m_MenuPosX[0], 27.5f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(150.0f, 150.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[8]);
	Sprite::Draw();

	// ����
	world = DirectX::XMMatrixTranslation(m_MenuPosX[0] - 145.0f, 27.5f, 0.0f);
	DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

	Sprite::SetWorld(mat[0]);
	Sprite::SetSize(DirectX::XMFLOAT2(150.0f, 150.0f));
	Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	Sprite::SetTexture(m_pTexture[14]);
	Sprite::Draw();

	// �X�e�[�W�i���o�[ + ��Փx
	Draw_StageNum();

	Draw_Secret(m_RandomNo);
}

//==============================================================
//	�֐����Fvoid Menu::Draw_StageNum(eWorldKind world)
//	�����P�FeWorldKind playworld(�ǂ̃X�e�[�W�ɂ��邩)
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[�̃X�e�[�W�i���o�[�\���p�֐�
//==============================================================
void Menu::Draw_StageNum()
{
	// �X�e�[�W�P
	if (GetStage() >= STAGE_1_01 && GetStage() <= STAGE_1_05)
	{
		//---- ��{��� ----
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�i���o�[
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
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_1_02:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_1_03:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_1_04:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_1_05:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherEasy);
			break;

		default:
			break;
		}
	}

	// �X�e�[�W�Q
	if (GetStage() >= STAGE_2_01 && GetStage() <= STAGE_2_06)
	{
		//---- ��{��� ----
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�i���o�[
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
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_2_02:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_2_03:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_2_04:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_2_05:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_2_06:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		default:
			break;
		}
	}

	// �X�e�[�W�R
	if (GetStage() >= STAGE_3_01 && GetStage() <= STAGE_3_07)
	{
		//---- ��{��� ----
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�i���o�[
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
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_3_02:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_3_03:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_3_04:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_3_05:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_3_06:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_3_07:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult);
			break;

		default:
			break;
		}
	}

	// �X�e�[�W�S
	if (GetStage() >= STAGE_4_01 && GetStage() <= STAGE_4_08)
	{
		//---- ��{��� ----
		DirectX::XMFLOAT4X4 mat[3];

		// ���[���h�i���o�[
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
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Easy);
			break;

		case STAGE_4_02:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherEasy);
			break;

		case STAGE_4_03:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_4_04:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal);
			break;

		case STAGE_4_05:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_4_06:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_4_07:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_4_08:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult);
			break;

		default:
			break;
		}
	}

	// �X�e�[�W�T
	if (GetStage() >= STAGE_5_01 && GetStage() <= STAGE_5_10)
	{
		// -
		//---- ��{��� ----
		DirectX::XMFLOAT4X4 mat[3];
		DirectX::XMMATRIX world;

		if (GetStage() >= STAGE_5_01 && GetStage() < STAGE_5_10)
		{
			// ���[���h�i���o�[
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
			// ���[���h�i���o�[
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
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_5_02:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_5_03:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_5_04:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult);
			break;

		case STAGE_5_05:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_06:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_07:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_08:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_09:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.5f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Difficult);
			break;

		case STAGE_5_10:
			// �X�e�[�W�i���o�[(�P�O�̈�)
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 260.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// �X�e�[�W�i���o�[(�P�̈�)
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 320.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.5f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Difficult);
			break;

		
		default:
			break;
		}
	}

	// �X�e�[�WEX
	if (GetStage() >= STAGE_EX_01 && GetStage() <= STAGE_EX_05)
	{
		// -
		//---- ��{��� ----
		DirectX::XMFLOAT4X4 mat[3];
		DirectX::XMMATRIX world;

		// ���[���h�i���o�[
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
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 300.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Easy_EX);
			break;

		case STAGE_EX_02:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.25f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherEasy_EX);
			break;

		case STAGE_EX_03:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.5f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Normal_EX);
			break;

		case STAGE_EX_04:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.75f, 0.0f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_RatherDifficult_EX);
			break;

		case STAGE_EX_05:
			// �X�e�[�W�i���o�[
			world = DirectX::XMMatrixTranslation(m_MenuPosX[1] + 310.0f, 660.0f, 0.0f);
			DirectX::XMStoreFloat4x4(&mat[0], DirectX::XMMatrixTranspose(world));

			Sprite::SetWorld(mat[0]);
			Sprite::SetSize(DirectX::XMFLOAT2(75.0f, 75.0f));
			Sprite::SetColor(DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
			Sprite::SetTexture(m_pTexture[9]);
			Sprite::SetUVPos(DirectX::XMFLOAT2(0.0f, 0.25f));
			Sprite::UIDraw();

			// ��Փx
			Draw_Difficulty(E_Difficult_EX);
			break;
		default:
			break;
		}
	}
}

//==============================================================
//	�֐����Fvoid Menu::Draw_Secret()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���ۂ��ނ̔閧�̕\��
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
		// ��Փx
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
		// ��Փx
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
		// ��Փx
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
		// ��Փx
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
		// ��Փx
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
		// ��Փx
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
		// ��Փx
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
		// ��Փx
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
		// ��Փx
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
		// ��Փx
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
//	�֐����Fvoid Menu::MoveStartUI()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F�X�^�[�g���o���̉E��UI�̈ړ�����
//==============================================================
void Menu::MoveStartUI()
{
	m_GameUIPosX = m_pEasing->MoveEaseOutQuad(-230.0f, 75.0f, 0.02f, true);
}

//==============================================================
//	�֐����Fvoid Menu::MoveEndUI()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F�S�[�����o���̉E��UI�̈ړ�����
//==============================================================
void Menu::MoveEndUI()
{
	m_GameUIPosX = m_pEasing->MoveEaseOutQuad(-230.0f, 75.0f, 0.02f, false);
}

//==============================================================
//	�֐����Fvoid Menu::MoveUI()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[���J�����Ƃ��̈ړ�����
//==============================================================
void Menu::MoveUI()
{
	m_MenuPosX[0] = m_pEasing->MoveEaseOutBack(-230.0f, 220.0f, 0.025f, true);

	m_MenuPosX[1] = m_pEasing->MoveEaseOutBack(1615.0f, 905.0f, 0.045f, true);
}

//==============================================================
//	�֐����Fvoid Menu::ResetUI()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[������Ƃ��̈ړ�����
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
//	�֐����Fvoid Menu::SetMenuSelectKind()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[������Ƃ��Ƀ��j���[�̑I�������Z�b�g���鏈��
//==============================================================
int  Menu::SetMenuSelectContinu()
{
	return m_MenuSelectKind = E_CONTINU;
}

//==============================================================
//	�֐����Fvoid Menu::GetMenuSelectKind()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[�̏�Ԃ�n�������i�I����ԁj
//==============================================================
int Menu::GetMenuSelectKind()
{
	return m_MenuSelectKind;
}

//==============================================================
//	�֐����Fvoid Menu::GetMenuSelectKind()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[�̏�Ԃ�n�������i���j���[���J����Ă邩�j
//==============================================================
int Menu::GetMenuKined()
{
	return m_MenuKind;
}

//==============================================================
//	�֐����Fvoid Menu::GetbMenu()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[UI���J���Ă��邩�ǂ����Ԃ��֐�
//==============================================================
bool Menu::GetbMenu()
{
	return m_bMenu;
}

//==============================================================
//	�֐����Fvoid Menu::GetRetryFlg()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���g���C���I�΂�Ă��邩�Ԃ��֐�
//==============================================================
bool Menu::GetRetryFlg()
{
	return m_RetryFlg;
}

//==============================================================
//	�֐����Fvoid Menu::GetReturnFlg()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F�Z���N�g�ɖ߂邪�I�΂�Ă��邩�Ԃ��֐�
//==============================================================
bool Menu::GetReturnFlg()
{
	return m_ReturnFlg;
}

//�I�[�v��SE�Đ�
void Menu::PlaySEOpen()
{
	if (m_pSEMenuSpeaker) {
		m_pSEMenuSpeaker->DestroyVoice();
		m_pSEMenuSpeaker = nullptr;
	}
	m_pSEMenuSpeaker = PlaySound(m_pSEMenuOpen);//�I�[�v��SE�Đ�
}

//�N���[�YSE�Đ�
void Menu::PlaySEClose()
{
	if (m_pSEMenuSpeaker) {
		m_pSEMenuSpeaker->DestroyVoice();
		m_pSEMenuSpeaker = nullptr;
	}
	m_pSEMenuSpeaker = PlaySound(m_pSEMenuClose);//�N���[�YSE�Đ�
}

//����SE�Đ�
void Menu::PlaySEDecision()
{
	if (m_pSEMenuSpeaker) {
		m_pSEMenuSpeaker->DestroyVoice();
		m_pSEMenuSpeaker = nullptr;
	}
	m_pSEMenuSpeaker = PlaySound(m_pSEMenuDecision);//����SE�Đ�
}

//==============================================================
//	�֐����Fvoid Menu::SetMotionLess()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[�������Ȃ��悤�ɂ���֐�
//==============================================================
int Menu::SetMotionLess()
{
	return m_MenuKind = E_MOTIONLESS;
}

//==============================================================
//	�֐����Fvoid Menu::SetNone()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[�������ɂ���֐�
//==============================================================
int Menu::SetNone()
{
	return m_MenuKind = E_NONE;
}

//==============================================================
//	�֐����Fvoid Menu::GetPos()
//	�����P�F�Ȃ�
//	�߂�l�F�Ȃ�
//
//	�T�v�F���j���[UI�̌��ݍ��W��n������
//==============================================================
float Menu::GetPos()
{
	return m_MenuPosX[0];
}

//==============================================================
//	�֐����Fvoid CObject::SetCamera(CameraBase * pCamera)
//	�����P�F�J�����̃|�C���^
//	�߂�l�F�Ȃ�
//	�T�v�F�J�����̃|�C���^�̎󂯓n��
//==============================================================
void Menu::SetCamera(CameraBase * pCamera)
{
	m_pCamera = pCamera;
}
