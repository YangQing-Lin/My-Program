#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

int main() {
    int n;
    cin >> n;
    if(n <= 3) {
        cout << n << endl;
        return 0;
    }
    vector<int> arr(13);
    arr[0] = 1;
    for(int i = 1; i < 13; i++) {
        arr[i] = arr[i-1] * 2;
    }
    for(int i = 1; i < 13; i++) {
        arr[i] += arr[i-1];
        if(arr[i] >= n) {
            cout << n - arr[i-2] << endl;
            break;
        }
    }
    return 0;
}