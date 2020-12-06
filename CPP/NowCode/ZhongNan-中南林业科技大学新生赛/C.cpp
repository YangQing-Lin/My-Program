#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long

ll my_funs(ll n, ll m) {
    ll sum = 1;
    if(n == m) {
        for(int i = 1; i <= n; i++) {
            sum *= i;
            //cout << sum << endl;
        }
    } else if(m == 0) {
        sum = 1;
    } else {
        sum = my_funs(n, n) / my_funs(n-m, n-m);
    }
    return sum;
}

ll del_funs(ll n) {
    ll sum = 0;
    ll son = 0;
    ll mather = 0;
    ll tmp = 1;
    for(int i = 1; i <= n; i++) {
        sum += my_funs(n, n-i);
    }
    return sum;
}

int main() {
    int n, t;
    cin >> n;
    while(n--) {
        cin >> t;
        printf("%lld %lld\n", my_funs(t, t), del_funs(t));
        // cout << my_funs(t, t) - del_funs(t) << endl;
    }
    return 0;
}