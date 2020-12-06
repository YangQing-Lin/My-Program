#include<iostream>
#include<vector>
using namespace std;

long long arr[491];

int main() {
    arr[1] = arr[2] = 1;
    for(int i = 3; i <= 490; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    int n;
    while(true) {
        scanf("%d", &n);
        if(n == -1) break;
        printf("Hour: %d: %lld cow(s) affected\n", n, arr[n]);
    }
    return 0;
}