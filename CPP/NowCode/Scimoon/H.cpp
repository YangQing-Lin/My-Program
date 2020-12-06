#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin >> t;
    ll a, b, c, A, B, C, maxn, minn;
    double temp;
    while(t--) {
        cin >> a >> b >> c >> A >> B >> C;
        temp = sqrt(pow(a-A, 2) + pow(b-B, 2));
        maxn = max(c, C);
        minn = min(c, C);
        if(temp >= maxn - minn && temp <= c + C) {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}