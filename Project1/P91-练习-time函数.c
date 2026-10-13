//
//#define _CRT_SECURE_NO_WARNINGS   // VS 特有：关掉 scanf 的"不安全"警告，必须写在所有 #include 之前
//
//#include <stdio.h>
//#include <time.h>
//#include <math.h>
//
///*
// * ============================================================
// *  P91 巩固练习：C语言常见函数 time()
// *  知识点（背下来）：
// *    1. time(NULL)：返回"时间戳" —— 1970-01-01 00:00:00 到此刻的总秒数
// *    2. 两次 time(NULL) 相减 = 中间经过的秒数 → 这就是"掐表计时"
// *    3. time_t 本质是 64 位整数，我这里直接用 long long 接，打印用 %lld
// *    4. 下一节 P92 会用它当随机数种子：srand(time(NULL))
// *  运行方式：编译后输入 1~4 选择题号
// * ============================================================
// */
//
///* ---------------- 第 1 题：打印时间戳 + 忙等 5 秒（示范，已写好） ---------------- */
//// task(任务)
//void task1(void)
//{
//	long long start = time(NULL);      // time(时间)：拿到"开始"这一刻的时间戳
//	printf("开始时间戳：%lld\n", start);
//
//	// 忙等：循环体是空的，全靠条件变化退出
//	// 注意：while(...) 后面千万不能多写一个分号，否则变成死循环
//	// 思考：这 5 秒里 CPU 在干什么？（答：100% 空转，跟 Sleep(5000) 让出 CPU 完全不同）
//	while (time(NULL) - start < 5)
//	{
//	}
//
//	long long end = time(NULL);        // end(结束)
//	printf("结束时间戳：%lld\n", end);
//	printf("中间经过：%lld 秒\n", end - start);
//}
//
///* ---------------- 第 2 题：秒数换算成 x天x时x分x秒 ---------------- */
//// 你还没学指针 → 一个函数只能返回一个值 → 所以拆成 4 个函数
//// 记住这种"憋屈感"，P114 学指针解决的第一个问题就是这个
//long long getDay(long long s)    // get(获取) + Day(天)
//{
//	long long Day = s/86400;
//	// TODO 1：一天 86400 秒，返回 s / 86400
//	return Day;                       // ← 写完 TODO 后删掉这一行
//}
//
//int getHour(long long s)   // get + Hour(小时)
//{
//	int Hour =s%86400/3600;
//	// TODO 2：先去掉整天（s % 86400），再除以 3600
//	return Hour;
//}
//
//int getMin(long long s)    // get + Minute(分)
//{
//	int Min = s % 3600 / 60;
//	// TODO 3：s % 3600 / 60  （% 和 / 优先级相同、从左到右算）
//	return Min ;
//}
//
//int getSec(long long s)    // get + Second(秒)
//{
//	int Sec = s % 60;
//	// TODO 4：s % 60
//	return Sec;
//}
//
//void task2(void)
//{
//	long long s;
//	printf("请输入总秒数：");
//	scanf("%lld", &s);
//	// 自测：输入 90061 → 1天1小时1分1秒
//	printf("%lld秒 = %lld天%d小时%d分%d秒\n", s, getDay(s), getHour(s), getMin(s), getSec(s));
//}
//
///* ---------------- 第 3 题：掐表测程序耗时（重点） ---------------- */
//// isPrime：is(是否) + Prime(质数) → 判断 n 是不是质数，是返回 1，不是返回 0
//int isPrime(int n)
//{
//	if (n < 2)
//	{
//		return 0;                   // 0 和 1 都不是质数
//	}
//	for (int i = 2; i*i<=n; i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;               // 找到能整除的因子 → 不是质数
//		}
//	}
//	 	return 1;               // 没找到能整除的因子 → 是质数
//	
//	// TODO 5：写 for (int i = 2; i <= sqrt(n); i++)
//	//        如果 n % i == 0（找到能整除的因子），说明不是质数，立刻 return 0
//	//        循环跑完都没找到 → 说明是质数，return 1
//	// 提示：sqrt 是 P90 学的开平方（square root），在 <math.h> 里，返回 double
//	//return 0;                       // ← 写完 TODO 后删掉这一行
//}
//
//// countPrime：count(计数) + Prime(质数) → 统计 1~n 里质数的个数
//int countPrime(int n)
//{
//	int count = 0;                  // count(计数)
//	for (int i = 2; i <= n; i++)
//	{
//		if (isPrime(i))             // isPrime 返回 1 就计数
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//void task3(void)
//{
//	clock_t t1 = clock();                 // 掐表：按下开始
//	int c = countPrime(20000000);                // 被测量的计算
//	clock_t t2 = clock();                 // 掐表：按下停止
//
//	// 标准答案：1~200000 共有 17984 个质数
//	printf("1~200000 共有 %d 个质数，耗时 %ld 毫秒\n", c, t2 - t1);
//	printf("思考：为什么耗时是 0 秒？怎么改进精度？\n");
//	printf("      → ①把 200000 调大到 2000000；②用 <time.h> 里的 clock()，精度到毫秒\n");
//}
//
///* ---------------- 第 4 题（选做）：新年倒计时 ---------------- */
//// 复用第 2 题的 4 个换算函数，所以要先完成第 2 题
//void task4(void)
//{
//	// future(未来)：北京时间 2027-01-01 00:00 的时间戳（东八区，已减 8 小时）
//	long long future = 1798732800;
//	long long left = future - time(NULL);      // left(剩余)
//
//	if (left <= 0)
//	{
//		printf("目标时刻已经过去了\n");
//		return;                                // return 单独用：提前结束函数
//	}
//	printf("距离 2027 年还有：%d天%d小时%d分%d秒\n", getDay(left), getHour(left), getMin(left), getSec(left));
//}
//
//
//


/* ---------------- 主函数：菜单选择 ---------------- */
//int main(void)
//{
//	printf("=== P91 time 函数练习 ===\n");
//	printf("1 打印时间戳+忙等5秒   2 秒数换算   3 掐表测质数耗时   4 新年倒计时\n");
//	printf("请输入题号(1-4)：");
//
//	int choice;                                // choice(选择)
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
