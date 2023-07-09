#pragma once
#include "input.h"

enum SkillAttribute
{
	guu,
	choki,
	paa,
	pistol,//万能攻撃（今未使用）

	random = 999,      

};

struct SkillInput
{
	KeyStates Input[MAX_BUFFER_SIZE];		//輸入指令
	int len;			//輸入指令の長さ
};

struct SkillData
{
	SkillInput input;
	char* movename;
	SkillAttribute move;
	int dam;
	int index;			//技番号
	bool leanrned;      //Player がこの技を使えるか？　true yes,false no
};


struct Skilltable
{
	SkillData guu1	   = { {{IS_GUU_PRESSED,},1}, "普通グー", guu, 1,0,true };
	SkillData choki1   = { {{IS_CHOKI_PRESSED,},1}, "普通チョキ",choki,1,1,true };
	SkillData paa1     = { {{IS_PAA_PRESSED,},1}, "普通パー",paa,1,2,true };
	
	SkillData KaniAtt1 = { {{IS_CHOKI_PRESSED,IS_CHOKI_PRESSED},2}, "クラブハンマー",choki,1,3,false };
	SkillData KaniAtt2 = { {{IS_RIGHT_PRESSED,IS_DOWN_PRESSED,IS_RIGHT_PRESSED,IS_CHOKI_PRESSED},4}, "昇蟹拳！！",choki,2,4,false };
	SkillData KaniAtt3 = { {{IS_DOWN_PRESSED,IS_RIGHT_PRESSED,IS_GUU_PRESSED},3}, "蟹動拳！", guu, 1,5,false };

	SkillData KakashiAtt1 = { {{IS_RIGHT_PRESSED,IS_RIGHT_PRESSED,IS_PAA_PRESSED},3}, "パー~~~~", paa, 1,6,false };
	SkillData KakashiAtt2 = { {{IS_LEFT_PRESSED,IS_LEFT_PRESSED,IS_CHOKI_PRESSED},3}, "チョキチョキ~~", choki, 1,7,false };
	SkillData KakashiAtt3 = { {{IS_DOWN_PRESSED,IS_UP_PRESSED,IS_GUU_PRESSED},3}, "グッグー~~", guu, 1,8,false };

	SkillData    owaguu   = { {{IS_GUU_PRESSED,IS_GUU_PRESSED,IS_GUU_PRESSED,IS_GUU_PRESSED,IS_GUU_PRESSED},5},"連続普通グー",guu,2,9,true};
	SkillData    owachoki = { {{IS_CHOKI_PRESSED,IS_CHOKI_PRESSED,IS_CHOKI_PRESSED,IS_CHOKI_PRESSED,IS_CHOKI_PRESSED},5},"連続普通チョキ",choki,2,10,true};
	SkillData    owapaa   = { {{IS_PAA_PRESSED,IS_PAA_PRESSED,IS_PAA_PRESSED,IS_PAA_PRESSED,IS_PAA_PRESSED},5},"連続普通パー",paa,2,11,true};
	SkillData  KaniOowaza = { {{IS_DOWN_PRESSED,IS_RIGHT_PRESSED,IS_DOWN_PRESSED,IS_RIGHT_PRESSED,IS_GUU_PRESSED},5}, "殺意蟹動拳！！！！！",guu,3,12,false };


	SkillData random     = { {{IS_LEFT_PRESSED,IS_LEFT_PRESSED,IS_LEFT_PRESSED,IS_LEFT_PRESSED,IS_LEFT_PRESSED},5}, "わるあがき",SkillAttribute::random, 1,999,true };
};



Skilltable* GetSkillTable(void);
SkillData* skilldecode(void);
int SkillCheck(const InputBuffer*, const SkillInput*);
void DrawSkillTable(void);
void FetchSkillInput(void);
void SkillFukugenn(void);