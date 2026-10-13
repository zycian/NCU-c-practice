//#include <stdio.h>
//
//int InterpolationSearch(int arr[], int len, int num)
//{
//    if (len <= 0 || num <arr[0] || num>arr[len - 1])
//    {
//        return -1;
//    }
//
//    int left = 0;
//    int right = len - 1;
//    while (left <= right&&num>=arr[left]&&num<=arr[right])
//    {
//        if (arr[right] == arr[left])
//        {
//            return(arr[left] == num) ? left : -1;
//        }
//
//        int mid=left+(int)((long long)(right-left)*(num-arr[left])/(arr[right]-arr[left]));
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
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    int len = sizeof(arr) / sizeof(int);
//
//    int num;
//    printf("请输入要查找的数字：");
//    scanf("%d", &num);
//
//    int index = InterpolationSearch(arr, len, num);
//    if (index != -1)
//    {
//        printf("找到了，位置在：%d\n", index);
//    }
//    else
//    {
//        printf("没找到\n");
//    }
//
//    return 0;
//}