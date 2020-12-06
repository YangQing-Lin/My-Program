/*
让每个学校的学生排成一排，为每一个座位安排学生
check[i]是一个学校的队伍数，id_school[i]的值表示第i个座位上坐的是那个学校的学生
每把椅子一次从每个学校面前走过，如果这个学校还有学生没被安排座位，那就安排他
安排方案为：如果此座位(cnt)前一个不是本校学生，那么抓一个此校学生坐在这把椅子上，并在id_school里标记
如果前一个是本校学生，那此位置空着，抓一个此校学生放在后面一把椅子上面，并标记
flag标记当前循环是否有学生被安排了位置，如果没有学生被安排，说明座位分配完毕，退出循环
*/
#include<iostream>
#include<vector>
#include<set>
#define max_int 2100000000
using namespace std;
int main() {
    int n, id_school[10005] = {0}, temp, cnt = 1;
    cin >> n;
    vector<vector<int> > arr(n+1);
    vector<int> check(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        check[i] = temp;
    }
    bool flag = false;
    while (true) {
        flag = true;
        for (int i = 1; i <= n; i++) {
            if (arr[i].size() < check[i] * 10) {
                if (id_school[cnt-1] != i) {
                    id_school[cnt] = i;
                    arr[i].push_back(cnt);
                    cnt++;
                } else {
                    id_school[cnt+1] = i;
                    arr[i].push_back(cnt+1);
                    cnt += 2;
                }
                flag = false;
            }
        }
        if (flag) break;
    }
    for(int i = 1; i <= n; i++) {
        printf("#%d\n", i);
        for(int j = 0; j < arr[i].size(); j++) {
            if(j % 10 != 0) printf(" ");
            else if (j != 0) cout << endl;
            cout << arr[i][j];
        }
        puts("");
    }
    return 0;
}