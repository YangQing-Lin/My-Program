#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main() {
    ull hp;
    ull a[3] = {1, 3, 7};
    ull b[3] = {1, 3, 9};
    cin >> hp;
    hp %= (7+9);
    while(true) {
        for(int i = 2; i >= 0; i--) {
            if(a[i] <= hp) {
                hp -= a[i];
                break;
            }
        }
        if(hp == 0) {
            printf("1\n");
            break;
        }
        for(int i = 2; i >= 0; i--) {
            if(b[i] <= hp) {
                hp -= b[i];
                break;
            }
        }
        if(hp == 0) {
            printf("2\n");
            break;
        }
    }
    return 0;
}