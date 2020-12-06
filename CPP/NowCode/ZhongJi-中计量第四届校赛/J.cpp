#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+7

int main() {
    int n;
    cin >> n;
    getchar();
    vector<int> arr(n), ans(n);
    string str;
    cin >> str;
    for(int i = 0; i < n; i++) arr[i] = str[i] - 'A';
    cin >> str;
    for(int i = 0; i < n; i++) ans[i] = str[i] - 'A';
    // if(ans == arr) cout << "yes" << endl;
    int cnt = 0;
    while(arr != ans) {
        int i, j;
        for(i = n-1; i >= 0; i--) {
            if(arr[i] > arr[i-1]) break;
        }
        for(j = n-1; j >= i; j--) {
            if(arr[j] > arr[i]) break;
        }
        swap(arr[i], arr[j]);
        i++;
        j = n-1;
        for(int k = 0; i+k < j-k; k++) {
            swap(arr[i+k], arr[j-k]);
        }
        for(i = 0; i < n; i++) cout << arr[i];
        puts("");
        cnt++;
    }
    cnt = -cnt;
    if(cnt < 0)
    cout << (-cnt) % (int)inf << endl;
    return 0;
}