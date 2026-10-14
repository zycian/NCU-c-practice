#include <stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int len = sizeof(arr) / sizeof(int);
	int* p = arr;
	//记录数组的地址
	printf("%p\n", p);

	for (int i = 0;i < len;i++)
	{
		printf("%d\n", *(p + i));
	}
	//检验此时p的值
	printf("%p\n", p);

	printf("%p\n", arr );
	printf("%p\n", arr+1);
	printf("%p\n", &arr );
	printf("%p\n", &arr + 1);
	return 0;
}