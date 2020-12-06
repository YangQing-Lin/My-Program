#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n, m, cnt, temp;
    bool book[101];
    cin >> t;
    while(t--) {
        cnt = 0;
        cin >> n >> m;
        memset(book, false, sizeof(book));
        while(n--) {
            cin >> temp;
            book[temp] = true;
        }
        while(m--) {
            cin >> temp;
            if(book[temp]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}