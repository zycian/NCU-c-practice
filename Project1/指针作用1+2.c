//#include <stdio.h>
//
////void swap(int* p1, int* p2);
//void getminmax(int arr[], int len, int* max, int* min);
//int main()
//{
//	/*int a = 10;
//	int b = 20;
//	printf("%d %d\n", a, b);
//	swap(&a, &b);
//	printf("%d %d", a, b);*/
//	
//	int arr[] = { 1,2,3,4,5,6 };
//	int len = sizeof(arr) / sizeof(int);
//	int min=arr[0];
//	int max = arr[0];
//	getminmax(arr, len, &max, &min);
//	printf("max=%d   min=%d", max, min);
//
//	return 0;
//}
//
//void getminmax(int arr[], int len, int* max,int* min)
//{
//	*max = arr[0];
//	*min = arr[0];
//
//	for (int i = 1;i < len;i++)
//	{
//		if (arr[i] > *max)
//		{
//			*max = arr[i];
//		}
//
//		if (arr[i] < *min)
//		{
//			*min = arr[i];
//		}
//	}
//}
//
//
//
//
//
////void swap(int* p1, int* p2)
////{
////	int temp = *p1;
////	*p1 = *p2;
////	*p2 = temp;
////}