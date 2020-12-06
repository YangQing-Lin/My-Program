#include<stdio.h>
int main(void) {
    enum DAY{
        MON = 1, TUE, WED, THU, FRI, SAT, SUM
    };

    enum DAY d = TUE;
    printf("%d\n", TUE);
    return 0;
}