#include<bits/stdc++.h>
using namespace std;
int main() {
    string str, temp_str;
    int n;
    cin >> str >> n;
    for(int i = 0; i < n; i++) {
        map<string, bool> check;
        cin >> temp_str;
        cout << str.find_last_of(temp_str) + 2 - temp_str.length() << endl;
    }
    return 0;
}