#include<bits/stdc++.h>
using namespace std;
int main() {
    int v, e, k, n;
    cin >> v >> e >> k;
    vector<vector<int> > book(v+1);
    vector<vector<bool> > has_road(v+1);
    for(int i = 0; i < v+1; i++) {
        book[i].resize(v+1);
        has_road[i].resize(v+1);
    }
    int a, b;
    while(e--) {
        scanf("%d %d", &a, &b);
        has_road[a][b] = true;
        has_road[b][a] = true;
    }
    cin >> n;
    // printf("###%d###\n", n);
    int i, j;
    vector<vector<int> > temp_book;
    while(n--) {
        temp_book = book;
        // printf("#%d#\n", (int)temp_book.size());
        bool flag = true;
        unordered_set<int> check;
        for(i = 1; i <= v; i++) {
            scanf("%d", &a);
            check.insert(a);
            temp_book[i][i] = a;
        }
        // 使用的颜色个数必须和第一行给出的k值相同
        // 这里坑死我了！！！
        if(check.size() != k) {
            printf("No\n");
            continue;
        }
        for(i = 1; i <= v; i++) {
            for(j = 1; j <= v; j++) {
                if(i != j && has_road[i][j] 
                && temp_book[j][j] == temp_book[i][i]) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag) {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
    return 0;
}
/*
6 8 3
2 1
1 3
4 6
2 5
2 4
5 4
5 6
3 6
4
1 2 3 3 1 2
4 5 6 6 4 5
1 2 3 4 5 6
2 3 4 2 3 4
*/