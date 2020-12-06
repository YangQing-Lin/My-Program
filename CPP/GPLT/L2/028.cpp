#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cmath>
//#define int long long
using namespace std;
double arr[1005][1005] = {0};
int n;

void myprint(int number) {
    queue<double> history;
    double maxn = 0;
    if(number < 0) {
        for(int i = 0; i < n; i++) {
            maxn = max(arr[i][-number], maxn);
        }
        for(int i = 0; i < n; i++) {
            if (arr[i][-number] == maxn) {
                printf("%d %d\n",number, i);
            }
        }
    } else {
        for(int i = 0; i < n; i++) {
            maxn = max(arr[number][i], maxn);
        }
        for(int i = 0; i < n; i++) {
            if (arr[number][i] == maxn) {
                printf("%d %d\n",number, -i);
            }
        }
    }
}

signed main() {
    double m, cnt, num;
    cin >> n >> m;
    vector<int> book_man;
    vector<int> book_girl;
    while(m--) {
        book_girl.clear();
        book_man.clear();
        cin >> cnt;
        for(int k = 0; k < cnt; k++) {
            cin >> num;
            if(num >= 0) {
                book_man.push_back(num);
            } else {
                book_girl.push_back(-num);
            }
        }
        for(int i = 0; i < book_man.size(); i++) {
            for(int j = 0; j < book_girl.size(); j++) {
                arr[book_man[i]][book_girl[j]] += 1.0/cnt;
            }
        }
    }
    int number1, number2;
    cin >> number1 >> number2;
    myprint(number1);
    myprint(number2);
    return 0;
}