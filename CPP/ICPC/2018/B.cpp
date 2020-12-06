#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll index = 1, n, temp, sum = 0, a, b, cnt;
    cin >> n;
    while(n--) {
        cin >> a >> b >> cnt;
        sum = 0;
        if(cnt == 0) {
            for(int i = 1; i <= a; i++) {
                for(int j = 1; j <= b; j++) {
                    sum += i * j;
                }
            }
        } else {
            vector<int> x(cnt);
            vector<int> y(cnt);
            for(int i = 0; i < cnt; i++) {
                cin >> x[i] >> y[i];
            }
            s
        }
        cout << sum << endl;
    }
    return 0;
}