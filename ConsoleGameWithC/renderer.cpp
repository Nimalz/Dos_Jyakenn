#include "renderer.h"


//line��`�悷��֐�
void DrawLine(char* temp)
{
	printf("%s", temp);
}


//char�^�񎟌��z�񂩂�ۂ��ƃA�j���[�V������A�o����Binterval�͊eframe�̕\�����ԁiframetime�j,cnt�͔z�񒆂̉�frame�ڂ�\������̂��R���g���[������
void DrawFrame(int interval, char temp[][DISP_V], int* cnt)
{
	for (int y = 0; y < DISP_H; y++)
	{
		DrawLine(temp[y + *cnt * DISP_H]);
	}
	Sleep(interval);

}

//BufferLine�^�z�񂩂��ʂ�A�o����B
void printBufferFrame(const BufferLine temp[DISP_H])
{
	for (int i = 0; i < DISP_H; i++) {
		
		DrawLine(temp[i].line);
	}
}

void printBufferFrameWithIndex(const BufferLine temp[DISP_H],int index1,int index2)
{
	for (int i = index1; i < index2; i++) {

		DrawLine(temp[i].line);
	}
}

void printWithRenew(const BufferLine temp[DISP_H],BufferLine in)
{
	for (int i = 0; i < DISP_H; i++) {

		if (i!=in.lineNum-1)
			DrawLine(temp[i].line);
		else
			DrawLine(in.line);
	}
}

//des�͌���frame��ۑ�����BufferLine�z��Ain�͓���ւ�Bufferline
void BufferRenew(BufferLine des[DISP_H], BufferLine in)
{	
	des[in.lineNum-1] = in;
}

//des�͌���frame��ۑ�����BufferLine�z��Ain�͓���ւ�Bufferline�z��Aindex��in�̍s��
void BufferRewnwArray(BufferLine des[DISP_H], BufferLine in[], int index)
{
	for (int i = 0; i < index; i++)
	{
		BufferRenew(des, in[i]);
	}
}

void BufferFrameCopy(const BufferLine in[DISP_H], BufferLine des[DISP_H])
{
	for (int i = 0; i < DISP_H; i++)
	{
		des[i] = in[i];
	}
}

void CharToBufferline(char* charin, int index,BufferLine* des)
{
	des->line = charin;
	des->lineNum = index;
}