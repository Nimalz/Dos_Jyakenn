#pragma once
#include "skill.h"

void InitBattle(void);
void UninitBattle(void);
void UpdateBattle(void);
void DrawBattle(void);

void DrawBattleInput(void);
void DrawBattleDisp(void);

int syoubuCheck(SkillData* , SkillData*);

//bool DeadOrAlive(void);