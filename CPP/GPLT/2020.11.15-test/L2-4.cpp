#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

int main() {
    int n, k, temp, a, b, m, flag, c, d;
    string str;
    cin >> n >> m;
    vector<vector<double> > arr(n+1);
    vector<int> book;
    for(int i = 0; i < n+1; i++) {
        arr[i].resize(n+1);
    }
    while(m--) {
        cin >> k;
        flag = -1;
        book.clear();
        book.resize(k);
        for(int i = 0; i < k; i++) {
            cin >> temp;
            // if(str.length() == 2 && str[0] == '-' && str[1] == 0) {
            //     flag = i;
            // }
            book[i] = temp;
        }
        for(int i = 0; i < k-1; i++) {
            for(int j = i+1; j < k; j++) {
                if(book[j] == 0 && book[i] == 0) {
                    arr[0][0] += 1.0/k;
                } else if(book[i] * book[j] < 0){
                    if(book[i] > 0) {
                        c = -book[j];
                        d = book[i];
                    } else {
                        c = -book[i];
                        d = book[j];
                    }
                    arr[c][d] += 1.0/k;
                    arr[c][n] = max(arr[c][n], arr[c][d]);
                    arr[n][d] = max(arr[n][d], arr[c][d]);
                }
            }
        }
    }
    cin >> a >> b;
    if(a < 0) {
        c = -a;
        d = b;
    } else {
        c = -b;
        d = a;
    }
    if(arr[c][n] == arr[c][d] && arr[n][d] == arr[c][d]) {
        printf("%d %d\n", a, b);
        return 0;
    }
    if(a < 0) c = -a;
    for(int i = 0; i < n; i++) {
        if(arr[c][i] == arr[c][n]) {
            printf("%d %d", a, i);
        }
    }
    return 0;
}