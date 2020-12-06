#include<iostream>
using namespace std;
int main() {
    int n, len;
    cin >> n >> len;
    len--;
    string str = "";
    for(int i = 0; i < n; i++) str+="z";
    for(int i = n-1; i >= 0; i--) {
        str[i] -= len % 26;
        len /= 26;
    }
    cout << str << endl;
    return 0;
}