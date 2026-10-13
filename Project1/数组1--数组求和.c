//#include<stdio.h>
//#include<stdlib.h>
//#include <time.h>
//
//int isExist(int arr[], int len, int num)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == num)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int len = sizeof(arr) / sizeof(int);
//
//	srand(time(NULL));
//	for (int i = 0;i < len;)
//	{
//		int num = rand() % 100 + 1;
//		if (!isExist(arr, i, num))
//		{
//			arr[i] = num;
//			i++;
//		}
//	}
//
//	int sum = 0;
//	for(int i=0;i<len;i++)
//	{
//		sum = sum + arr[i];
//        printf("\t%d\n ", arr[i]);
//	}
//	printf("数组元素的和为：%d\n", sum);
//
//	int avg = sum / len;
//	printf("数组元素的平均值为：%d\n", avg);
//
//	int count = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] < avg)
//		{
//			count++;
//		}
//	}
//	printf("小于平均值的元素个数为：%d\n", count);
//
//	return 0;
//}