#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define		DISP_H		    (24)	// １画面の縦サイズ
#define     DISP_V          (240)	// １画面の横サイズ (環境によって3byte文字使う可能性がある、実際の横サイズはDISP_V/3=80)

enum
{
	GAME_TITLE,
	GAME_MENU,
	GAME_TUTO,
	GAME_INTRO,
	GAME_BATTLE,
	GAME_EVENT,

	GMAE_MAX,
};


// Main OBJ
void Init(void);
void Uninit(void);
void Update(void);
void Draw(void);

// モードの取得関数
int GetMode(void);

// モードをセットする関数
void SetMode(int);

void DrawFrame(int, char [][DISP_V],int*);

