#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main() {
    int n, m, k, a, b;
    cin >> n >> m;
    vector<vector<int> > arr(n+1);
    vector<int> number(n+1);
    vector<int> temp_number(n+1);
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
        number[a]++;
        number[b]++;
    }
    cin >> k;
    int cnt, num;
    for(int i = 1; i <= k; i++) {
        temp_number = number;
        cin >> num;
        while (num--) {
            cin >> cnt;
            temp_number[cnt] = 0;
            for(int j = 0; j < arr[cnt].size(); j++) {
                temp_number[arr[cnt][j]]--;
            }
        }
        int j;
        for(j = 1; j <= n; j++) {
            if(temp_number[j] > 0) {
                printf("No\n");
                break;
            }
        }
        if (j > n) {
            printf("Yes\n");
        }
    }

    // int n, m, k, a, b;
    // cin >> n >> m;
    // vector<unordered_set<int> > arr(n+1);
    // vector<unordered_set<int> > temp_arr(n+1);
    // for(int i = 0; i < m; i++) {
    //     cin >> a >> b;
    //     arr[a].insert(b);
    //     arr[b].insert(a);
    // }
    // cin >> k;
    // int temp;
    // for(int i = 0; i < k; i++) {
    //     temp_arr = arr;
    //     cin >> temp;
    //     for(int j = 0; j < temp; j++) {
    //         cin >> a;
    //         for(auto it = temp_arr[a].begin(); it != temp_arr[a].end(); it++) {
    //             temp_arr[*it].erase(a);
    //         }
    //         temp_arr[a].clear();
    //     }
    //     int j;
    //     for(j = 1; j <= n; j++) {
    //         if(temp_arr[j].size() >= 1) {
    //             printf("NO\n");
    //             break;
    //         }
    //     }
    //     if(j == n + 1) printf("YES\n");
    // }
    // return 0;
}