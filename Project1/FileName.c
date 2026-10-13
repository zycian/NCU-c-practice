//#include <stdio.h>
//
//int main() {
//    int dividend = 0;   // 被除数
//    int divisor = 0;    // 除数
//    
//    printf("请输入被除数: ");
//    scanf("%d", &dividend);
//    
//    printf("请输入除数: ");
//    scanf("%d", &divisor);
//    
//    if (divisor == 0) {
//        printf("? 错误！除数不能为0！\n");
//        return 1;
//    }
//    
//    int quotient = 0;     // 商（计数器）
//    int remainder = dividend;  // 余数
//    
//    // 循环减法
//    while (remainder >= divisor) {
//        remainder -= divisor;   // 减一次
//        quotient++;             // 商+1
//    }
//    
//    printf("除法运算结果:\n");
//    printf("%d ÷ %d = %d ... %d\n", dividend, divisor, quotient, remainder);
//    printf("商: %d, 余数: %d\n", quotient, remainder);
//    
//    return 0;
//}
