#include <stdio.h>

int* method();
void swap(void* p1, void* p2, int len);

int main()
{
	/*
	char  1
	short  2
	int  4
	long  4
	long long  8
	+/-  加减一个数据类型的长度
	*和/无意义
	指针相加也无意义

	void*p 没有类型，无法获取变量中数据，无法计算，但可以接收任意地址
	*/

	int a = 1;
	int* p1 = &a;
	int b = 2;
	int* p2 = &b;
	printf("%p\n", p1);
	printf("%p\n", p2); 
	printf("%p\n", p2 - p1);

	int* p3 = p1 + 10;//未分配的叫野指针即p3
	printf("%p\n", p3);
	printf("%d\n", *p3);

	int* p4 = method();//指向被释放空间的悬空指针p4
	printf("tuoshijian\n");
	printf("%p\n", p4);
	printf("%d\n", *p4);

	printf("-----------下面是void类型-------------\n");

		//不同类型指针不能互相赋值
		//但void可以接收，但不能读取不能计算
	int c = 10;
	int d = 20;
	void* p5 = &c;
	void* p6 = &d;

	swap(&c, &d, 4);


	return 0;
}

int* method()
{
	int n = 20;
	int* p = &n;
	return p;
}

void swap(void* p1, void* p2, int len)//len来记录类型长度
{
	char* pc1 = p1;//char字节长度为1
	char* pc2 = p2;
	char temp = 0;
	//通过循环来一个一个交换字节进而交换数据
	for (int i=0;i < len;i++) 
	{
		temp = *pc1;
		*pc1 = *pc2;
		*pc2 = temp;

		pc1++;//pc1/2是指针，也就是每个字节的地址
		pc2++;
	}
}