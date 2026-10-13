//#define _CRT_SECURE_NO_WARNINGS   // VS 特有：关掉 scanf 的"不安全"警告，必须写在所有 #include 之前
//
//#include <stdio.h>
//#include <stdlib.h>                // standard(标准) + library(库)：rand/srand 都在这个头文件里
//#include <time.h>
//
///*
// * ============================================================
// *  P92 巩固练习：随机数
// *  知识点（背下来）：
// *    1. rand() 生成 0 ~ 32767 的随机整数（RAND_MAX = 32767）
// *    2. srand(种子) 决定 rand 从"随机数表"的哪一格开始取 —— 同一个种子，得到同一串数
// *    3. 用时间戳当种子：srand(time(NULL))，整个程序【只调用一次】，写在 main 开头
// *    4. 取 [min, max] 范围的通用公式：rand() % (max - min + 1) + min
// *  运行方式：编译后输入 1~4 选择题号
// * ============================================================
// */
//
///* ---------------- 第 1 题：通用随机函数 + 对照实验（已写好） ---------------- */
//// getRandom：get(获取) + Random(随机) → 返回 [min, max] 内的随机整数
//// random-read：先 rand() % (max-min+1) 得到 0~(max-min)，再 +min 平移到区间
//int getRandom(int min, int max)
//{
//	int num = rand() % (max - min + 1) + min;
//	return num;
//}
//
//void task1(void)
//{
//	printf("10 个 1~100 的随机数：\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d  ", getRandom(1, 100));
//	}
//	printf("\n");
//
//	printf("\n【必做对照实验】\n");
//	printf("1. 注释掉 main 里的 srand(time(NULL)) → 关掉程序重新运行一次 → 看两次结果是不是完全一样\n");
//	printf("2. 再把 srand 放回来 → 重新运行两次 → 结果变得不一样了\n");
//	printf("结论：随机数其实是'查表'，种子决定从哪一格开始查。种子不变 → 数列永远不变。\n");
//	printf("\n【思考坑】如果把 srand(time(NULL)) 写在循环里会怎样？\n");
//	printf("答：time() 精确到秒，同一秒种子相同 → 循环里每个数都取到表的同一格 → 10 个数一模一样。\n");
//}
//
///* ---------------- 第 2 题：掷骰子 10000 次，统计频率 ---------------- */
//void task2(void)
//{
//	// 还没学数组，只能用 6 个变量；记住这种啰嗦感，P95 数组一句 arr[point]++ 就搞定
//	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;   // c = count(计数)
//
//	for (int i = 0; i < 10000; i++)
//	{
//		int point = getRandom(1, 6);        // point(点数)
//
//		switch (point)
//        {
//        case 1:
//            c1++;
//            break;
//        case 2:
//            c2++;
//            break;
//        case 3:
//            c3++;
//            break;
//        case 4:
//            c4++;
//            break;
//        case 5:
//            c5++;
//            break;
//        case 6:
//            c6++;
//            break;
//        default:
//            break;
//        }
//		// TODO 2：用 switch(point) 给 c1~c6 里对应的那个 ++ （别忘了每个 case 配 break）
//	}
//
//	printf("1点：%d 次，占比 %.2f%%\n", c1, (double)c1 / 10000 * 100);
//	printf("2点：%d 次，占比 %.2f%%\n", c2, (double)c2 / 10000 * 100);
//	printf("3点：%d 次，占比 %.2f%%\n", c3, (double)c3 / 10000 * 100);
//	printf("4点：%d 次，占比 %.2f%%\n", c4, (double)c4 / 10000 * 100);
//	printf("5点：%d 次，占比 %.2f%%\n", c5, (double)c5 / 10000 * 100);
//	printf("6点：%d 次，占比 %.2f%%\n", c6, (double)c6 / 10000 * 100);
//	// 提示：%.2f 保留两位小数；%% 才表示一个真正的百分号
//	// 目标：每个面接近 16.67%
//}
//
///* ---------------- 第 3 题：随机算术题生成器 ---------------- */
//// makeQuestion：make(制作) + Question(问题) → 出一题并判卷，答对返回 1，答错返回 0
//int makeQuestion(void)
//{
//	int a = getRandom(1, 100);
//	int b = getRandom(1, 100);
//	int op = getRandom(0, 1);              // op = operator(运算符)：0 加法，1 减法
//	int right;                             // right(正确的)：标准答案
//	int answer;                            // answer(回答)：用户输入的答案
//
//	if (op == 0)
//	{
//		printf("%d + %d = ?  ", a, b);
//		right = a + b;
//	}
//	else
//	{
//		if (a < b)
//		{
//			int temp = 0;
//			temp = a;
//			a = b;
//			b = temp;
//		}
//		// TODO 3a：减法不能出负数。如果 a < b，用临时变量 temp 把两个数交换过来
//		printf("%d - %d = ?  ", a, b);
//		right = a - b;
//	}
//
//	scanf("%d", &answer);
//	
//	if (right  == answer)
//	{
//		printf("答对！\n");
//		return 1;
//	}
//
//	else
//	{
//		printf("答错，正确答案是 %d\n", right);
//		return 0;
//	}
//	// TODO 3b：比较 answer 和 right
//	//          相同 → printf("答对！\n"); return 1;
//	//          不同 → printf("答错，正确答案是 %d\n", right); return 0;
//	//return 0;                              // ← 写完 TODO 后删掉这一行
//}
//
//void task3(void)
//{
//	int score = 0;                         // score(分数)
//	for (int i = 1; i <= 5; i++)
//	{
//		printf("第%d题：", i);
//		score = score + makeQuestion();    // 答对加 1 分，答错加 0 分
//	}
//	printf("五题结束，你的得分：%d / 5\n", score);
//}
//
///* ---------------- 第 4 题（选做）：石头剪刀布，三局两胜 ---------------- */
//void task4(void)
//{
//	int myWin = 0;                         // my(我的) + Win(胜利)
//	int pcWin = 0;                         // pc = personal computer(电脑)
//	int round = 0;                         // round(回合)
//
//	while (myWin < 2 && pcWin < 2)         // 谁先赢够 2 局就结束 —— break 的兄弟用法：让条件失效
//	{
//		round++;
//		printf("\n第 %d 局，请出拳（1石头 2剪刀 3布）：", round);
//
//		int my;
//		scanf("%d", &my);
//
//		if (my < 1 || my > 3)              // 输入合法性检查
//		{
//			printf("只能输入 1~3，这局不算\n");
//			round--;
//			continue;                      // continue：跳过本轮循环剩下的部分
//		}
//
//		int pc = getRandom(1, 3);
//		printf("电脑出：%d\n", pc);
//
//		int r= (my - pc + 3) % 3;
//		if (r == 0)
//        {
//            printf("平局\n");
//        }
//        else if (r == 2)
//        {
//            printf("我赢\n");
//            myWin++;
//        }
//        else
//        {
//            printf("我输\n");
//            pcWin++;
//        }
//		// TODO 4：判定胜负
//		//   技巧版：int r = (my - pc + 3) % 3;   →  r==0 平局，r==1 我赢，r==2 我输
//		//   推不出来就用 switch / if 老实列 9 种组合，一样扎实
//		//   平局：什么都不加；我赢：myWin++；我输：pcWin++
//		//   最后 printf 本局结果
//	}
//
//	printf("\n最终战绩：我 %d : %d 电脑\n", myWin, pcWin);
//}
//
///* ---------------- 主函数：菜单选择 ---------------- */
//int main(void)
//{
//	srand(time(NULL));     // ★ 播种：整个程序只调用一次，必须放在最后 rand() 之前
//
//	printf("=== P92 随机数练习 ===\n");
//	printf("1 随机函数+对照实验   2 掷骰子统计   3 算术题生成器   4 石头剪刀布\n");
//	printf("请输入题号(1-4)：");
//
//	int choice;                            // choice(选择)
//	scanf("%d", &choice);
//
//	switch (choice)
//	{
//	case 1:
//		task1();
//		break;
//	case 2:
//		task2();
//		break;
//	case 3:
//		task3();
//		break;
//	case 4:
//		task4();
//		break;
//	default:
//		printf("题号只能是 1~4\n");
//		break;
//	}
//
//	return 0;
//}
