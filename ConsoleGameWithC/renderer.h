#pragma once
#include "main.h"

#define SIZEOFBUFFERLINE    (sizeof(BufferLine))

struct BufferLine
{
	char* line;			//�`�悷�镶�����pointer
	int lineNum;		//���s�ڂɂ��̕������`�悷��̋L�^�ϐ�
};


void printBufferFrame(const BufferLine [DISP_H]);

void DrawLine(char*);
void DrawFrame(int, char[][DISP_V], int*);
void BufferRenew(BufferLine [DISP_H], BufferLine);
void BufferRewnwArray(BufferLine [DISP_H], BufferLine [], int);
void BufferFrameCopy(const BufferLine [DISP_H], BufferLine [DISP_H]);
void printWithRenew(const BufferLine[DISP_H], BufferLine);
void CharToBufferline(char*, int, BufferLine*);
void printBufferFrameWithIndex(const BufferLine[DISP_H],int, int);