// 函数功能实现模块

#include"game.h"

// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			board[x][y] = ' ';
		}
	}
}
void DisPlay(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		//打印一行数据
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
	printf("\n");
}

// 玩家开始下棋
void PlayMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");
	printf("请选择你要下棋的位置：\n");
	// 首先对玩家输入的坐标进行判断
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x < 1 || x > 3 || y < 0 || y > 3)
		{
			printf("你输入的位置有误,请重新输入:\n");
		}
		else
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新选择\n");
			}
		}
	}
}

// 电脑下棋
void  ComputerPlay(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		 x = rand() % row;
		 y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}

}

// 判断是不是满了

int isFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//判断获胜
char IsWin(char board[ROW][COL], int row, int col)
{
	// 分析获胜情况：1.玩家获胜 2.电脑获胜 3.平局 4 ：Q 继续
	// 横三列
	for (int i = 0; i < row; i++)
	{
		if (board[i][1] == board[i][2] && board[i][1] == board[i][0] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	// 竖三行
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] &&board[1][j] !=' ')
		{
			return board[1][j];
		}
	}
	// 两条对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (isFull(board, ROW, COL) == 1)
	{
		return "P";
	}
	return 'Q';
}
