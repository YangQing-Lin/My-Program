#include<bits/stdc++.h>
using namespace std;
#define ll long long

priority_queue<int, vector<int> > max_heap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, m, k, t, temp;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(max_heap.size() < k)
            max_heap.push(t);
        else if (max_heap.top() > t) {
            max_heap.pop();
            max_heap.push(t);
        }
    }
    while(m--) {
        cin >> t;
        if(t == 1) {
            cin >> temp;
            if(max_heap.size() < k)
                max_heap.push(temp);
            else if (max_heap.top() > temp) {
                max_heap.pop();
                max_heap.push(temp);
            }
        } else {
            if(max_heap.size() < k) cout << -1 << endl;
            else cout << max_heap.top() << endl;
        }
    }
    return 0;
}




// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// priority_queue<int, vector<int>, greater<int> > min_heap1, min_heap2;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     int n, m, k, t, temp;
//     cin >> n >> m >> k;
//     list<int> l;
//     for(int i = 0; i < n; i++) {
//         cin >> t;
//         min_heap1.push(t);
//     }
//     while(m--) {
//         cin >> t;
//         if(t == 1) {
//             cin >> temp;
//             min_heap1.push(temp);
//         } else {
//             if(min_heap1.size() < k) cout << -1 << endl;
//             else {
//                 while(!min_heap2.empty()) min_heap2.pop();
//                 int cnt = 0;
//                 while(!min_heap1.empty()) {
//                     min_heap2.push(min_heap1.top());
//                     cnt++;
//                     if(cnt == k) {
//                         printf("%d\n", min_heap1.top());
//                     }
//                     min_heap1.pop();
//                 }
//                 min_heap1 = min_heap2;
//             }
//         }
//     }
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main() {
//     int n, m, k, t, temp;
//     cin >> n >> m >> k;
//     vector<int> arr(n);
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     for(int i = 0 ; i < m; i++) {
//         cin >> t;
//         if(t == 1) {
//             cin >> temp;

//         }
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main() {
//     int n, m, k, t, temp;
//     cin >> n >> m >> k;
//     set<int,greater<int> > s;
//     while(n--) {
//         cin >> t;
//         s.insert(t);
//     }
//     while(m--) {
//         cin >> t;
//         if(t == 1) {
//             cin >> temp;
//             s.insert(temp);
//             printf("#%d\n", (int)s.size());
//         } else {
//             if(s.size() < k) cout << -1 << endl;
//             else {
//                 int cnt = 0;
//                 for(auto it = s.begin(); it != s.end(); it++) {
//                     cnt++;
//                     if(cnt == k) {
//                         cout << *it << endl;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     return 0;
// }