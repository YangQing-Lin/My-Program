#include<bits/stdc++.h>
using namespace std;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    stack<int> s;
    int len1 = str1.length(), len2 = str2.length();
    int i = len1 - 1, j = len2 - 1;
    while(i >= 0 && j >= 0) {
        s.push(((str1[i] - '0') + (str2[j] - '0')) % 10);
        i--;j--;
    }
    while(i >= 0) {
        s.push(str1[i] - '0');
        i--;
    }
    while(j >= 0) {
        s.push(str2[j] - '0');
        j--;
    }
    // if(len1 < len2) {
    //     for(int k = 0; k <= j; k++) {
    //         printf("%c", str2[k]);
    //     }
    // } else if (len1 > len2) {
    //     for(int k = 0; k <= i; k++) {
    //         printf("%c", str1[k]);
    //     }
    // }
    while(!s.empty() && s.top() == 0) s.pop();
    if(s.empty()) cout << 0;
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    puts("");
    return 0;
}