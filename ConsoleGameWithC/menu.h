#pragma once


#define		ANI_FRAME		(10)	        //menuアニメーションのframe数
#define     ANI_TIME		(100)		    //menuアニメーションの各frameの表示時間
#define     ANI_LOOP_TIME   (80)			//カーソルのアニメーションの表示時間
#define     ANI_FLASH_TIME  (5)				//カーソルのアニメーションの表示時間


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

