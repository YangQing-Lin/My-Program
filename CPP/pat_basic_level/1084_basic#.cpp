#include<iostream>
using namespace std;
int main(){
    string last_str;
    string this_str;
    int n;
    cin >> last_str >> n;
    if(n == 1) {
        cout << last_str << endl;
        return 0;
    }
    last_str += '1';
    for(int i = 2; i < n; i++) {
        int cnt = 1;
        this_str = last_str[0];
        for(int i = 0; i < last_str.length() - 1; i++) {
            if(last_str[i] == last_str[i + 1]) {
                cnt++;
            } else {
                this_str += (cnt + '0');
                this_str += last_str[i + 1];
                cnt = 1;
            }
        }
        this_str += (cnt + '0');
        last_str = this_str;
    }
    cout << last_str << endl;
    return 0;
}