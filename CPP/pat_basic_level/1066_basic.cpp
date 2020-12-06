#include <iostream>
using namespace std;
int main() {
    int n, m;
    int p, q;
    int flag;
    int map[501][501] = {0};
    cin >> n >> m >> p >> q >> flag;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            if(temp >= p && temp <= q) {
                temp = flag;
            }
            map[i][j] = temp;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j) {
                printf(" ");
            }
            printf("%03d", map[i][j]);
        }
        puts("");
    }
    return 0;
}