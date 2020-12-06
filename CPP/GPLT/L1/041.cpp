#include<iostream>
using namespace std;
int main() {
    int n = 0;
    int temp;
    while(true) {
        cin >> temp;
        n++;
        if(temp == 250) {
            cout << n << endl;
            break;
        }
    }
    return 0;
}