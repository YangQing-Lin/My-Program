#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vector<int> a(x);
        vector<int> b(x);
        for(int j = 0; j < x; j++) {
            cin >> a[j];
        }
        for(int j = 0; j < x; j++) {
            cin >> b[j];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), cmp);
        int j;
        for(j = 0; j < x; j++) {
            if(a[j] + b[j] > y) {
                printf("No\n");
                break;
            }
        }
        if(j == x) {
            printf("Yes\n");
        }
    }
    return 0;
}