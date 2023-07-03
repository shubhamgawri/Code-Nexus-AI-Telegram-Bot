// CP6-Postlab , FEC ,Shubham Gawri , 9371 , Pr. To find x^y using recursion // 
#include <stdio.h>
int power(int n1, int n2);
int main() {
    int base, exp, result;
    printf("Enter base number: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);
    result = power(base, exp);
    printf("%d^%d = %d \n", base, exp, result);
    return 0;
}
//Power function
int power(int base, int exp) {
    if (exp != 0)
        return (base * power(base, exp - 1));
    else
        return 1;
}