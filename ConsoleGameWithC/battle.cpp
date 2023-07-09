#include "battle.h"
#include "main.h"
#include "enemy.h"
#include "player.h"
#include "renderer.h"
#include "input.h"

int cursor_battle;        //ƒJ[ƒ\ƒ‹‚ÌŒ»İˆÊ’u‚ğ•Û‘¶‚·‚é
int kachimageFlag;		  //Ÿ‚¿•‰‚¯‚ÌŒ‹‰Ê‚ğ•Û‘¶ 1 PLAYERŸ‚¿ 0 ƒGƒlƒ~[Ÿ‚¿ 3 ‚Ğ‚«‚í‚¯
SkillData* ewaza;
SkillData* pwaza;
bool PlayerDead = false;
bool EnemyDown = false;

BufferLine UI_Battle[DISP_H] =
{
					 { "„¬„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„­\n", 1 },
					 { "„«                                QQQQQ                                   „«\n", 2},
					 { "„«                              ^          _                                 „«\n", 3},
					 { "„«                            ^              _                               „«\n", 4},
					 { "„«                          ^                  _                             „«\n", 5},
					 { "„«                        ^QQQQQQQQQQQ_                           „«\n", 6},
					 { "„«                           (                  )                              „«\n", 7},
					 { "„«                          (     ‚Ö     ‚Ö      )                             „«\n", 8},
					 { "„«                          (     ‚Ì     ‚Ì      )                             „«\n", 9},
					 { "„«                           (        ‚à        )                              „«\n",10},
					 { "„«                            (                )                               „«\n",11},
					 { "„«                             _    WWWW   ^                                 „«\n",12},
					 { "„«                               =          =                                  „«\n",13},
					 { "„«                                  _\\\\^                                     „«\n",14},
					 { "„«  _QQQQQQQQQQQQQQQ^| _QQQQQQQQQQQQQQQQQ^ „«\n",15},
					 { "„«  ==QQ_QQQQQQQQQ      | |  |    QQQQQQQQQQQQ^QQ== „«\n",16},
					 { "„«  ^      |   z      z     z   z^  _ _   z      z     z   z     |      _ „«\n",17},
					 { "„«          |  z   z z     z      |   /|  |  z   z z     z        z  |         „«\n",18},
					 { "„«          |QzQQzQzQzQQz  |  | |  |QzQQzQzQzQQz zQzQ|         „«\n",19},
					 { "„°„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„²\n",20 },
					 { "„«                                                                             „«\n",21},
					 { "„«                                                                             „«\n",22},
					 { "„«                                                                             „«\n",23},
					 { "„¯„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„®\n",24},
};

BufferLine UI_Battle1[DISP_H] =
{
					 { "„¬„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„­\n", 1 },
					 { "„«                                                                             „«\n", 2},
					 { "„«                                                                             „«\n", 3},
					 { "„«                                                                             „«\n", 4},
					 { "„«                                                                             „«\n", 5},
					 { "„«                                                                             „«\n", 6},
					 { "„«                                                                             „«\n", 7},
					 { "„«                                                                             „«\n", 8},
					 { "„«                                                                             „«\n", 9},
					 { "„«                                                                             „«\n",10},
					 { "„«                                                                             „«\n",11},
					 { "„«                                                                             „«\n",12},
					 { "„«                                                                             „«\n",13},
					 { "„«                                                                             „«\n",14},
					 { "„«                                                                             „«\n",15},
					 { "„«                                                                             „«\n",16},
					 { "„«                                                                             „«\n",17},
					 { "„«                                                                             „«\n",18},
					 { "„«                                                                             „«\n",19},
					 { "„°„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„²\n",20 },
					 { "„«                                                                             „«\n",21},
					 { "„«                                                                             „«\n",22},
					 { "„«                                                                             „«\n",23},
					 { "„¯„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„®\n",24},
};

BufferLine UI_Battle2[DISP_H] =
{
					 { "„¬„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„­\n", 1 },
					 { "„«                                                                             „«\n", 2},
					 { "„«                                                                             „«\n", 3},
					 { "„«                                                                             „«\n", 4},
					 { "„«                                                                             „«\n", 5},
					 { "„«                   _P_                      ^P^                        „«\n", 6},
					 { "„«                  /l _  _                  ^  ^  lR                     „«\n", 7},
					 { "„«                 | R R   |                b  /  /   |                     „«\n", 8},
					 { "„«                 _ ` ]R  R  œ      œ  /  / ]   ^                     „«\n", 9},
					 { "„«                   _ __ l  |  b|QQQ|b /  l __ ^                       „«\n",10},
					 { "„«                        _  _ ^       _^  ^                             „«\n",11},
					 { "„«                         ^_|   lQQl  |^_                             „«\n",12},
					 { "„«                       ^^_|             |^__                           „«\n",13},
					 { "„«                       ^^_|             |^__                           „«\n",14},
					 { "„«                       ^   /_QQQQQ^_   _                           „«\n",15},
					 { "„«                                                                             „«\n",16},
					 { "„«                                                                             „«\n",17},
					 { "„«                                                                             „«\n",18},
					 { "„«                                                                             „«\n",19},
					 { "„°„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„²\n",20 },
					 { "„«                                                                             „«\n",21},
					 { "„«                                                                             „«\n",22},
					 { "„«                                                                             „«\n",23},
					 { "„¯„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„®\n",24},
};

