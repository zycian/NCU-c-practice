#include <stdio.h>
int main()
{
	////用索引
	//int arr[3][5] =
	//{
	//	{1,2,3,4,5},
	//	{11,22,33,44,55},
	//	{111,222,333,444,555}
	//};
	//for (int i = 0;i < 3;i++)//行
	//{
	//	for (int j = 0;j < 5;j++)//列
	//	{
	//		printf ("%d ", arr[i][j]);
	//	}
	//	printf("\n");
	//}

	//定义三个一维数组
	int arr1[] = { 1,2,3 };
	int arr2[] = { 1,2,3,4,5 };
	int arr3[] = { 1,2,3,4,5,6,7,8,9 };
	//算出各组长度再存入数组
	int len1 = sizeof(arr1) / sizeof(int);
	int len2 = sizeof(arr2) / sizeof(int);
	int len3 = sizeof(arr3) / sizeof(int);
	int lenarr[] = { len1,len2,len3 };

	int* arr[3] = { arr1,arr2,arr3 };//存的是一维数组的内存地址

	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < lenarr[i];j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}