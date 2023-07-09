#include <time.h>
#include "main.h"
#include "title.h"
#include "menu.h"
#include "renderer.h"
#include "player.h"
#include "battle.h"
#include "enemy.h"
#include "input.h"
#include "skill.h"
#include "tutorial.h"

// �V�[���Ǘ��p
int mode;

int main()
{

	Init();

	//mode = GAME_MENU;
	while (1)
	{
		Update();	// �X�V����


		Draw();		// �`�揈��
	}

	rewind(stdin);
	(void)_getch();

	Uninit();
	return 0;
}

void Init(void)
{
	// �����_���̏���������
	srand((unsigned)time(NULL));
	int mode = GAME_TITLE;

	// �^�C�g���̏���������
	InitTitle();
	// ���j���[�̏���������
	InitMenu();
	InitTuto();
	InitPlayer();
	InitEnemy();
	InitBattle();

}

void Uninit(void)
{

}

void Update(void)
{
	switch (GetMode())
	{
	case GAME_TITLE:
		// �^�C�g���̍X�V����
		UpdateTitle();
		break;
	case GAME_MENU:
		// ���j���[�̍X�V����
		UpdateMenu();
		break;
	case GAME_TUTO:
		UpdateTuto();
		break;
	case GAME_INTRO:
		if (!GetInputDone())
		{
			UpdateInput();
		}
		if (GetInputDone())
		{
			UpdateBattle();
			UpdatePlayer();
			UpdateEnemy();
		}
		break;


	case GAME_BATTLE:
		if (!GetInputDone())
		{
			UpdateInput();
		}
		if (GetInputDone())
		{
			UpdateBattle();
			UpdatePlayer();
			UpdateEnemy();
		}
		break;
	case GAME_EVENT:
		// �t�B�[���h�̍X�V����
		//UpdateField();
		break;
	}
}

void Draw(void)
{

	switch (GetMode())
	{
	case GAME_TITLE:
		// �^�C�g���̕`�揈��
		while (_kbhit())
		{
			(void)_getch();
		}
		DrawTitle();
		break;
	case GAME_MENU:
		// ���j���[�̍X�V����
		while (_kbhit())
		{
			(void)_getch();
		}
		DrawMenu();
		break;
	case GAME_TUTO:
		while (_kbhit())
		{
			(void)_getch();
		}
		DrawTuto();
		break;
	case GAME_INTRO:


		DrawBattle();
	
		break;
	case GAME_BATTLE:

		DrawBattle();

		break;
	case GAME_EVENT:
		// �t�B�[���h�\��

		//DrawField();
		while (_kbhit())
		{
			(void)_getch();
		}
		break;
	}
}

// ���[�h�̎擾�֐�
int GetMode(void)
{
	return mode;
}


// ���[�h���Z�b�g����֐�
void SetMode(int no)
{
	mode = no;
}

//�A�j���C�V�����̕`��frame���Ƃ̏���

