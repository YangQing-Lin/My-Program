#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    double h, w, k;
    while(n--) {
        cin >> h >> w;
        k = (h-100)*1.8;
        if(fabs(w-k) < k*0.1) {
            printf("You are wan mei!\n");
        } else if (w-k > 0) {
            printf("You are tai pang le!\n");
        } else {
            printf("You are tai shou le!\n");
        }
    }
    return 0;
}