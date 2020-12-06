#include<bits/stdc++.h>
using namespace std;
int main() {
    string name;
    int n, a, b;
    char temp;
    cin >> n;
    getchar();
    while(n--) {
        cin >> name >> a >> b;
        getchar();
        if(a < 15 || a > 20 || b < 50 || b > 70) {
            cout << name << endl;
        }
    }
    return 0;
}