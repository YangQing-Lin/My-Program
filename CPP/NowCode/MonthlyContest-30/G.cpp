#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int len = a.size();
    int cnt = 0;
    vector<int>::iterator it;
    for(int i = a.size() - 1; i >= 0; i--) {
        int j;
        for(j = b.size() - 1; j >= 0; j--) {
            if(b[j] < a[i]) {
                cnt++;
                a.erase(i);
                b.erase(j);
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}