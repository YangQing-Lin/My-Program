/*
学长的做法：upper_bound + vector.insert
upper_bound:返回数组中第一个大于被查数的下标
vector.insert：在数组的指定下标插入数字
最后输出i/2下标的数字就行
*/
// 

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > minn;
priority_queue<int, vector<int> > maxn;

int main() {
    int n, half, temp;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        if(i == 1) {
            half = temp;
            cout << half << endl;
        }
        else {
            if(temp >= half) {
                minn.push(temp);
            } else {
                maxn.push(temp);
            }
            if (i % 2 != 0 && maxn.size() != minn.size()) {
                if (maxn.size() > minn.size()) {
                    minn.push(half);
                    half = maxn.top();
                    maxn.pop();
                } else {
                    maxn.push(half);
                    half = minn.top();
                    minn.pop();
                }
            }
            if (i % 2 != 0) cout << half << endl;
        }
    }
    return 0;
}


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main() {
//     int n, temp;
//     cin >> n;
//     vector<int> arr;
//     for(int i = 1; i <= n; i++) {
//         cin >> temp;
//         arr.push_back(temp);
//         if(i == 1) cout << temp << endl;
//         else if (i % 2 != 0){
//             sort(arr.begin(), arr.end());
//             cout << arr[i / 2] << endl;
//         }
//     }
//     return 0;
// }