//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 3,5,2,1,4 };
//	int len = sizeof(arr) / sizeof(int);
//
//	//—°‘Ò-≈≈–Ú
// 
//	for (int i = 0;i < len - 1;i++)
//	{
//		for (int j = i + 1;j < len;j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				int temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//
//	//±È¿˙
// 
//	for (int i = 0;i < len;i++)
//    {
//        printf("%d ", arr[i]);
//    }
//	return 0;
//}