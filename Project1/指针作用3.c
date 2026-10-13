//#include<stdio.h>
//
//int getremainder(int num1, int num2, int* res);
//
//int main()
//{
//    int a = 0;
//    int b = 3;
//    int res = 0;
//
//
//    if (getremainder(b, a, &res) == 1)
//    {
//        printf("%d与%d相除得到的余数是%d\n", b, a, res);
//    }
//    else
//    {
//        printf("fail\n");
//    }
//
//    /*if (a == 0)
//    {
//        printf("fail");
//    }
//    else
//    {
//        getremainder(b, a, &res);
//
//        printf("%d与%d相除得到的余数是%d", b, a, res);
//    }*/
//	return 0;
//}
//
//int getremainder(int num1, int num2, int* res)
//{
//    if (num2 == 0)
//    {
//        return 0;
//    }
//    *res = num1 % num2;
//    return 1;
//}