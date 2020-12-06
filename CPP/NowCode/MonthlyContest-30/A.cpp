#include<bits/stdc++.h>
using namespace std;


// void dfs(int n) {
//     if()
// }


int main() {
    int n, m, a, b, flag, t;
    cin >> n >> m;
    vector<vector<int> > arr(n);
    vector<bool> check(n);
    fill(check.begin(), check.end(), false);
    for(int i = 0; i < n; i++) arr[i].resize(n, -1);
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << arr[i][j];
    //     }
    // }
    for(int k = 0; k < m; k++) {
        cin >> a >> b >> t;
        arr[a][b] = arr[b][a] = t;
    }
    for(int k = 0; k < n; k++) {
        if(!check[k]) {
            for(int i = 0; i < n; i++) {
                // d
            }
        }
    }
    return 0;
}