#include<iostream>
#include<map>
using namespace std;
int main(){
    int n, m;
    int sum_student = 0;
    int sum_cnt = 0;
    cin >> n >> m;
    map<int, int> check;
    getchar();
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        check[temp] = 1;
    }
    getchar();
    for(int i = 0; i < n; i++) {
        string name;
        int cnt;
        int temp;
        bool flag = true;
        cin >> name >> cnt;
        for(int j = 0; j < cnt; j++) {
            cin >> temp;
            if(check[temp] == 1) {
                if(flag) {
                    //printf("%s:", name);
                    cout << name << ":";
                    flag = false;
                    sum_student++;
                }
                printf(" %04d", temp);
                sum_cnt++;
            }
        }
        getchar();
        if(!flag) {
            puts("");
        }
    }
    printf("%d %d\n", sum_student, sum_cnt);
    return 0;
}