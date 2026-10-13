// ============================================================
// 【已留档】本文件是 P90「C语言中的常见函数（math）」的练习笔记。
// 说明：为了给新练习 8.c 腾出工程里唯一的 main()，本文件整体注释。
//       想重新运行它：先把 8.c 整篇注释，再去掉本文件每行开头的 "//"。
// ============================================================
//#include <stdio.h>
//#include <math.h>
///*
//* pow()幂
//* sqrt()平方根
//* ceil()向上取整
//* floor()向下取整
//* fabs()绝对值
//
//* fmax()最大值
//* fmin()最小值
//* round()四舍五入
//* fmod()取余
//* log()自然对数
//* log10()以10为底的对数
//* exp()指数函数
//* sin()正弦
//* cos()余弦
//* tan()正切
//* asin()反正弦
//* acos()反余弦
//* atan()反正切
//* rand()随机数
//* srand()设置随机数种子
//* time()获取时间戳
//*/
//
//int main()
//{
//	double res1 = pow(2, 3);// 2的3次方
//	printf("2的3次方是：%lf\n", res1);
//
//	double res2 = sqrt(9);// 9的平方根
//	printf("9的平方根是：%lf\n", res2);
//
//	double res3 = ceil(3.14);// 向上取整
//	printf("3.14向上取整是：%lf\n", res3);
//
//	double res4 = floor(3.14);// 向下取整
//	printf("3.14向下取整是：%lf\n", res4);
//
//	double res5 = fabs(-10.5);// 浮点数绝对值
//	printf("10.5的绝对值是：%lf\n", res5);
//
//	double res6 = round(3.14);// 四舍五入
//	printf("3.14四舍五入是：%lf\n", res6);
//
//	double res7 = fmod(10.5, 3.2);// 取余
//	printf("10.5除以3.2的余数是：%lf\n", res7);
//
//	double res8 = log(2.71828);// 自然对数
//	printf("2.71828的自然对数是：%lf\n", res8);
//
//	double res9 = log10(100);// 以10为底的对数
//	printf("100以10为底的对数是：%lf\n", res9);
//
//	double res10 = exp(1);// 指数函数
//	printf("e的1次方是：%lf\n", res10);
//
//	double res11 = sin(0);// 正弦
//	printf("0的正弦是：%lf\n", res11);
//
//	double res12 = cos(0);// 余弦
//	printf("0的余弦是：%lf\n", res12);
//
//	double res13 = tan(0);// 正切
//	printf("0的正切是：%lf\n", res13);
//
//	double res14 = asin(0);// 反正弦
//	printf("0的反正弦是：%lf\n", res14);
//
//	double res15 = acos(0);// 反余弦
//	printf("0的反余弦是：%lf\n", res15);
//
//	double res16 = atan(0);// 反正切
//	printf("0的反正切是：%lf\n", res16);
//
//	return 0;
//}
