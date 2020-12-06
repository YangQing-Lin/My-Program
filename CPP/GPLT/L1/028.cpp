#include<bits/stdc++.h>
using namespace std;

bool is_Prime(int n) {
    if(n == 2 || n == 3) return true;
    if(n <= 1 || n % 2 == 0) return false;
    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, temp;
    cin >> n;
    while(n--) {
        cin >> temp;
        if(is_Prime(temp)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}