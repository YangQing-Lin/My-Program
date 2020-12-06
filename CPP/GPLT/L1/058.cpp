#include<iostream>
using namespace std;

string exchange(string str, int count, int i) {
    if (count > 3 && count <= 9) {
        str = str.substr(0, i-count) + '9' + str.substr(i);
    } else if (count > 9) {
        str = str.substr(0, i-count) + "27" + str.substr(i);
    }
    return str;
}

int main() {
    string str;
    getline(cin, str);
    int count = 0, i;
    for(i = 0; i < str.length(); i++) {
        if(str[i] == '6') {
            count++;
        } else {
            str = exchange(str, count, i);
            i -= count;
            count = 0;
        }
    }
    if(count != 0) {
        str = exchange(str, count, i);
    }
    cout << str << endl;
    return 0;
}