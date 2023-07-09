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

// シーン管理用
int mode;

int main()
{

	Init();

	//mode = GAME_MENU;
	while (1)
	{
		Update();	// 更新処理


		Draw();		// 描画処理
	}

	rewind(stdin);
	(void)_getch();

	Uninit();
	return 0;
}

void Init(void)
{
	// ランダムの初期化処理
	srand((unsigned)time(NULL));
	int mode = GAME_TITLE;

	// タイトルの初期化処理
	InitTitle();
	// メニューの初期化処理
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
		// タイトルの更新処理
		UpdateTitle();
		break;
	case GAME_MENU:
		// メニューの更新処理
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
		// フィールドの更新処理
		//UpdateField();
		break;
	}
}

void Draw(void)
{

	switch (GetMode())
	{
	case GAME_TITLE:
		// タイトルの描画処理
		while (_kbhit())
		{
			(void)_getch();
		}
		DrawTitle();
		break;
	case GAME_MENU:
		// メニューの更新処理
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
		// フィールド表示

		//DrawField();
		while (_kbhit())
		{
			(void)_getch();
		}
		break;
	}
}

// モードの取得関数
int GetMode(void)
{
	return mode;
}


// モードをセットする関数
void SetMode(int no)
{
	mode = no;
}

//アニメイシヨンの描画frameごとの処理

