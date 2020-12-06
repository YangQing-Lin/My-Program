#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> core(m);
    vector<int> answer(m);
    for(int i = 0 ; i < m; i++) {
        cin >> core[i];
    }
    for(int i = 0 ; i < m; i++) {
        cin >> answer[i];
    }
    int sum, temp;
    while(n--) {
        sum = 0;
        for(int i = 0 ; i < m; i++) {
            cin >> temp;
            if(temp == answer[i]) sum += core[i];
        }
        cout << sum << endl;
    }
    return 0;
}