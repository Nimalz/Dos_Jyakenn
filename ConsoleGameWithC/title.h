#pragma once


#define		COUNTDOWN_FRAME	(35)	// countdown部分のアニメーションのフレイム数
#define     BLOCK_FRAME     (10)	//　title部分■sceneからtitle画面まで変換するframeのpattern数
#define     LOOP_FRAME      (4)		// title画面表示する時、loopで表示するpatternの数
#define     COUNTDOWN_TIME  (100)	// countdown画面表示する時、各frameの表示時間（Sleep(COUNTDOWN_INT)）
#define     JYANKEN_TIME    (500)   // グウ　チョキ　パアの表示時間ｍｓ
#define     FLASH_TIME 		(45)	// 黒画面の表示時間ｍｓ
#define     BLOCK_TIME      (400)   // title画面直前のアニメーションの各frame表示時間
#define     LOOP_TIME       (1000)  // title画面の表示時間

enum
{
	TITLE_COUNTDOWN,
	TITLE_JYAKEN,
	TITLE_BLOCK,
	TITLE_LOOP,

	TITLE_MAX,
};


void InitTitle(void);
void UninitTitle(void);
void UpdateTitle(void);
void DrawTitle(void);


void UpdateCountdown(void);
void UpdateJyanken(void);
void UpdateBlock(void);
void UpdateLoop(void);

void DrawCountdown(void);
void DrawJyanken(void);
void DrawBlock(void);
void DrawLoop(void);

#ifdef _DEBUG
void DrawTest(void);
#endif