//#include <stdio.h>
//
//int main()
//{
//	int a = 1;
//	int* p = &a;
//	printf("%d\n", *p);
//	*p = 200;
//	printf("%d\n", *p);
//	printf("%d\n", a);
//
//	char c = 'a';
//	char* p1 = &c;
//    printf("%c\n", *p1);
//    *p1 = 'b';
//    printf("%c\n", *p1);
//    printf("%c\n", c);
//
//	long long n = 100;
//	long long* p2 = &n;
//    printf("%lld\n", *p2);
//    *p2 = 300;
//    printf("%lld\n", *p2);
//    printf("%lld\n", n);
//
//	float f = 1.1;
//    float* p3 = &f;
//    printf("%f\n", *p3);
//    *p3 = 2.2;
//    printf("%f\n", *p3);
//    printf("%f\n", f);
//
//    printf("%zu\n", sizeof(*p1));
//
//	return 0;
//}