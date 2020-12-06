#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, sum = 0;
    cin >> n;
    vector<ll> arr(n);
    set<int> s;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    for(ll i = 0; i < n - 2; i++) {
        for(ll j = 0; j < n; j++) {
            if(arr[j] == *s.begin()) {
                // printf("#%d\n", *s.begin());
                ll a, b, c = j - 1;
                while(c >= 0 && arr[c] == -1) c--;
                a = c == -1 ? 0 : arr[c];
                c = j + 1;
                while(c < n && arr[c] == -1) c++;
                b = c == n ? 0 : arr[c];
                sum += max(a, b) + arr[j];
                s.erase(arr[j]);
                arr[j] = -1;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) if(arr[i] != -1) sum += arr[i];
    cout << sum << endl;
    return 0;
}
/*
5
2 5 3 5 1
*/