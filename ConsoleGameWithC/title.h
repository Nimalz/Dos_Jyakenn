#pragma once


#define		COUNTDOWN_FRAME	(35)	// countdown�����̃A�j���[�V�����̃t���C����
#define     BLOCK_FRAME     (10)	//�@title������scene����title��ʂ܂ŕϊ�����frame��pattern��
#define     LOOP_FRAME      (4)		// title��ʕ\�����鎞�Aloop�ŕ\������pattern�̐�
#define     COUNTDOWN_TIME  (100)	// countdown��ʕ\�����鎞�A�eframe�̕\�����ԁiSleep(COUNTDOWN_INT)�j
#define     JYANKEN_TIME    (500)   // �O�E�@�`���L�@�p�A�̕\�����Ԃ���
#define     FLASH_TIME 		(45)	// ����ʂ̕\�����Ԃ���
#define     BLOCK_TIME      (400)   // title��ʒ��O�̃A�j���[�V�����̊eframe�\������
#define     LOOP_TIME       (1000)  // title��ʂ̕\������

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