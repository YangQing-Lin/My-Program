#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, temp;
    cin >> n;
    while(n--) {
        cin >> temp;
        printf("%d", temp);
        for(int i = 1; i <= temp-1; i++) {
            printf(" %d", i);
        }
        puts("");
    }
    return 0;
}