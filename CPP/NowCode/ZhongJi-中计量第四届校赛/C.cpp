#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    vector<int> arr(n + 1);
    arr[0] = 0;
    for(int i = 0; i < n; i++)
        arr[i+1] = arr[i] + (str[i] == 'A' ? 1 : -1);
    // for(int i = 1; i <= n; i++) cout << arr[i] << endl;
    map<int, int> m;
    m[0] = 0;
    str = "C" + str;
    int maxn = -1, a, b, cnt;
    for(int i = 1; i <= n; i++) {
        cnt = 0;
        if(m[arr[i]] == 0 && arr[i] != 0) {
            m[arr[i]] = i;
        } else {
            cnt = i - m[arr[i]];
            // printf("%d %d ", arr[i], cnt);
            a = m[arr[i]];
            while(str[a] == 'A' && a >= 1) {
                cnt++;
                a--;
            }
            // printf("%d ", cnt);
            a = i + 1;
            while(str[a] == 'B' && a <= n) {
                cnt++;
                a++;
            }
            // printf("%d ", cnt);
            maxn = max(maxn, cnt);
            // printf("#%d\n", maxn);
        }
    }
    cout << maxn << endl;
    // for(int i = 1; i <= n; i++) {
    //     if(m[arr[i]] != i) {

    //     }
    // }
    return 0;
}