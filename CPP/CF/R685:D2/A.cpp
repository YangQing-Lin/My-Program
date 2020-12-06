#include<bits/stdc++.h>
using namespace std;

vector<int> arr(1e9);

void init() {
    arr[1] = 0;
    arr[2] = 2;
    int n;
    for(int i = 3; i < 1e9; ++i) {
        n = sqrt(i) + 1;
        while(n-- && n > 1) {
            if(i % n == 0) {
                break;
            }
        }
        arr[i] = min(arr[n], arr[i-1]);
    }
}

int main() {
    int n, temp;
    cin >> n;
    init();
    while(n--) {
        scanf("%d", &temp);
        printf("%d\n", arr[temp]);
    }
    return 0;
}