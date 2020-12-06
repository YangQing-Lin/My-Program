#include<iostream>
#define int long long
using namespace std;
signed main() {
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}