//#include <stdio.h>
//
//void printArray(int arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[5] = { 0 };
//	int len = sizeof(arr) / sizeof(int);
//	for (int i = 0; i < len; i++)
//	{
//		printf("请输入第 %d 个元素：", i + 1);
//		scanf("%d", &arr[i]);
//	}
//
//	printArray(arr, len);
//
//	int i = 0;
//	int j = len - 1;
//	while (i < j)
//	{
//		int temp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = temp;
//
//		i++;
//		j--;
//	}
//		
//    printArray(arr, len);
//
//	return 0;
//}