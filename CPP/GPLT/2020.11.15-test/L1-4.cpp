#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

int main() {
    int n, m;
    cin >> n >> m;
    printf("%d ", m % 2 == 1 ? 1 : 0);
    for(int i = 0; i < m/2; i++) {
        n <<= 1;
    }
    printf("%d\n", n);
    return 0;
}