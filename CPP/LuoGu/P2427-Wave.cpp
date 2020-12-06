#include<iostream>
#include<vector>
using namespace std;

vector<string> arr;

int main() {
    int y_change[8] = {1,0,-1,0,1,-1,1,-1};
    int x_change[8] = {0,1,0,-1,1,1,-1,-1};
    int n, m, k;
    cin >> n >> m >> k;
    arr.resize(n);
    string temp;
    // cin >> temp;
    getchar();
    for(int i = 0; i < n; i++) {
        cin >> temp;
        arr[i] = temp;
    }
    int a, b;
    int count;
    char flag;
    for(int i = 0; i < k; i++) {
        count = 2;
        cin >> a >> b;
        flag = arr[a][b];
        while(true) {
            // printf("1\n");
            if(a-(count-1) < 0 || a+(count-1) >= n
            || b-(count-1) < 0 || b+(count-1) >= m) {
                cout << count << endl;
                break;
            }
            // printf("2\n");
            int a_temp = a - count + 1;
            int b_temp = b - count + 1;
            for(int j = 0; j < count*2-1; j++) {
                // printf("<%d>\n", j);
                if(arr[a_temp][b_temp+j] != flag) {
                    cout << count << endl;
                    break;
                }
                if(arr[a_temp+j][b_temp] != flag) {
                    cout << count << endl;
                    break;
                }
                if(arr[a+count-1][b_temp+j] != flag) {
                    cout << count << endl;
                    break;
                }
                if(arr[a_temp+j][b+count-1] != flag) {
                    cout << count << endl;
                    break;
                }
            }
            count++;
        }
    }




    // int a, b;
    // char flag;
    // int count = 0;
    // queue<int> x;
    // queue<int> y;
    // queue<int> empty_queue;
    // for(int i = 0; i < k; i++) {
    //     // printf("#1\n");
    //     count = 0;
    //     cin >> a >> b;
    //     flag = arr[a][b];
    //     count = 1;
    //     // printf("#2\n");
    //     x.push(a);
    //     y.push(b);
    //     int x_temp;
    //     int y_temp;
    //     while(!x.empty()) {
    //         int j;
    //         // printf("#3\n");
    //         for(j = 0; j < 8; j++) {
    //             // printf("^%d^\n", j);
    //             x_temp = x.front() + x_change[j];
    //             y_temp = y.front() + y_change[j];
    //             // if(j == 2) printf("%d %d\n", x_temp, y_temp);
    //             if(x_temp >= n || x_temp < 0
    //             || y_temp >= m || y_temp < 0
    //             || arr[x_temp][y_temp] != flag) {
    //                 break;
    //             }
    //             x.push(x_temp);
    //             y.push(y_temp);
    //         }
    //         // printf("#4\n");
    //         if(j != 4) {
    //             cout << count << endl;
    //             x = empty_queue;
    //             y = empty_queue;
    //             break;
    //         }
    //         count += 2;
    //         x.pop();
    //         y.pop();
    //         // printf("#5\n");
    //     }
    // }
    return 0;
}