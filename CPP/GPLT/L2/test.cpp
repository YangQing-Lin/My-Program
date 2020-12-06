#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, count = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i != 0) {
            if(arr[i] < arr[i-1]) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}