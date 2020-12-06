#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n, r, a, b, x, y;
    cin >> n >> r >> a >> b;
    double index_x, index_y;
    bool flag = false;
    vector<int> arr(max(abs(a), abs(b)));
    if(a == 0) {
        index_x = 0;
        index_y = 1;
    } else {
        index_x = 1;
        index_y = b/a;
        flag = true;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if(flag) {
            int j = 0;
            for(int i = 0; i <= a; i++, j += index_y){
                if(sqrt(pow(abs(x-i), 2)+pow(abs(y-j), 2)) <= 10){
                    ++arr[i];
                }
            }
        } else {
            int i = 0;
            for(int j = 0; j <= b; j++, j += index_y){
                if(sqrt(pow(abs(x-i), 2)+pow(abs(y-j), 2)) <= 10){
                    ++arr[i];
                }
            }
            ////////////放弃了
        }
    }
    return 0;
}