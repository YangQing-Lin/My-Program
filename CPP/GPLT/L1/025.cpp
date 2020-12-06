#include<bits/stdc++.h>
using namespace std;

int to_number(string str) {
    int n = 0;
    for(int i = 0; i < str.length(); i++) {
        n = n * 10 + str[i] - '0';
    }
    return n;
}

bool is_number(string str) {
    if(str[0] == '-' || str.length() > 4 || str[0] == '0') return false;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] > '9' || str[i] < '0') return false;
    }
    if(to_number(str) > 1000) return false;
    return true;
}

int main() {
    string str1, str2;
    cin >> str1;
    getchar();
    getline(cin, str2);
    // printf("%d %d %s\n", to_number(str1), to_number(str2), 
    // to_string(to_number(str1) + to_number(str2)).c_str());
    printf("%s + %s = %s\n", 
    is_number(str1) ? str1.c_str() : "?", 
    is_number(str2) ? str2.c_str() : "?", 
    (is_number(str1) && is_number(str2)) ? 
    to_string(to_number(str1) + to_number(str2)).c_str() : "?");
    return 0;
}