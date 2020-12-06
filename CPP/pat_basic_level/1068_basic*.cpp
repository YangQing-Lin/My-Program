#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int main() {
    int right[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int down[] =  {-1, -1, -1, 0, 0, 1, 1, 1};
    int Map[1001][1001] = {0};
    int m, n, delta;
    cin >> m >> n >> delta;
    int y, x;
    int sum = 0;
    int find_y, find_x, find_number;
    map<int, int> check;
    for (y = 0; y < n; y++) {
        for ( x = 0; x < m; x++) {
            cin >> Map[y][x];
            check[Map[y][x]]++;
        }
    }
    for (y = 1; y < n - 1; y++) {
        for ( x = 1; x < m - 1; x++) {
            if(check[Map[y][x]] == 1) {
                int i;
                for(i = 0; i < 8; i++) {
                    if(fabs(Map[y][x] - Map[y + right[i]][x + down[i]]) <= delta) {
                        break;
                    }
                }
                if(i == 8) {
                    sum++;
                    find_x = x;
                    find_y = y;
                    find_number = Map[y][x];
                }
            }
        }
    }
    if(sum == 0) {
        cout << "Not Exist" << endl;
    } else if(sum == 1){
        printf("(%d, %d): %d\n", find_x+1, find_y+1, find_number);
    } else {
        cout << "Not Unique" << endl;
    }
    return 0;
}