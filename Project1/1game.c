#include "game.h"

//初始化雷区和显示区
void Initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}
//打印雷区和显示区
void Displayboard(char show[ROWS][COLS], int rows, int cols)
{
	for (int i = 0;i <= cols;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1;i <= rows;i++)
	{
		printf("%d ", i);
		for (int j = 1;j <= cols;j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//布置雷区
void setmine(char board[ROWS][COLS], int rows, int cols)
{
	int count = easy_count;
	while (count)//>=10次
	{
		int x = rand() % rows + 1;//随机获取位置
		int y = rand() % cols + 1;
		if (board[x][y] == '0')//如果没雷
		{
			board[x][y] = '1';//埋下雷
			count--;//限定条件
		}
	}



}

//计算周围雷数
static int Getminecount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
	//'数字'与数字之间的转换就是加减‘0’
}

//排查雷
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x;
	int y;
	int win = 0;
	while (win < row*col-easy_count)
	{
		printf("输入坐标：");
		scanf("%d,%d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("死了死了杂鱼杂鱼\n");
					Displayboard(mine, row, col);
					break;
				}
				else
				{
					int count = Getminecount(mine, x, y);
					show[x][y] = count + '0';
					Displayboard(show, row, col);
					win++;
					
				}
				
			}
			else
			{
				printf("已经输过");
				continue;
			}
		}
		else
		{
			printf("不存在该坐标");
			break;
		}
	}
	if (win == row * col-easy_count)
	{
		printf("WIN!!!");
		Displayboard(mine, row, col);
	}
}

