#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    ll cnt = 0;
    cnt = n / 4 * 2;
    n %= 4;
    if(n >= 3) {
        n -= 3;
        cnt++;
    }
    cout << cnt + n << endl;
    return 0;
}