BufferLine PHP = { "„« ‚©‚©‚µ‚ÉP‚í‚ê‚½I                                                  „«\n",21 };
BufferLine temp1 = { "„« ŠiƒQ[‚İ‚½‚¢‚ÉƒRƒ}ƒ“ƒh‚ğ“ü—Í’†‚µ‚Äu‚¶‚á‚ñ‚¯‚ñv‚Åí‚¢‚Ü‚µ‚å‚¤I            „«\n",22 };
BufferLine temp2 = { "„«   WASD=ª©«¨            J=Î K=çõ L=†          ESC ƒRƒ}ƒ“ƒh•\    @@@ „«\n",23 };

void InitBattle(void)
{
	ewaza = &(GetEnemy()->waza[0]);


}

void UninitBattle(void)
{

}

void UpdateBattle(void)
{
	Player* player = GetPlayer(0);
	pwaza = skilldecode();
	Enemy* enemy = GetEnemy();


	if (enemy->rageFlag)
	{
		int random = rand() % (enemy->wazamax + 2);
		if (random > enemy->wazamax - 1)
			ewaza = &(enemy->oowaza);
		else
			ewaza = &(enemy->waza[random]);
	}
	else
	{
		if ((enemy->wazanum % enemy->wazamax) || (enemy->wazanum == 0))
			ewaza = &(enemy->waza[enemy->wazanum % enemy->wazamax]);
		else
			ewaza = &(enemy->oowaza);
	}
	if (pwaza->index == 999)
	{
		player->hp--;
		pwaza->move = (SkillAttribute)(rand() % 3);
	}
	if (ewaza->index == 999)
	{
		enemy->hp--;
		ewaza->move = (SkillAttribute)(rand() % 3);
	}
	kachimageFlag = syoubuCheck(pwaza, ewaza);


	switch (kachimageFlag)
	{
	case 0:
		player->hp -= ewaza->dam;
		break;
	case 1:
		enemy->hp -= pwaza->dam;
		break;
	case 3:
		break;
	}
	if (player->hp <= 0)
	{
		player->hp = 0;
		PlayerDead = true;
		return;
	}
	else if (enemy->hp <= 0)
	{
		enemy->hp = 0;
		EnemyDown = true;
		return;
	}


}

void DrawBattle(void)
{
	if (!GetInputDone())
	{
		DrawBattleInput();
	}
	else
	{
		DrawBattleDisp();
	}


}

