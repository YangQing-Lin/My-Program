#include<iostream>
using namespace std;
int main() {
    int arr[6][6] = {0};
    int prefx[6][6] = {0};
    for(int i = 1; i < 6; i++) {
        for(int j = 1; j < 6; j++) {
            if(j != 1) cout << " ";
            arr[i][j] = (i-1) * 5 + j;
            if(i == 1 || j == 1) prefx[i][j] = arr[i][j];
            printf("%3d", arr[i][j]);
        }
        puts("");
    }
    puts("");
    for(int i = 1; i < 6; i++) {
        for(int j = 1; j < 6; j++) {
            if(j != 1) cout << " ";
            if (i != 1 && j != 1)
                prefx[i][j] = prefx[i][j-1] + prefx[i-1][j] - prefx[i-1][j-1] + arr[i][j];
            printf("%3d", prefx[i][j]);
        }
        puts("");
    }
    return 0;
}