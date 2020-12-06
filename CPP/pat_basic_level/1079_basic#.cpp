#include<iostream>
using namespace std;

bool is_palindromic_number(string str) {
    bool flag = true;
    int len = str.length();
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            flag = false;
            break;
        }
    }
    return flag;
}

string make(string s_1) {
    string s_2 = s_1;
    int temp = 0;
    int len = s_1.length();
    for(int j = 0; j < len; j++) {
        int number = s_1[j] - '0' + s_1[len-j-1] - '0';
        s_2[j] = (number + temp) % 10 + '0';
        temp = (number + temp) / 10;
    }
    if(temp != 0) {
        s_2 += temp + '0';
    }
    string s_3(s_2.rbegin(), s_2.rend());
    cout << s_1 + " + ";
    for(int i = len - 1; i >= 0; i--) {
        cout << s_1[i];
    }
    cout << " = " << s_3 << endl;
    if(is_palindromic_number(s_3)) {
        cout << s_3 + " is a palindromic number." << endl;
    }
    return s_3;
}

int main(){
    string s_1;
    int i = 0;
    getline(cin, s_1);
    if(is_palindromic_number(s_1)) {
        cout << s << " is a palindromic number.\n";
        return 0;
    }
    for(; i < 10; i++) {
        s_1 = make(s_1);
        if(is_palindromic_number(s_1)){
            break;
        }
    }
    if(i >= 10) {
        cout << "Not found in 10 iterations.\n";
    }
    return 0;
}