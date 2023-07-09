#include "main.h"
#include "player.h"



Player player[PLYAYE_MAX];
InputBuffer inputBuffer;

void InitPlayer(void)
{
	for (int i = 0; i < PLYAYE_MAX; i++)
	{
		player[i].hp = PLAYER_INIT_HP;
		player[i].Input = inputBuffer;
		initInputBuffer(&player[i].Input);
	}

}

void UninitPlayer(void)
{

}

void UpdatePlayer(void)
{

}

void DrawPlayer(void)
{
	;
}



Player* GetPlayer(int index)
{
	return &player[index];
}
