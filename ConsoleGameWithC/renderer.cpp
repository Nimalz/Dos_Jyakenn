#include "renderer.h"


//lineを描画する関数
void DrawLine(char* temp)
{
	printf("%s", temp);
}


//char型二次元配列から丸ごとアニメーションを輸出する。intervalは各frameの表示時間（frametime）,cntは配列中の何frame目を表示するのをコントロールする
void DrawFrame(int interval, char temp[][DISP_V], int* cnt)
{
	for (int y = 0; y < DISP_H; y++)
	{
		DrawLine(temp[y + *cnt * DISP_H]);
	}
	Sleep(interval);

}

//BufferLine型配列から画面を輸出する。
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

//desは現在frameを保存するBufferLine配列、inは入れ替えBufferline
void BufferRenew(BufferLine des[DISP_H], BufferLine in)
{	
	des[in.lineNum-1] = in;
}

//desは現在frameを保存するBufferLine配列、inは入れ替えBufferline配列、indexはinの行数
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