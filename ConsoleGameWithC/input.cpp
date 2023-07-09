#include "main.h"
#include "input.h"
#include "menu.h"
#include "player.h"
#include "renderer.h"
#include "skill.h"
KeyStates state = KeyStates::NONE;		//key入力状態を保存する
bool InputOkFlag = true;
bool InputDone = false;

BufferLine BufferFrame1[DISP_H] =
{
					 { "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n", 1 },
					 { "┃           ■        ■          ■                ■      ■  ■■          ┃\n",2},
					 { "┃           ■■■■            ■                ■        ■                ┃\n",3},
					 { "┃                                                                             ┃\n",4},
					 { "┃                                ■                                           ┃\n",5},
					 { "┃                  ■              ■          ■                             ┃\n",6},
					 { "┃                  ■        ■■■■■■      ■                             ┃\n",7},
					 { "┃            ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓             ┃\n",8},
					 { "┃            ┃      　             　　　　　　　　　　　       ┃             ┃\n",9},
					 { "┃            ┃  遊び方：            　　　　　　　　　　　      ┃             ┃\n",10},
					 { "┃            ┃      格ゲーみたいにwasd或いは↑←↓→KEY　　 　　┃             ┃\n",11},
					 { "┃            ┃      と　J　K　Lでコマンドを入力し、　　　　　   ┃             ┃\n",12},
					 { "┃            ┃      SPACE KEY或いはENTER　KEYで確認する。       ┃             ┃\n",13},
					 { "┃            ┃      「じゃんけん」を武器にして、　　　          ┃             ┃\n",14},
					 { "┃            ┃       敵と戦いましょう！                         ┃             ┃\n",15},
					 { "┣━━━━━━━━━━━━┫　　　　　　　　　　　　　　　　　　　        　　┣━━━━━━━━━━━━━┫\n",16 },
					 { "┃            ┃                                                  ┃             ┃\n",17},
					 { "┃            ┃                     　　　　                     ┃             ┃\n",18},
					 { "┃            ┃                                                  ┃             ┃\n",19},
					 { "┃            ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛             ┃\n",20},
					 { "┃                                                                             ┃\n",21},
					 { "┃                                   EXIT                                      ┃\n",22},
					 { "┃                                                                             ┃\n",23},
					 { "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",24},
};

//curはカーソル現在位置を保存する、optionMaxはmenu内選択可能なoptionな最大数、INPUTMODEは今の操作mode
void keyInputMenu(void)
{
	InputProcess();
	switch (state)
	{
	case IS_UP_PRESSED:	// カーソルを上へ移動する
		SetCur((GetCur() + MENU_MAX - 1) % MENU_MAX);
		break;
	case IS_DOWN_PRESSED:	// カーソルを下へ移動する
		SetCur((GetCur() + 1) % MENU_MAX);
		break;
	case IS_CONFIRM_PRESSED:
		switch (GetCur())
		{
		case NEW:			
			SetMode(GAME_TUTO);// フィールドへシーン遷移する
			break;
		case CONT:
			printBufferFrame(BufferFrame1);
			rewind(stdin);
			(void)_getch();
			break;
		case EXIT:
			exit(-1);
			break;
		}
	}

}

void keyInputBattle(int index)
{
	// キー入力処理

	InputProcess();
	Player* player = GetPlayer(index);

	if (InputOkFlag)
	{
		switch (state)
		{
		case IS_UP_PRESSED:
			player->Input.buffer[player->Input.count] = IS_UP_PRESSED;
			player->Input.count++;
			break;
		case IS_DOWN_PRESSED:
			player->Input.buffer[player->Input.count] = IS_DOWN_PRESSED;
			player->Input.count++;
			break;
		case IS_LEFT_PRESSED:
			player->Input.buffer[player->Input.count] = IS_LEFT_PRESSED;
			player->Input.count++;

			break;
		case IS_RIGHT_PRESSED:
			player->Input.buffer[player->Input.count] = IS_RIGHT_PRESSED;
			player->Input.count++;
			break;
		case IS_GUU_PRESSED:
			player->Input.buffer[player->Input.count] = IS_GUU_PRESSED;
			player->Input.count++;
			break;
		case IS_CHOKI_PRESSED:
			player->Input.buffer[player->Input.count] = IS_CHOKI_PRESSED;
			player->Input.count++;
			break;
		case IS_PAA_PRESSED:
			player->Input.buffer[player->Input.count] = IS_PAA_PRESSED;
			player->Input.count++;
			break;
		case IS_PAUSE_PRESSED:
			DrawSkillTable();
			break;
		case IS_BACK_PRESSED:
			if (player->Input.count > 0)
			{
				player->Input.buffer[player->Input.count - 1] = NONE;
				player->Input.count--;
			}
			break;
		case IS_CONFIRM_PRESSED:
			if (player->Input.count != 0)
			{
				player->Input.buffer[player->Input.count] = END_SIGN;
				player->Input.count++;
				InputDone = true;
			}
			
			break;
		}
	}
	else
	{
		switch (state)
		{
		case IS_BACK_PRESSED:
			player->Input.buffer[player->Input.count - 1] = NONE;
			player->Input.count--;
			InputOkFlag = true;
			break;
		case IS_CONFIRM_PRESSED:
			player->Input.buffer[player->Input.count] = END_SIGN;
			player->Input.count++;
			InputDone = true;
			break;
		}

	}

	if (player->Input.count == (MAX_BUFFER_SIZE))
	{
		InputOkFlag = false;
	}

}

void initInputBuffer(InputBuffer* buffer)
{
	for (int i = 0; i < MAX_BUFFER_SIZE; i++)
	{
		buffer->buffer[i] = KeyStates::NONE;
	}
	buffer->count = 0;
	InputOkFlag = true;
	InputDone = false;
}

void InputProcess()
{
	state = NONE;
	int key;
	rewind(stdin);
	key = _getch();

	if (key == 0 || key == 0xe0)
		key = _getch();
	switch (key)
	{
	case KEY_UP:
	case KEY_UP_ARR:
		state = (KeyStates)(state | IS_UP_PRESSED);
		break;
	case KEY_DOWN:
	case KEY_DOWN_ARR:
		state = (KeyStates)(state | IS_DOWN_PRESSED);
		break;
	case KEY_LEFT:
	case KEY_LEFT_ARR:
		state = (KeyStates)(state | IS_LEFT_PRESSED);
		break;
	case KEY_RIGHT:
	case KEY_RIGHT_ARR:
		state = (KeyStates)(state | IS_RIGHT_PRESSED);
		break;
	case KEY_GUU:
		state = (KeyStates)(state | IS_GUU_PRESSED);
		break;
	case KEY_CHOKI:
		state = (KeyStates)(state | IS_CHOKI_PRESSED);
		break;
	case KEY_PAA:
		state = (KeyStates)(state | IS_PAA_PRESSED);
		break;
	case KEY_PAUSE:
		state = (KeyStates)(state | IS_PAUSE_PRESSED);
		break;
	case KEY_SAPCE:
	case KEY_ENTER:
		state = (KeyStates)(state | IS_CONFIRM_PRESSED);
		break;
	case KEY_DEL:
		state = (KeyStates)(state | IS_BACK_PRESSED);
		break;
	default:
		state = (KeyStates)key;
		break;
	}


}

void UpdateInput(void)
{
	KBHIT();

	keyInputBattle(0);

	system("cls");
}

//KeyStates GetState(void)
//{
//	return state;
//}

bool GetInputDone(void)
{
	return InputDone;
}

void SetInputDone(bool in)
{
	InputDone = in;
}

