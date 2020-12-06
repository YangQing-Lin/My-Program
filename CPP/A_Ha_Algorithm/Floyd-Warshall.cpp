/*
求任意两个点之间的最短路径
也称“多源最短路径”问题
时间复杂度: O(N^3)
核心代码行数: 5行
*/
#include<iostream>
using namespace std;
int main() {
    int e[10][10], n, m, t1, t2, t3;
    int inf = 9999999;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == j) e[i][j] = 0;
            else e[i][j] = inf;
    for(int i = 1; i <= m; i++) {
        cin >> t1 >> t2 >> t3;
        e[t1][t2] = t3;
    }

    // Floyd-Warshall算法核心语句
    // 从i号顶点到j号顶点只经过前k号顶点的最短路径
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(e[i][j] > e[i][k] + e[k][j])
                    e[i][j] = e[i][k] + e[k][j];
    
    // 输出整个数组
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%10d", e[i][j]);
        }
        puts("");
    }
    return 0;
}
/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/