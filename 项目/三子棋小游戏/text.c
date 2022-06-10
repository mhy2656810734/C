#include"game.h"

void menu()
{
	printf("========欢迎来到五子棋游戏========\n");
	printf("======1.开始游戏   0.退出游戏=====\n");
	printf("==================================\n");
}


void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisPlay(board, ROW, COL);
	while (1)
	{
 		PlayMove(board, ROW, COL);
		DisPlay(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'Q')
		{
			break;
		}
		ComputerPlay(board, ROW, COL);
		DisPlay(board, ROW, COL); 
		ret = IsWin(board, ROW, COL);
		if (ret != 'Q')
		{
			break;
		}
	}
	if (ret == '#')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '*')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局\n");
	}

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	
	do
	{
		menu();
		printf("请输入你的选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}