//w—ß“ü—ÍŠ®—¹Œã‚Ì•`‰æˆ—
void DrawBattleDisp(void)
{
	Player* player = GetPlayer(0);
	Enemy* enemy = GetEnemy();
	int lenp = strlen(pwaza->movename);
	int lene = strlen(ewaza->movename);
	if (enemy->name == kakashi)
		printBufferFrameWithIndex(UI_Battle, 0, 20);
	else if (enemy->name == kani)
		printBufferFrameWithIndex(UI_Battle2, 0, 20);
	printf("„«");
	for (int i = 0; i < 36 - (lenp + lene) / 2; i++)
	{
		printf(" ");
	}

	printf("%s VS %s", pwaza->movename, ewaza->movename);
	for (int i = 0; i < 37 - (lenp + lene) / 2; i++)
	{
		printf(" ");
	}
	printf("„«\n");

	printf("„« PLAYER HP:%2d        ", player->hp);
	for (int i = 0; i < 9; i++)
	{
		printf(" ");
	}
	if (pwaza->move == guu)
		printf("Î‘®«");
	if (pwaza->move == choki)
		printf("çõ‘®«");
	if (pwaza->move == paa)
		printf("†‘®«");
	/*if (pwaza->move == SkillAttribute::random)
		printf("ƒ‰ƒ“ƒ_ƒ€");*/
	printf("  ");
	if (kachimageFlag == 1)
		printf(">");
	else if (kachimageFlag == 0)
		printf("<");
	else
		printf("=");
	printf("  ");
	if (ewaza->move == guu)
		printf("Î‘®«");
	if (ewaza->move == choki)
		printf("çõ‘®«");
	if (ewaza->move == paa)
		printf("†‘®«");
	/*if (ewaza->move == SkillAttribute::random)
		printf("ƒ‰ƒ“ƒ_ƒ€");*/

	for (int i = 0; i < 19; i++)
	{
		printf(" ");
	}
	printf("%2d:ENEMY HP", enemy->hp);
	printf("„«\n");

	printf("„«                   ");
	printf("ƒRƒ}ƒ“ƒhF");
	for (int i = 0; i < pwaza->input.len; i++)
	{
		switch (pwaza->input.Input[i])
		{
		case IS_UP_PRESSED:
			printf("ª");
			break;
		case IS_DOWN_PRESSED:
			printf("«");
			break;
		case IS_LEFT_PRESSED:
			printf("©");
			break;
		case IS_RIGHT_PRESSED:
			printf("¨");
			break;
		case IS_GUU_PRESSED:
			printf("Î");
			break;
		case IS_CHOKI_PRESSED:
			printf("çõ");
			break;
		case IS_PAA_PRESSED:
			printf("†");
			break;
		}
	}
	for (int i = 0; i < 48 - (pwaza->input.len) * 2; i++)
	{
		printf(" ");
	}

	printf("„«\n");

	if (enemy->name == kakashi)
		printBufferFrameWithIndex(UI_Battle, 23, 24);
	else if (enemy->name == kani)
		printBufferFrameWithIndex(UI_Battle2, 23, 24);

	SetInputDone(false);
	initInputBuffer(&player->Input);
	rewind(stdin);
	(void)_getch();
	if (PlayerDead)
	{
		system("cls");
		if (enemy->name == kakashi)
			printWithRenew(UI_Battle, { "„«ƒvƒŒƒCƒ„[‚ª“|‚³‚ê‚Ü‚µ‚½AAA                                               „«\n",21 });
		else if (enemy->name == kani)
			printWithRenew(UI_Battle2, { "„«ƒvƒŒƒCƒ„[‚ª“|‚³‚ê‚Ü‚µ‚½AAA                                               „«\n",21 });
		rewind(stdin);
		(void)_getch();
		SetMode(GAME_MENU);
		PlayerDead = false;
		InitPlayer();
		LoadEnemy(kakashi);
		SkillFukugenn();
		return;
	}

	if (EnemyDown)
	{
		system("cls");
		printWithRenew(UI_Battle1, { "„«ƒGƒlƒ~[‚ğ“|‚µ‚½BV‚µ‚¢‹Z‚ğŠo‚¦‚½‚©‚àc                           @        „«\n",21 });
		if (enemy->name == kakashi)
		{
			GetSkillTable()->KakashiAtt1.leanrned = true;
			GetSkillTable()->KakashiAtt2.leanrned = true;
			GetSkillTable()->KakashiAtt3.leanrned = true;
		}
		else if (enemy->name == kani)
		{
			GetSkillTable()->KaniAtt1.leanrned = true;
			GetSkillTable()->KaniAtt2.leanrned = true;
			GetSkillTable()->KaniAtt3.leanrned = true;

			GetSkillTable()->KaniOowaza.leanrned = true;
		}
		rewind(stdin);
		(void)_getch();
		Sleep(1000);
		printWithRenew(UI_Battle2, { "„«•Ï‚ÈŠI‚ÉŒ©‚Â‚©‚ç‚ê‚Ü‚µ‚½I                                          @       „«\n",21 });
		rewind(stdin);
		(void)_getch();
		Sleep(1000);
		SetMode(GAME_BATTLE);
		LoadEnemy(kani);
		EnemyDown = false;
		InitPlayer();

		return;
	}


	temp1 = { "„« Ÿ‚Í‰½‹Z‚ğg‚¤H                                   @@@@                 „«\n",22 };
}

//w—ß“ü—Í’†‚Ì•`‰æˆ—
void DrawBattleInput(void)
{
	Player* player = GetPlayer(0);
	Enemy* enemy = GetEnemy();
	if (enemy->name == kakashi)
	{
		
		printBufferFrameWithIndex(UI_Battle, 0, 20);
		DrawLine(temp1.line);
		DrawLine(UI_Battle[21].line);
		DrawLine(temp2.line);
		DrawLine(UI_Battle[23].line);
	}
	else if (enemy->name == kani)
	{
		
		printBufferFrameWithIndex(UI_Battle2, 0, 20);
		DrawLine(temp1.line);
		DrawLine(UI_Battle2[21].line);
		DrawLine(temp2.line);
		DrawLine(UI_Battle2[23].line);
	}


	for (int i = 0; i < player->Input.count; i++)
	{
		switch (player->Input.buffer[i])
		{
		case IS_UP_PRESSED:
			printf("%s", "ª");
			break;
		case IS_DOWN_PRESSED:
			printf("%s", "«");
			break;
		case IS_LEFT_PRESSED:
			printf("%s", "©");
			break;
		case IS_RIGHT_PRESSED:
			printf("%s", "¨");
			break;
		case IS_GUU_PRESSED:
			printf("%s", "Î");
			break;
		case IS_CHOKI_PRESSED:
			printf("%s", "çõ");
			break;
		case IS_PAA_PRESSED:
			printf("%s", "†");
			break;

		}
	}
	Sleep(100);
}

int syoubuCheck(SkillData* pin, SkillData* ein)
{
	//if (pin->movename)
	if (((ein->move - (pin->move)) == -1) || ((ein->move - (pin->move)) == 2))
	{
		return 0;//ƒGƒlƒ~[Ÿ—˜
	}
	else if (((ein->move - (pin->move)) == 1) || ((ein->move - (pin->move)) == -2))
	{
		return 1;//ƒvƒŒƒCƒ„[Ÿ—˜
	}

	return 3;//‚Ğ‚«‚í‚¯
}

