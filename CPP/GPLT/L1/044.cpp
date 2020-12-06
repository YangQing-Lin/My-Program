#include<iostream>
#include<map>
using namespace std;
int main() {
    int n, cnt = 0;
    string input;
    string arr[4] = {"ChuiZi", "Bu", "JianDao", "ChuiZi"};
    cin >> n;
    getchar();
    while(true) {
        cin >> input;
        if(input == "End") break;
        if(cnt == n) {
            cout << input << endl;
            cnt = 0;
            continue;
        }
        for(int i = 0; i < 4; i++) {
            if(arr[i] == input) {
                cout << arr[i + 1] << endl;
                cnt++;
                break;
            }
        }
    }   
    return 0;
}