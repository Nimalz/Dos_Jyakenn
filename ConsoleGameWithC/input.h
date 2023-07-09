#pragma once
//#include "time.h"

#define MAX_BUFFER_SIZE		(5)

#define KBHIT() \
/*キー入力がなければ何もしない*/ \
if (!_kbhit())\
{\
/*画面クリア*/\
system("cls");	\
return;\
}

enum KeyMap
{
	KEY_NONE = 0,

	KEY_UP = 119,		//W
	KEY_DOWN = 115,		//S
	KEY_LEFT = 97,		//A
	KEY_RIGHT = 100,	//D

	KEY_UP_ARR = 72,	//↑
	KEY_DOWN_ARR = 80,	//↓
	KEY_LEFT_ARR = 75,	//←
	KEY_RIGHT_ARR = 77,	//↓

	KEY_GUU = 106,		//J
	KEY_CHOKI = 107,	 //K
	KEY_PAA = 108,		//L

	KEY_SAPCE = 32,		//SPACE
	KEY_ENTER = 13,		//ENTER 

	KEY_PAUSE = 27,		//ESC
	KEY_DEL = 8,		// \b
};

enum INPUTMODE
{
	INPUT_MENU,
	INPUT_BATTLE,
	//INPUT_PAUSE,

	INPUT_MAX,
};

enum KeyStates
{
	NONE = 0,

	IS_UP_PRESSED = 1,
	IS_DOWN_PRESSED = 1 << 1,
	IS_LEFT_PRESSED = 1 << 2,
	IS_RIGHT_PRESSED = 1 << 3,

	IS_GUU_PRESSED = 1 << 4,
	IS_CHOKI_PRESSED = 1 << 5,
	IS_PAA_PRESSED = 1 << 6,

	IS_PAUSE_PRESSED = 1 << 7,

	IS_CONFIRM_PRESSED = 1 << 8,

	IS_BACK_PRESSED = 1 << 9,

	END_SIGN = 1 << 10,			// \0として使う
};

struct InputBuffer
{
	KeyStates buffer[MAX_BUFFER_SIZE+1];
	int count;
};

void keyInputMenu(void);
void keyInputBattle(int);
void keyInput(INPUTMODE mode);

void InputProcess(void);

void initInputBuffer(InputBuffer*);

//KeyStates GetState(void);

bool GetInputDone(void);
void UpdateInput(void);

void SetInputDone(bool);