//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 2,3,56,23,1 };
//	int len = sizeof(arr) / sizeof(int);
//
//	for (int j = 0;j < len - 1;j++)
//	{
//
//
//
//		for (int i = 0;i < len - 1-j;i++)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				int temp = 0;
//				temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//			}
//		}
//	}
//	
//	for (int i = 0;i < len;i++)
//    {
//        printf("%d ", arr[i]);
//    }
//	return 0;
//}