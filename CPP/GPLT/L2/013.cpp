#include<bits/stdc++.h>
using namespace std;

bool visit[510];
int e[510][510] = {0}, n, m;

void dfs(int node) {
    visit[node] = true;
    for(int i = 0; i < n; i++) {
        if(visit[i] == false && e[node][i] == 1) {
            dfs(i);
        }
    }
}

int countcnt() {
    int count = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        if(visit[i] == false) {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main() {
    int a, b, city, k;
    scanf("%d%d", &n, &m);
    // cin >> n >> m;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        // cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    int cnt = countcnt();
    scanf("%d", &k);
    // cin >> k;
    for(int i = 0; i < k; i++) {
        scanf("%d", &city);
        // cin >> city;
        for(int j = 0; j < n; j++) {
            if(e[city][j] == 1) {
                e[city][j] = e[j][city] = 0;
            }
        }
        int tempcnt = countcnt();
        if(tempcnt > cnt + 1) {
            printf("Red Alert: City %d is lost!\n", city);
        } else {
            printf("City %d is lost.\n", city);
        }
        cnt = tempcnt;
        if(i == n - 1) printf("Game Over.\n");
    }
    return 0;
}



// #include <cstdio>
// #include <algorithm>
// using namespace std;

// bool visit[510]; // visit：标记节点是否被访问过
// int e[510][510], n, m, k; // e：图的邻接矩阵

// /*
// 图的连通分量的定义：
// 连通分量：不连通的图是由2个或者2个以上的连通子图组成的。这些不相交的连通子图称为图的连通分量。
// 简单来说就是有几个完全分离的子图，那么整个图的连通分量就是多少
// */
// void dfs(int node) {
//     // 先将当前节点标记为“已访问”
//     visit[node] = true;
//     for(int i = 0; i < n; i++) {
//         // 如果与当前节点连通的其它节点未被访问，则递归访问它
//         // 其实这是一个深搜遍历所有整个连通图的做法
//         // 就像广搜一样，遍历整个子图并标记，那么这就是一个完整的连通图
//         if(visit[i] == false && e[node][i] == 1)
//         dfs(i);
//     }
// }
// int countcnt() {
//     int cnt = 0;
//     fill(visit, visit + 510, false);
//     for(int i = 0; i < n; i++) {
//         if(visit[i] == false) {
//             // 以当前节点为中心，深搜整个子图并标记
//             dfs(i);
//             // 搜索完一个子图之后计数器+1
//             cnt++;
//         }
//     }
//     return cnt;
// }

// int main() {
//     scanf("%d%d", &n, &m);
//     int a, b, city;
//     for(int i = 0; i < m; i++) {
//         scanf("%d%d", &a, &b);
//         e[a][b] = e[b][a] = 1;
//     }
//     // 获取图的连通分量
//     int cnt = countcnt();
//     scanf("%d", &k);
//     for(int i = 0; i < k; i++) {
//         scanf("%d", &city);
//         for(int j = 0; j < n; j++) {
//             if(e[city][j] == 1) {
//                 e[city][j] = 0;
//                 e[j][city] = 0;
//             }
//         }
//         int tempcnt = countcnt();
//         if(tempcnt > cnt + 1)
//             printf("Red Alert: City %d is lost!\n", city);
//         else
//             printf("City %d is lost.\n", city);
//         cnt = tempcnt;
//         if(i == n - 1) printf("Game Over.\n");
//     }
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n, m, a, b, count;
//     cin >> count >> m;
//     vector<unordered_set<int> > tree(count);
//     while(m--) {
//         cin >> a >> b;
//         tree[a].insert(b);
//         tree[b].insert(a);
//     }
//     cin >> n;
//     bool flag = false;
//     for(int i = 0; i < n; i++) {
//         cin >> m;
//         flag = false;
//         for(auto it = tree[m].begin(); it != tree[m].end(); it++) {
//             tree[*it].erase(m);
//             if(tree[*it].size() == 0) flag = true;
//         }
//         tree[m].clear();
//         if(flag) printf("Red Alert: City %d is lost!\n", m);
//         else printf("City %d is lost.\n", m);
//         if(i == count-1) printf("Game Over.\n"); 
//     }
//     return 0;
// }

/*
#include <cstdio>
#include <algorithm>
using namespace std;
bool visit[510];
int e[510][510], n, m, k;
void dfs(int node) {
    visit[node] = true;
    for(int i = 0; i < n; i++) {
        if(visit[i] == false && e[node][i] == 1)
            dfs(i);
    }
}
int countcnt() {
    int cnt = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        if(visit[i] == false) {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d", &n, &m);
    int a, b, city;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    int cnt = countcnt();
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &city);
        for(int j = 0; j < n; j++) {
            if(e[city][j] == 1) {
                e[city][j] = 0;
                e[j][city] = 0;
            }
        }
        int tempcnt = countcnt();
        if(tempcnt > cnt + 1)
            printf("Red Alert: City %d is lost!\n", city);
        else
            printf("City %d is lost.\n", city);
        cnt = tempcnt;
        if(i == n - 1) printf("Game Over.\n");
    }
    return 0;
}
*/