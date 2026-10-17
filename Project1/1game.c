#include "game.h"

//初始化雷区和显示区
void Initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	//遍历二维数组，初始化为0或者*
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
	for (int i = 0;i <= cols;i++)//打印列号		0 1 2 3 4 5 6 7 8 9
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1;i <= rows;i++)//打印接下来的行号和内容
	{
		printf("%d ", i);//打印行号

		for (int j = 1;j <= cols;j++)//打印在一行中的内容
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//布置雷区
void setmine(char board[ROWS][COLS], int rows, int cols, int mine_count)
{
	int count = mine_count;
	while (count)//>=10次
	{
		//随机获取位置
		int x = rand() % rows + 1;
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
	//‘0’是字符0的ASCII码值，减去8*'0'是为了将字符转换为数字，得到周围雷的数量。
	//'数字'与数字之间的转换就是加减‘0’
}

//排查雷
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col,int mine_count)
{
	int x;
	int y;
	int win = 0;//找到的雷数
	while (win < row*col-mine_count)
	{
		printf("输入坐标：");
		scanf("%d,%d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')//踩雷
				{
					printf("死了死了杂鱼杂鱼\n");
					Displayboard(mine, row, col);
					break;
				}
				else
				{
					int count = Getminecount(mine, x, y);//计算周围雷数
					show[x][y] = count + '0';//将数字转换为字符，此时字符的数字表示周围雷数
					Displayboard(show, row, col);//打印显示区
					win++;
				}
			}
			else
			{
				printf("已经输过");
				continue;//如果已经输入过该坐标，则提示已经输过，跳到输入坐标的循环继续输入
			}
		}
		else
		{
			printf("不存在该坐标");
			break;
		}
	}
	if (win == row * col - mine_count)//如果找到的雷数等于总格子数减去雷数，则说明玩家赢了
	{
		printf("WIN!!!");
		Displayboard(mine, row, col);
	}
}

