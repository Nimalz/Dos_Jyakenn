#pragma once

#include "input.h"
#define PLYAYE_MAX (1)
#define PLAYER_INIT_HP (10)
enum MOVE
{
	PLAYER_IDLE,
	PLAYER_GUU,
	PLAYER_CHOKI,
	PLAYER_PAA,

	PLAYER_MAX,
};

struct Player
{
	//int x;				//Playerâ°ç¿ïW
	//int y;				//Playerècç¿ïW
	int hp;
	char name[80];
	InputBuffer Input;
};

void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

Player* GetPlayer(int);

