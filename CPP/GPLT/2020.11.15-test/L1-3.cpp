#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

int main() {
    int n, temp, a = 0, b = 0;
    cin >> n;
    while(n--) {
        cin >> temp;
        if(temp % 2 == 1) ++a;
        else ++b;
    }
    printf("%d %d\n", a, b);
    return 0;
}