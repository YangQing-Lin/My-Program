#include<iostream>
using namespace std;

int check(string temp) {
    bool has_number = false;
    bool has_char = false;
    if(temp.length() < 6) {
        return 0;
    }
    for (char ch : temp) {
        if(ch >= '0' && ch <= '9') {
            has_number = true;
        } else if (isalpha(ch)){
            has_char = true;
        } else if (ch != '.') {
            return 1;
        }
    }
    if (!has_number) {
        return 2;
    }
    if (!has_char) {
        return 3;
    }
    return 4;
}

int main() {
    int n;
    cin >> n;
    string temp;
    getchar();
    for(int i = 0; i < n; i++) {
        bool has_number = false;
        bool has_char = false;
        getline(cin, temp);
        switch(check(temp)) {
            case 0:
                cout << "Your password is tai duan le.\n";
                break;
            case 1:
                cout << "Your password is tai luan le.\n";
                break;
            case 2:
                cout << "Your password needs shu zi.\n";
                break;
            case 3:
                cout << "Your password needs zi mu.\n";
                break;
            case 4:
                cout << "Your password is wan mei.\n";
                break;
        }
    }
    return 0;
}