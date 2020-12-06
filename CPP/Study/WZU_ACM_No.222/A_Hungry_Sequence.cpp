#include<iostream>
using namespace std;

int arr[100001] = {0};

int main() {
    int n, index = 0, temp;
    cin >> n;
    cout << 2;
    arr[index] = 2;
    index = 1;
    for(int i = 1; i < n; i++, index++) {
        arr[index] = arr[index-1]+1;
        for(int j = 0; j < index; j++) {
            if(arr[index]%arr[j] == 0) {
                j = 0;
                arr[index]++;
                continue;
            }
        }
        printf(" %d", arr[index]);
    }
    puts("");
    return 0;
}