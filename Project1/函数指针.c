#include <stdio.h>

int add(num1, num2);
int subtract(num1, num2);
int mutiply(num1, num2);
int divide(num1, num2);
//void method1()
//{
//	printf("method1\n");
//}
//
//int method2(int num1, int num2)
//{
//	printf("method2\n");
//	return num1 + num2;
//}

int main()
{
	////定义函数指针  类型（*指针名）（形参）   可用其来动态调用函数
	//void (*p1)() = method1;
	//int (*p2)(int, int) = method2;
	////利用指针调用函数
	//p1();
	//int num=p2(1,2);
	//printf("%d",num);


	//定义函数通过键盘录入来进行加减乘除
	int (*p[4])(int, int) = { add,subtract,mutiply,divide };//函数指针数组
	printf("请录入两个数字进行计算：");
	int num1;
	int num2;
	scanf("%d %d",&num1,&num2);

	printf(" %d\n", num1);
	printf(" %d\n", num2);

	
	int choose;
	printf("请选择要进行的计算：");
	scanf("%d", &choose);
	printf("1.加 2.减 3.乘 4.除\n");
	if (choose < 1 || choose>4)
	{
		printf("没有这个操作");
	}
	else if (choose == 4 && num2 == 0)
	{
		printf("被除数不能为0");
	}
	else
	{
		printf("结果是：%d", p[choose - 1](num1, num2));
	}
	

	return 0;
}

int add(num1,num2)
{
	return num1 + num2;
}
int subtract(num1, num2)
{
	return num1 - num2;
}
int mutiply(num1, num2)
{
	return num1 * num2;
}
int divide(num1, num2)
{
	return num1 / num2;
}
