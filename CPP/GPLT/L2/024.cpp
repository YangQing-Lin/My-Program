#include<bits/stdc++.h>
using namespace std;

int pre[10005] = {0};

int find(int root) {
    int tmp, son;
    son = root;
    while(pre[root] != root) {
        root = pre[root];
    }
    while(son != root) {
        tmp = pre[son];
        pre[son] = root;
        son = tmp;
    }
    return root;
}

int main() {
    unordered_set<int> check;
    unordered_set<int> roots;
    vector<int> arr;
    for(int i = 0; i < 10004; i++) pre[i] = i;
    int n, k, temp;
    cin >> n;
    while(n--) {
        cin >> k;
        while(k--) {
            cin >> temp;
            check.insert(temp);
            arr.push_back(temp);
            pre[find(arr[0])] = find(temp);
        }
        arr.clear();
    }
    for(auto it = check.begin(); it != check.end(); it++) {
        roots.insert(find(*it));
    }
    printf("%d %d\n", (int)check.size(), (int)roots.size());
    cin >> k;
    int a, b;
    while(k--) {
        cin >> a >> b;
        if(find(a) != find(b)) {
            printf("N\n");
        } else {
            printf("Y\n");
        }
    }
    return 0;
}