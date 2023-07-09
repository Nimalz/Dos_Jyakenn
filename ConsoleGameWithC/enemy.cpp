#include "enemy.h"
#include "renderer.h"
#include "skill.h"

EnemyName enemyname;
Enemy enemy;
int diff = 0;;

void LoadEnemy(EnemyName enemyname)
{
	diff++;
	switch (enemyname)
	{
	case kakashi:
		LoadKakashi();
		break;
	case kani:
		LoadKani();
		break;
	case doeromon:
		LoadDoeromon();
		break;
	case monkey:
		LoadMonkey();
		break;
	}
	
}

void InitEnemy(void)
{
	
	enemyname = DEBUT_ENEMY;
	LoadEnemy(enemyname);
	diff = 0;

}


void UninitEnemy(void)
{

}

void UpdateEnemy(void)
{
	enemy.wazanum++;
	if (enemy.wazanum == 2 * enemy.wazamax)
		enemy.rageFlag = true;
}

void DrawEnemy(void)
{

}



void LoadKakashi(void)
{
	Skilltable* Skilltable = GetSkillTable();
	enemy.diff = 1;
	enemy.hp = 5;
	enemy.name = EnemyName::kakashi;
	enemy.waza[0] = Skilltable->KakashiAtt1;
	enemy.waza[1] = Skilltable->KakashiAtt2;
	enemy.waza[2] = Skilltable->KakashiAtt3;
	enemy.wazamax = 3;
	enemy.wazanum = 0;
	enemy.rageFlag = false;
	enemy.oowaza = Skilltable->random;
}

void LoadKani(void)
{
	Skilltable* Skilltable = GetSkillTable();
	enemy.diff = diff;
	enemy.hp = 10+diff*rand()%2;
	enemy.name = EnemyName::kani;
	enemy.waza[0] = Skilltable->KaniAtt1;
	enemy.waza[1] = Skilltable->KaniAtt2;
	enemy.waza[2] = Skilltable->KaniAtt3;
	enemy.wazamax = 3;
	enemy.wazanum = 0;
	enemy.rageFlag = false;
	enemy.oowaza  = Skilltable->KaniOowaza;

}

void LoadDoeromon(void)
{
	;
}

void LoadMonkey(void)
{
	;
}



Enemy* GetEnemy(void)
{
	return &enemy;
}



