/*
分析：必须要车号大的先出，小的后出。所以列车排队的每一队必须是从大到小排列（从右往左看），才能保证开出去的车也是从大到小的。
对于每一个想要进入并列铁轨的车，如果车号大于每一队的队尾的车号，说明不能进入已经有的队伍，必须进入新的铁轨
否则，选择一个最接近它车号的尾部车号的队伍进入
其实无需保存每一个并行队列的所有值，只需要保存当前队伍的车尾（就是每一列最左边 即 每一列的最小值）即可
因为每一次都是需要排序比较大小的，所以用set自动排序
首先把set里面放入一个0值。每一次set的最后一个值s.rbegin()都是当前所有队列队尾的最大值.
如果当前想要进入排队队伍的t值比集合里面最大值小，就移除第一个比他大的值，然后把t插入集合中。表示的是将t值插入了最接近它车号的队伍的队尾
否则就直接插入进去t值。作为新的队伍。
s.upper_bound(t)返回的是第一个大于t的迭代器的位置
在前面加星号表示取这个位置的值
所以s.erase(*(s.upper_bound(t)));表示删除当前这个刚好大于t的位置处的值
因为一开始插入了一个没有的0，所以最后输出是s.size()-1;
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    cin >> n;
    set<int> s;
    s.insert(0);
    while(n--) {
        cin >> t;
        if(t < *s.rbegin()) {
            s.erase(*(s.upper_bound(t)));
        }
        s.insert(t);
    }
    cout << s.size()-1 << endl;
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i = 1; i <= n; i++) {
//         cin >> arr[n-i];
//     }
//     int count = 1;
//     while(n != 0) {
//         if(arr[0] == n) {
//             arr.erase(arr.begin());
//         } else if (*(arr.end()-1) == n) {
//             arr.erase(arr.end()-1);
//         } else {
//             count++;
//             // printf("#%d#\n", n);
//             for(auto it = arr.begin(); it != arr.end(); it++) {
//                 if(*it == n) {
//                     arr.erase(it);
//                     break;
//                 }
//             }
//         }
//         n--;
//     }
//     cout << count << endl;
//     return 0;
// }