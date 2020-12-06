#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int teacher;
        int max = 0;
        int min = m + 1;
        int cnt = -2;
        int sum = 0;
        cin >> teacher;
        int temp;
        for(int j = 0; j < n - 1; j++) {
            cin >> temp;
            if(temp >= 0 && temp <= m) {
                cnt++;
                sum += temp;
                if (temp > max) {
                    max = temp;
                }
                if (temp < min) {
                    min = temp;
                }
            }
        }
        int score = ((double)(sum - min - max) / cnt + teacher) / 2 + 0.5;
        cout << score << endl;
    }
    return 0;
}