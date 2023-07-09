#include "tutorial.h"
#include "renderer.h"
#include "main.h"
#include "player.h"

int control = 0;
BufferLine current;
//BufferLine temp2;
//BufferLine temp3;
BufferLine UI_Intro[DISP_H] =
{
					 { "��������������������������������������������������������������������������������������������������������������������������������������������������������������\n", 1 },
					 { "��                                �Q�Q�Q�Q�Q                                   ��\n", 2},
					 { "��                              �^          �_                                 ��\n", 3},
					 { "��                            �^              �_                               ��\n", 4},
					 { "��                          �^                  �_                             ��\n", 5},
					 { "��                        �^�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�_                           ��\n", 6},
					 { "��                           (                  )                              ��\n", 7},
					 { "��                          (     ��     ��      )                             ��\n", 8},
					 { "��                          (     ��     ��      )                             ��\n", 9},
					 { "��                           (        ��        )                              ��\n",10},
					 { "��                            (                )                               ��\n",11},
					 { "��                             �_     ��   �@�^                                ��\n",12},
					 { "��                               =          =                                  ��\n",13},
					 { "��                                  �_\\\\�^                                     ��\n",14},
					 { "��  �_�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�^| �_�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�^ ��\n",15},
					 { "��  ==�Q�Q�_�Q�Q�Q�Q�Q�Q�Q�Q�Q      | |  |    �Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�^�Q�Q== ��\n",16},
					 { "��  �^      |   z      z     z   z�^  �_ �_   z      z     z   z     |      �_ ��\n",17},
					 { "��          |  z   z z     z      |   /|  |  z   z z     z        z  |         ��\n",18},
					 { "��          |�Qz�Q�Qz�Qz�Qz�Q�Qz  |  | |  |�Qz�Q�Qz�Qz�Qz�Q�Qz z�Qz�Q|         ��\n",19},
					 { "��������������������������������������������������������������������������������������������������������������������������������������������������������������\n",20 },
					 { "��                                                                             ��\n",21},
					 { "��                                                                             ��\n",22},
					 { "��                                                                             ��\n",23},
					 { "��������������������������������������������������������������������������������������������������������������������������������������������������������������\n",24},
};

//BufferLine narry1 =  { "���u����񂯂�v�̐��E�ւ悤����                                             ��\n",21 }; 
void InitTuto(void)
{
	control = 0;
}

void UpdateTuto(void)
{
	control++;
	switch (control)
	{
	case 1:
		system("cls");
		CharToBufferline("���u����񂯂�v�̐��E�ւ悤�����B                                             ��\n", 21, &current);
		system("cls");
		break;
	case 2:
		system("cls");
		UI_Intro[20].line = current.line;
		CharToBufferline("�� �l�͂������ł��B�@�@�@�@�@�@�@�@�@�@�@                                      ��\n", 22, &current);
		break;
	case 3:
		system("cls");
		UI_Intro[20].line = current.line;
		CharToBufferline("�� ���̐��E�͕|����ł��B�@�@�@�@�@�@�@                               �@       ��\n", 22, &current);
		break;
	case 4:
		system("cls");
		UI_Intro[20].line = current.line;
		CharToBufferline("�� �u����񂯂�v���ł��Ȃ����̂͐����鉿�l���Ȃ�����B            �@�@�@�@    ��\n", 22, &current);
		break;
	case 5:
		system("cls");
		UI_Intro[20].line = current.line;
		CharToBufferline("�� ���Ȃ��͂����Ɓu����񂯂�v�ł��܂��H                           �@       ��\n", 22, &current);
		break;
	case 6:
		system("cls");
		UI_Intro[20].line = "��                                                                             ��\n";
		UI_Intro[11].line = "��                             �_    WWWW  �@�^                                ��\n";
		CharToBufferline("�� �������ɏP��ꂽ�I                   �@                   �@�@�@�@�@�@�@    ��\n",21, &current);
		break;

	}

}

void DrawTuto(void)
{
	if (control)
	{
		printWithRenew(UI_Intro, current);
	
		rewind(stdin);
		(void)_getch();
		if (control==6)
		SetMode(GAME_INTRO);
	}


}