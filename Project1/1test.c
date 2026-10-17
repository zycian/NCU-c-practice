#include"game.h"

void menu()
{
	printf("-------------------------\n");
	printf("----------1.play---------\n");
	printf("----------0.exit---------\n");
	printf("-------------------------\n");
}

void game()
{
	char mine[ROWS][COLS];//雷区
	char show[ROWS][COLS];//显示区
	//初始化雷区和显示区
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//打印雷区和显示区
	Displayboard(show, ROW, COL);

	//布置雷区
	setmine(mine, ROW, COL);

	//Displayboard(mine, ROW, COL);

	//排雷
	findmine(mine, show, ROW, COL);
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do//循环菜单
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
		}
	} while (input == 1);
	

	return 0;
}