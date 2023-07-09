#include <stdio.h>
#include <string.h>
#include "main.h"
#include "skill.h"
#include "player.h"

Skilltable skilltable;
Skilltable skilltableBack;


Skilltable* GetSkillTable(void)
{
	return &skilltable;
}

SkillData* skilldecode(void)
{
	InputBuffer* Input = &(GetPlayer(0)->Input);
	Skilltable* pattern = GetSkillTable();
	if (SkillCheck(Input, &(pattern->KaniOowaza.input)) && (pattern->KaniOowaza.leanrned))
		return &(pattern->KaniOowaza);
	if (SkillCheck(Input, &(pattern->owapaa.input)) && (pattern->owapaa.leanrned))
		return &(pattern->owapaa);
	if (SkillCheck(Input, &(pattern->owachoki.input)) && (pattern->owachoki.leanrned))
		return &(pattern->owachoki);
	if (SkillCheck(Input, &(pattern->owaguu.input)) && (pattern->owaguu.leanrned))
		return &(pattern->owaguu);
	if (SkillCheck(Input, &(pattern->KakashiAtt1.input)) && (pattern->KakashiAtt1.leanrned))
		return &(pattern->KakashiAtt1);
	if (SkillCheck(Input, &(pattern->KakashiAtt2.input)) && (pattern->KakashiAtt2.leanrned))
		return &(pattern->KakashiAtt2);
	if (SkillCheck(Input, &(pattern->KakashiAtt3.input)) && (pattern->KakashiAtt3.leanrned))
		return &(pattern->KakashiAtt3);
	if (SkillCheck(Input, &(pattern->KaniAtt3.input)) && (pattern->KaniAtt3.leanrned))
		return &(pattern->KaniAtt3);
	if (SkillCheck(Input, &(pattern->KaniAtt2.input)) && (pattern->KaniAtt2.leanrned))
		return &(pattern->KaniAtt2);
	if (SkillCheck(Input, &(pattern->KaniAtt1.input)) && (pattern->KaniAtt1.leanrned))
		return &(pattern->KaniAtt1);
	if (SkillCheck(Input, &(pattern->paa1.input)) && (pattern->paa1.leanrned))
		return &(pattern->paa1);
	if (SkillCheck(Input, &(pattern->choki1.input)) && (pattern->choki1.leanrned))
		return &(pattern->choki1);
	if (SkillCheck(Input, &(pattern->guu1.input)) && (pattern->guu1.leanrned))
		return &(pattern->guu1);



	return &(pattern->random);
}



int SkillCheck(const InputBuffer* str, const SkillInput* substr)
{
	int len1 = str->count - 1;
	int len2 = substr->len;

	for (int i = 0; i <= len1 - len2; i++) {
		int j;


		for (j = 0; j < len2; j++) {
			if (str->buffer[i + j] != substr->Input[j])
				break;
		}


		if (j == len2)
			return len2;
	}


	return 0;
}

void DrawSkillTable(void)
{
	Skilltable* table = GetSkillTable();
	system("cls");
	printf("技一覧      　　    属性      　  　  入力コマンド\n\n");
	FetchSkillInput();

	rewind(stdin);
	(void)_getch();
}

void FetchSkillInput(void)
{	
	Skilltable* table = GetSkillTable();
	SkillData SkillArray[14] = {table->guu1,table->choki1,table->paa1,table->KakashiAtt1,table->KakashiAtt2,table->KakashiAtt3,
		table->KaniAtt1,table->KaniAtt2,table->KaniAtt3,table->owaguu,table->owachoki,table->owapaa,table->KaniOowaza,table->random};
	for (int i = 0; i < 14; i++)
	{
		if (SkillArray[i].leanrned)
		{
			printf("%-20s", SkillArray[i].movename);
			if (SkillArray[i].move == guu)
				printf("石属性　");
			if (SkillArray[i].move == choki)
				printf("鋏属性　");
			if (SkillArray[i].move == paa)
				printf("紙属性　");
			if (SkillArray[i].move == SkillAttribute::random)
				printf("ランダム");
			printf("          ");
			if (i == 13)
			{
				printf("適当");
				break;
			}
			for (int j = 0; j < SkillArray[i].input.len; j++)
			{
				switch (SkillArray[i].input.Input[j])
				{
				case IS_UP_PRESSED:
					printf("↑");
					break;
				case IS_DOWN_PRESSED:
					printf("↓");
					break;
				case IS_LEFT_PRESSED:
					printf("←");
					break;
				case IS_RIGHT_PRESSED:
					printf("→");
					break;
				case IS_GUU_PRESSED:
					printf("石");
					break;
				case IS_CHOKI_PRESSED:
					printf("鋏");
					break;
				case IS_PAA_PRESSED:
					printf("紙");
					break;
				}
			}
			printf("\n");
		}
	}
	
}

void SkillFukugenn(void)
{
	skilltable = skilltableBack;
}
