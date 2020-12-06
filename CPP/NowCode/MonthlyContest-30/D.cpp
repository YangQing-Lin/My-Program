#include<bits/stdc++.h>
using namespace std;
int main() {
    int prime[100005] = {0};
    int n, temp;
    cin >> n;
    int cnt = 2;
    for(int i = 2; i <= n; i++) {
        if(prime[i] == 0) {
            for(int j = 2; j * i <= n; j++) {
                prime[j * i] = 1;
            }
            cnt++;
        }
        prime[i] = cnt;
    }
    prime[1] = prime[2] = prime[3] = -1;
    // for(int i = 1; i < 16; i++) printf("%d ", prime[i]);
    // puts("");
    cout << prime[n] << endl;
    return 0;
}