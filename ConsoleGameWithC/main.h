#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define		DISP_H		    (24)	// �P��ʂ̏c�T�C�Y
#define     DISP_V          (240)	// �P��ʂ̉��T�C�Y (���ɂ����3byte�����g���\��������A���ۂ̉��T�C�Y��DISP_V/3=80)

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

// ���[�h�̎擾�֐�
int GetMode(void);

// ���[�h���Z�b�g����֐�
void SetMode(int);

void DrawFrame(int, char [][DISP_V],int*);

