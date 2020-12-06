#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    char c;
    c = getchar();
    cin >> n;
    getchar();
    string str;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        getline(cin, str);
        arr[i] = str;
    }
    bool flag = true;
    for(int i = 0; i <= n/2; i++) {
        if(arr[i] != arr[n-i-1]) {
            flag = false;
        }
    }
    if(flag) {
        cout << "bu yong dao le\n";
    }
    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if(arr[i][j] == ' ') cout << ' ';
            else cout << c;
        }
        puts("");
    }
    return 0;
}