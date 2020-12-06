#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x, y, id, max_id, max_dis = 0, min_id, min_dis = 10001;
    for(int i = 0; i < n; i++) {
        cin >> id >> x >> y;
        int dis = x * x + y * y;
        if(dis > max_dis) {
            max_dis = dis;
            max_id = id;
        }
        if(dis < min_dis) {
            min_dis = dis;
            min_id = id;
        }
    }
    printf("%04d %04d\n", min_id, max_id);
    return 0;
}