#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int cnt = 0;
        while(n != 1) {
            if(n % 2 == 0) n >>= 1;
            else n -= 1;
            // cout << n << endl;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}