#include<bits/stdc++.h>
using namespace std;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 0; i < str1.length(); i++) {
        if(find(str2.begin(), str2.end(), str1[i]) != str2.end()) {
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
    return 0;
}