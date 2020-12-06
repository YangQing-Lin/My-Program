#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m, temp, max_index = 1;
    cin >> n;
    vector<vector<int> > tree(n+1);
    queue<int> book;
    int arr[100005];
    for(int i = 1; i <= n; i++) arr[i] = i;
    for(int i = 1; i <= n; i++) {
        
        cin >> m;
        for(int j = 1; j <= m; j++) {
            cin >> temp;
            tree[i].push_back(temp);
            arr[temp] = i;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(arr[i] == i) {
            book.push(i);
            break;
        }
    }
    while(!book.empty()) {
        temp = book.front();
        for(int i = 0; i < tree[temp].size(); i++) {
            book.push(tree[temp][i]);
        }
        book.pop();
    }
    cout << temp << endl;
    return 0;
}