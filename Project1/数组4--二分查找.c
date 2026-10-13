//#include <stdio.h>   //对于有序数组，使用二分查找法查找指定元素的下标
//
//int BinarySearch(int arr[], int len, int num)
//{
//    int left = 0;
//    int right = len - 1;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (arr[mid] == num)
//        {
//            return mid;
//        }
//        else if (arr[mid] < num)
//        {
//            left = mid + 1;
//        }
//        else
//        {
//            right = mid - 1;
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//	int arr[] = {7,23,79,81,103,127,131,147};
//	int len = sizeof(arr) / sizeof(int);
//	
//	int num;
//	printf("请输入要查找的数字：");
//	scanf("%d", &num);
//
//	int index = BinarySearch(arr, len, num);
//	if (index != -1)
//	{
//		printf("找到了，位置在：%d\n", index);
//	}
//	else
//	{
//		printf("没找到\n");
//	}
//
//} 