#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll index = 1, n, temp, sum = 0;
    cin >> n;
    while(n--) {
        cin >> temp;
        // sum = 0;
        // index = 1;
        // for(int i = 1; i < temp; i++) {
        //     index = index * i;
        //     printf(" %d * %lld + ", i, index);
        //     sum += i * index;
        // }
        cout << temp - 1 << endl;

    }
    return 0;
}