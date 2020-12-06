#include<stdio.h>
#include<math.h>
int main(void) {
	int n;
	int count = 0;
    int high;
    int bit;
    n = 1000000;
    high = n;
    bit = (int)log10(n) + 1;
    while (high/10) {
        high /= 10;
    }
    if(high <= 3){
    	count = n - (high)*pow(9, bit - 1);     	
    }
    else{
    	count = n - (high - 1)*pow(9, bit - 1);
    }
    printf("%d\n", count); 
	return 0;
} 
