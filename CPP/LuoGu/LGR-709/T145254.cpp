#include<iostream>
#include<stdio.h>
#define ull unsigned long long
using namespace std;

int main() {
    ull n;
    cin >> n;
    ull arr[4];
    ull index = 0;
    for(ull i = 0; i < n; i++) {
        ull max_index = 0, min_idnex = 0, sum = 0;
        for(ull j = 0; j < 4; j++) {
            cin >> arr[j];
            if(arr[j] > arr[max_index]) max_index = j;
            if(arr[j] < arr[min_idnex]) min_idnex = j;
            sum += arr[j];
        }
        ull len = sum / 2;
        if(arr[max_index] + arr[min_idnex] != sum - (arr[max_index] + arr[min_idnex])) {
            printf("0\n");
        } else if (arr[0] == arr[1] && arr[1] == arr[2]) {
            printf("1\n");
        } else {
            ull j;
            for(j = 0; j < 4; j++) {
                if(j != max_index && arr[j] == arr[max_index]) {
                    printf("4\n");
                    break;
                }
            }
            if(j == 4) printf("8\n");
        }
    }
    return 0;
}