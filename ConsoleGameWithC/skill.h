#pragma once
#include "input.h"

enum SkillAttribute
{
	guu,
	choki,
	paa,
	pistol,//���\�U���i�����g�p�j

	random = 999,      

};

struct SkillInput
{
	KeyStates Input[MAX_BUFFER_SIZE];		//�A���w��
	int len;			//�A���w�߂̒���
};

struct SkillData
{
	SkillInput input;
	char* movename;
	SkillAttribute move;
	int dam;
	int index;			//�Z�ԍ�
	bool leanrned;      //Player �����̋Z���g���邩�H�@true yes,false no
};


struct Skilltable
{
	SkillData guu1	   = { {{IS_GUU_PRESSED,},1}, "���ʃO�[", guu, 1,0,true };
	SkillData choki1   = { {{IS_CHOKI_PRESSED,},1}, "���ʃ`���L",choki,1,1,true };
	SkillData paa1     = { {{IS_PAA_PRESSED,},1}, "���ʃp�[",paa,1,2,true };
	
	SkillData KaniAtt1 = { {{IS_CHOKI_PRESSED,IS_CHOKI_PRESSED},2}, "�N���u�n���}�[",choki,1,3,false };
	SkillData KaniAtt2 = { {{IS_RIGHT_PRESSED,IS_DOWN_PRESSED,IS_RIGHT_PRESSED,IS_CHOKI_PRESSED},4}, "���I���I�I",choki,2,4,false };
	SkillData KaniAtt3 = { {{IS_DOWN_PRESSED,IS_RIGHT_PRESSED,IS_GUU_PRESSED},3}, "�I�����I", guu, 1,5,false };

	SkillData KakashiAtt1 = { {{IS_RIGHT_PRESSED,IS_RIGHT_PRESSED,IS_PAA_PRESSED},3}, "�p�[~~~~", paa, 1,6,false };
	SkillData KakashiAtt2 = { {{IS_LEFT_PRESSED,IS_LEFT_PRESSED,IS_CHOKI_PRESSED},3}, "�`���L�`���L~~", choki, 1,7,false };
	SkillData KakashiAtt3 = { {{IS_DOWN_PRESSED,IS_UP_PRESSED,IS_GUU_PRESSED},3}, "�O�b�O�[~~", guu, 1,8,false };

	SkillData    owaguu   = { {{IS_GUU_PRESSED,IS_GUU_PRESSED,IS_GUU_PRESSED,IS_GUU_PRESSED,IS_GUU_PRESSED},5},"�A�����ʃO�[",guu,2,9,true};
	SkillData    owachoki = { {{IS_CHOKI_PRESSED,IS_CHOKI_PRESSED,IS_CHOKI_PRESSED,IS_CHOKI_PRESSED,IS_CHOKI_PRESSED},5},"�A�����ʃ`���L",choki,2,10,true};
	SkillData    owapaa   = { {{IS_PAA_PRESSED,IS_PAA_PRESSED,IS_PAA_PRESSED,IS_PAA_PRESSED,IS_PAA_PRESSED},5},"�A�����ʃp�[",paa,2,11,true};
	SkillData  KaniOowaza = { {{IS_DOWN_PRESSED,IS_RIGHT_PRESSED,IS_DOWN_PRESSED,IS_RIGHT_PRESSED,IS_GUU_PRESSED},5}, "�E�ӊI�����I�I�I�I�I",guu,3,12,false };


	SkillData random     = { {{IS_LEFT_PRESSED,IS_LEFT_PRESSED,IS_LEFT_PRESSED,IS_LEFT_PRESSED,IS_LEFT_PRESSED},5}, "��邠����",SkillAttribute::random, 1,999,true };
};



Skilltable* GetSkillTable(void);
SkillData* skilldecode(void);
int SkillCheck(const InputBuffer*, const SkillInput*);
void DrawSkillTable(void);
void FetchSkillInput(void);
void SkillFukugenn(void);