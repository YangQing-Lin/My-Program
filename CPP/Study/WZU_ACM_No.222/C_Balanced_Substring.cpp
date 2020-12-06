#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    string str;
    int num_0, num_1, num;
    cin >> num;
    cin >> str;
    num_0 = num_1 = 0;
    for(int i = 0; i < num; i++) {
        if(str[i] == '0') num_0++;
        else num_1++;
    }
    cout << min(num_0, num_1)*2 << endl;
    return 0;
}