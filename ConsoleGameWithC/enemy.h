#pragma once
#include "skill.h"
#define ENEMY_SKILL_MAX (5)
#define DEBUT_ENEMY     (kakashi)

enum EnemyName
{
	kakashi,
	kani,
	doeromon,
	monkey,
};

struct Enemy
{
	int diff;			//“ïˆÕ“x§Œä•Ï”
	int hp;	
	int wazamax;		//g‚¦‚é‹Z‚Ì”
	int wazanum;        //Ÿ‰½”Ô–Ú‚Ì‹Z‚ğg‚¤
	bool rageFlag;     //–\‘–mode@flag
	EnemyName name;		
	SkillData oowaza;
	SkillData waza[ENEMY_SKILL_MAX];
};



void InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);

void LoadKakashi(void);
void LoadKani(void);
void LoadDoeromon(void);
void LoadMonkey(void);

void LoadEnemy(EnemyName);
Enemy* GetEnemy(void);

