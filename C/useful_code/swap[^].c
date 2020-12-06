#include<stdio.h>
int main(void){
    int number_a, number_b;
    scanf("%d %d", &number_a, &number_b);
    printf("%d %d\n", number_a^number_b^number_a,
        number_b^number_a^number_b);
    number_a = number_a^number_b^number_a;
    number_b = number_b^number_a^number_b;
    printf("a = %d b = %d\n", number_a, number_b);
    return 0;
}