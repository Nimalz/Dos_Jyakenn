#pragma once


#define		ANI_FRAME		(10)	        //menu�A�j���[�V������frame��
#define     ANI_TIME		(100)		    //menu�A�j���[�V�����̊eframe�̕\������
#define     ANI_LOOP_TIME   (80)			//�J�[�\���̃A�j���[�V�����̕\������
#define     ANI_FLASH_TIME  (5)				//�J�[�\���̃A�j���[�V�����̕\������


enum
{
	MENU_ANI,
	MENU_LOOP,

};

enum 
{
	NEW,
	CONT,
	EXIT,

	MENU_MAX
};

void InitMenu(void);
void UninitMenu(void);
void UpdateMenu(void);
void DrawMenu(void);

void UpdateAni(void);
void DrawAni(void);

void UpdateMenuLoop(void);
void DrawMenuLoop(void);

int  GetCur(void);
void SetCur(int);

#ifdef _DEBUG
void menutest(void);

bool GetRenewFlag(void);
void SetRenewFlag(bool);

#endif

