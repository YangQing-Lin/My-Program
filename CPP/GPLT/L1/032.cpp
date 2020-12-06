#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char ch;
    cin >> n >> ch;
    getchar();
    string str;
    getline(cin, str);
    if(str.length() >= n) {
        cout << str.substr(str.length() - n, n) << endl;
    } else {
        for(int i = 0; i < n - str.length(); i++) cout << ch;
        cout << str << endl;
    }
    return 0;
}