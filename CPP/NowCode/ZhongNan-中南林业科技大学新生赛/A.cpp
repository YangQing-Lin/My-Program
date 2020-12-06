#include<bits/stdc++.h>
using namespace std;
int main() {
    unordered_set<char> book;
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++) {
        book.insert(str[i]);
    }
    cout << book.size() << endl;
    return 0;
}