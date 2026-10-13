//#define _CRT_SECURE_NO_WARNINGS   // VS 特有：关掉 scanf 的"不安全"警告，必须写在所有 #include 之前
//
//#include <stdio.h>
//#include <stdlib.h>                // standard(标准) + library(库)：rand / srand
//#include <time.h>
//
//#define LEN 10                     // LEN = length(长度)：宏定义数组长度，以后改一处就够
//
///*
// * ============================================================
// *  P102 后数组综合练习
// *
// *  【数组核心知识点 —— 必背，90% 的坑都在这 6 条里】
// *  1. 下标从 0 开始：int arr[10] 的合法下标是 0~9，arr[10] 是越界
// *     ? C 语言【不做越界检查】！越界读写不报错，但会踩到别人的内存 → 结果莫名其妙。
// *       这是嵌入式/底层开发里最难查的 bug 之一，写循环条件时务必数清楚。
// *  2. 数组在内存中是【连续存放】的，数组名代表首元素的地址。
// *  3. 求长度：sizeof(arr) / sizeof(arr[0])
// *     ? 只在"定义数组的那个函数内部"有效！一旦把数组传给另一个函数，
// *       函数里的 arr 已经退化成指针，sizeof(arr) 得到的是指针大小（x64 下 8 字节），算出来是错的。
// *     ★ 结论：数组作函数参数时，必须【额外多传一个长度 len】。
// *  4. 数组传参是"传地址"：函数里改 arr[i]，外面的原数组【跟着变】，不用 return。
// *  5. 求最值套路：先让 arr[0] 当擂主，再逐个挑战。
// *     ? 千万不要用 0 当初始最大值 —— 数组里全是负数时就错了。
// *  6. 初始化：int arr[10] = { 0 };   → 10 个元素全部为 0
// *              int arr[10] = { 1, 2 }; → 前两个是 1、2，其余自动补 0
// *
// *  运行方式：编译后输入 1~6 选择题号
// * ============================================================
// */
//
//// printArray：print(打印) + Array(数组) → 打印数组全部元素（工具函数，后面每题都能用）
//// 注意参数写法：int arr[] 后面必须紧跟 int len，因为函数里算不出数组长度（见知识点 3）
//void printArray(int arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//// getRandom：get(获取) + Random(随机) → 返回 [min, max] 内的随机整数
//int getRandom(int min, int max)
//{
//	return rand() % (max - min + 1) + min;
//}
//
///* ---------------- 第 1 题：遍历 + 求和 + 平均值 + 最值（示范，已写好） ---------------- */
//void task1(void)
//{
//	int scores[LEN] = { 0 };       // scores(分数)：全部初始化为 0
//
//	// (1) 录入：数组元素当 scanf 的接收变量，要写成 &scores[i]
//	for (int i = 0; i < LEN; i++)
//	{
//		printf("请输入第 %d 个成绩：", i + 1);
//		scanf("%d", &scores[i]);   // ? 别写成 &scores[LEN]，那是越界
//	}
//
//	printf("你输入的成绩：");
//	printArray(scores, LEN);
//
//	// (2) 求和：累加器初值必须是 0
//	int sum = 0;
//	for (int i = 0; i < LEN; i++)
//	{
//		sum = sum + scores[i];
//	}
//
//	// (3) 最值：擂台法，初值取 arr[0]（不是 0！）
//	int max = scores[0];           // max = maximum(最大值)
//	int min = scores[0];           // min = minimum(最小值)
//	for (int i = 1; i < LEN; i++) // 从 1 开始就行，arr[0] 已经是擂主了
//	{
//		if (scores[i] > max)
//		{
//			max = scores[i];
//		}
//		if (scores[i] < min)
//		{
//			min = scores[i];
//		}
//	}
//
//	printf("总分：%d\n", sum);
//	printf("平均分：%.2f\n", (double)sum / LEN);   // 整数除整数会丢小数，先把其中一个转成 double
//	printf("最高分：%d，最低分：%d\n", max, min);
//}
//
///* ---------------- 第 2 题：数组当"计数器"（对比 P92 题2 的 6 个变量写法） ---------------- */
//void task2(void)
//{
//	// 长度开 7，只用下标 1~6（下标 0 空着），这样骰子点数可以直接当下标，不用换算
//	int count[7] = { 0 };          // count(计数)
//
//	for (int i = 0; i < 10000; i++)
//	{
//		int point = getRandom(1, 6);
//		count[point]++;
//		// TODO 2：一行搞定统计 —— count[?]++;
//		//         想一下：P92 那会儿要写 6 个 case，现在为什么一行就够？
//	}
//
//	for (int i = 1; i <= 6; i++)
//	{
//		printf("%d点：%d 次，占比 %.2f%%\n", i, count[i], (double)count[i] / 10000 * 100);
//	}
//	// 目标：每一面都接近 16.67%
//}
//
///* ---------------- 第 3 题：线性查找（数组作参数 + 找不到返回 -1 的约定） ---------------- */
//// findIndex：find(查找) + Index(下标) → 找到返回下标，找不到返回 -1
//// 这是 C 语言的通用约定：-1 表示"没找到"，因为下标不可能是负数
//int findIndex(int arr[], int len, int target)   // target(目标)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == target)
//		{
//			return i;
//		}
//	}
//	// TODO 3：for 遍历 arr，一旦 arr[i] == target 就 return i（立刻结束，不用再找）
//	//         循环全部走完说明没有 → return -1;
//	return -1;
//}
//
//void task3(void)
//{
//	int nums[LEN] = { 23, 45, 12, 67, 89, 34, 56, 78, 90, 11 };
//
//	printf("数组内容：");
//	printArray(nums, LEN);
//
//	printf("请输入要查找的数字：");
//	int target;
//	scanf("%d", &target);
//
//	int index = findIndex(nums, LEN, target);
//	if (index == -1)
//	{
//		printf("%d 不在数组中\n", target);
//	}
//	else
//	{
//		printf("%d 在数组中，下标是 %d\n", target, index);
//	}
//}
//
///* ---------------- 第 4 题：分段统计（数组当计数器，进阶版） ---------------- */
//void task4(void)
//{
//	int scores[LEN] = { 0 };
//
//	// 用随机数造 10 个成绩，省得手动输入
//	for (int i = 0; i < LEN; i++)
//	{
//		scores[i] = getRandom(35, 100);
//	}
//	printf("10 个成绩：");
//	printArray(scores, LEN);
//
//	// seg = segment(分段)：seg[0]=<60分  seg[1]=60~69  seg[2]=70~79  seg[3]=80~89  seg[4]=90~100
//	int seg[5] = { 0 };
//	for (int i=0; i < LEN; i++)
//	{
//		int s = scores[i];
//		if (s < 60) seg[0]++;
//		else if (s < 70) seg[1]++;
//		else if (s < 80) seg[2]++;
//		else if (s < 90) seg[3]++;
//		else seg[4]++;
//	}
//	// TODO 4：遍历 scores，判断每个成绩落在哪一段，给对应的 seg[?]++
//	//         写法一（老实版）：if (s < 60) seg[0]++; else if (s < 70) seg[1]++; ...
//	//         写法二（技巧版）：算段号 = (s - 60) / 10 + 1，但 s<60 时要归到 0，s==100 时要归到 4
//	//         先用老实版写出来，能跑再考虑技巧版
//
//	printf("60分以下：%d 人\n", seg[0]);
//	printf("60~69分 ：%d 人\n", seg[1]);
//	printf("70~79分 ：%d 人\n", seg[2]);
//	printf("80~89分 ：%d 人\n", seg[3]);
//	printf("90~100分：%d 人\n", seg[4]);
//}
//
///* ---------------- 第 5 题（挑战·下节课内容预告）：数组反转 ---------------- */
//// reverse(反转)：把数组前后颠倒，比如 1 2 3 4 5 → 5 4 3 2 1
//void reverse(int arr[], int len)
//{
//	// TODO 5：只需要循环 len / 2 次
//	//         第 i 次：交换 arr[i] 和 arr[len - 1 - i]  （i=0 换最后一个，i=1 换倒数第二个……）
//	//         交换用三行：int temp = arr[i]; arr[i] = arr[len-1-i]; arr[len-1-i] = temp;
//	//         ? 想想为什么只走一半？走全程会怎样？（答：换过去又换回来，等于没换）
//}
//
//void task5(void)
//{
//	int nums[LEN] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//	printf("反转前：");
//	printArray(nums, LEN);
//
//	reverse(nums, LEN);            // 不用接收返回值，因为数组传的是地址，原地就改了
//
//	printf("反转后：");
//	printArray(nums, LEN);
//}
//
///* ---------------- 第 6 题（挑战·下节课内容预告）：冒泡排序 ---------------- */
//// bubbleSort：bubble(气泡) + Sort(排序) → 每一趟把最大的"浮"到末尾，升序排列
//void bubbleSort(int arr[], int len)
//{
//	// TODO 6：两层循环
//	//   外层 for (int i = 0; i < len - 1; i++)       → 共走 len-1 趟
//	//   内层 for (int j = 0; j < len - 1 - i; j++)   → 每趟少比一个（后面 i 个已经排好了）
//	//   内层里：if (arr[j] > arr[j + 1]) 就交换这两个相邻元素
//}
//
//void task6(void)
//{
//	int nums[LEN] = { 0 };
//	for (int i = 0; i < LEN; i++)
//	{
//		nums[i] = getRandom(1, 100);
//	}
//
//	printf("排序前：");
//	printArray(nums, LEN);
//
//	bubbleSort(nums, LEN);
//
//	printf("排序后：");
//	printArray(nums, LEN);
//}
//
///* ---------------- 主函数：菜单选择 ---------------- */
//int main(void)
//{
//	srand(time(NULL));             // ★ 播种：整个程序只调用一次
//
//	printf("=== P102 数组综合练习 ===\n");
//	printf("1 成绩统计(和/均/最值)  2 骰子计数  3 线性查找\n");
//	printf("4 分段统计              5 数组反转  6 冒泡排序\n");
//	printf("请输入题号(1-6)：");
//
//	int choice;                    // choice(选择)
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
//	case 5:
//		task5();
//		break;
//	case 6:
//		task6();
//		break;
//	default:
//		printf("题号只能是 1~6\n");
//		break;
//	}
//
//	return 0;
//}
