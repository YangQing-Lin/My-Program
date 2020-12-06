#include<iostream>
#include<stack>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int arr[1005];
    for(int i = 1; i <= k; i++) {
        stack<int> check;
        int index = 1;
        int j;
        for(j = 1; j <= n; j++) {
            cin >> arr[j];
        }
        for(j = 1; j <= n; j++) {
            if(arr[j] == index) {
                index++;
                while(!check.empty() && check.top() == index) {
                    index++;
                    check.pop();
                }
            }
            else {
                check.push(arr[j]);
                if(check.size() > m) {
                    break;
                }
            }
        }
        if(j > n && check.size() == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}