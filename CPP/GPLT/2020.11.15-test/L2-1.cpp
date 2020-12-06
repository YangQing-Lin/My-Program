#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

int main() {
    int i, m, n, k, max_size = 0, this_size = 0;
    cin >> m >> n >> k;
    vector<int> arr(n);
    while(k--) {
        for(i = 0; i < n; i++) {
            cin >> arr[i];
        }
        max_size = this_size = arr[0];
        for(i = 1; i < n-1; i++) {
            if(this_size > m) {
                printf("NO\n");
                break;
            }
            if(arr[i] < max_size && arr[i+1] > arr[i]) {
                printf("NO\n");
                break;
            }
            if(arr[i] > max_size) {
                this_size = arr[i] - i;
                max_size = arr[i];
            }
        }
        if(i == n-1) printf("Yes\n");
    }
    return 0;
}