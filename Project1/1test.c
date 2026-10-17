#include"game.h"


/*
  接下来的目标
		1.实现难度选择
		2.如果排的位置不是雷，周围没有雷，自动排开周围的雷
		3.加上排雷时间显示（每次排雷用了多久）
		4.标记雷功能
*/

void menu()
{
	printf("-------------------------\n");
	printf("----------1.play---------\n");
	printf("----------0.exit---------\n");
	printf("-------------------------\n");
}

int choose_difficulty()
{
	int input;
	printf("请选择难度：\n");
	printf("1.简单\n");
	printf("2.中等\n");
	printf("3.困难\n");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		printf("你选择了简单难度\n");
		return EASY_COUNT;
	case 2:
		printf("你选择了中等难度\n");
		return MEDIUM_COUNT;
	case 3:
		printf("你选择了困难难度\n");
		return HARD_COUNT;
	default:
		printf("选择错误，请重新选择\n");
		return -1;
	}
}
		
void game(int mine_count)
{
	char mine[ROWS][COLS];//雷区
	char show[ROWS][COLS];//显示区
	//初始化雷区和显示区
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//打印雷区和显示区
	Displayboard(show, ROW, COL);

	//布置雷区
	setmine(mine, ROW, COL, mine_count);

	Displayboard(mine, ROW, COL);

	//排雷
	findmine(mine, show, ROW, COL, mine_count);
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	//通过do...while循环实现菜单的循环选择，让游戏可以一直玩下去，直到选择退出
	do//循环菜单
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)//直接在switch语句内定义变量会报错，解决方法：1.把变量定义放在switch语句外面 2.在case语句内加大括号。
					  //不能定义在switch和case之间（会跳过）
		{
			
		case 1:
		{
			int mine_count = choose_difficulty();//switch语句内要定义变量时case语句要加大括号
			if (mine_count > 0)
			{
				game(mine_count);
			}
			else
			{
				printf("选择错误，请重新选择\n");
			}
			break;
		}
		case 0:
			printf("退出本局\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}

	} while (input != 0);
	

	return 0;
}