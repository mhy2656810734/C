#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROW][COL], int row, int col);
void DisPlay(char board[ROW][COL], int row, int col);
void PlayMove(char board[ROW][COL], int row, int col);
void  ComputerPlay(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);
int isFull(char board[ROW][COL], int row, int col);
