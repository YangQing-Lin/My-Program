#include<bits/stdc++.h>
using namespace std;

struct node {
    char ch;
    int len;
};

int main() {
    int n;
    node t;
    string str;
    cin >> n;
    cin >> str;
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    t.ch = str[0];
    t.len = 1;
    vector<node> book;
    for(int i = 1; i < str.length(); i++) {
        if(str[i] == t.ch) t.len++;
        else {
            book.push_back(t);
            t.ch = str[i];
            t.len = 1;
        }
    }
    if(book.size() == 0 || book[book.size() - 1].ch != t.ch) book.push_back(t);
    if(book.size() == 1) {
        cout << book[0].len << endl;
        return 0;
    }
    int maxn = -1;
    for(int i = 0; i < book.size(); i++) {
        int cnt = 0;
        // printf("%c %d\n", book[i].ch, book[i].len);
        // if(book[i].ch == 'B') {
        //     cnt += book[i].len;
        //     if(i + 1 < book.size()) {
        //         cnt += book[i+1].len;
        //     }
        //     if(i + 2 < book.size()) {
        //         cnt += book[i+2].len;
        //     }
        //     if(i - 1 >= 0) {
        //         cnt += book[i-1].len;
        //     }
        // }
        if(book[i].ch == 'A') {
            for(int j = 0; j < 4 && i + j < book.size(); j++) {
                cnt += book[i+j].len;
            }
        }
        maxn = max(maxn, cnt);
    }
    cout << maxn << endl;
    return 0;
}







// #include<bits/stdc++.h>
// using namespace std;

// struct node {
//     int len, start, end;
// };

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n), temp;
//     vector<node> book;
//     node t;
//     string str;
//     getchar();
//     cin >> str;
//     for(int i = 0; i < n; i++) arr[i] = str[i] - 'A';
//     t.len = t.start = 0;
//     bool flag = false;
//     for(int i = 0; i < n - 1; i++) {
//         if(arr[i] >= arr[i + 1]) {
//             t.len++;
//             if(arr[i] > arr[i + 1]) flag = true;
//         } else {
//             t.end = i;
//             if(t.len != 0 && flag) {
//                 book.push_back(t);
//                 flag = false;
//             }
//             t.start = i + 1;
//             t.len = 0;
//         }
//     }
//     if(t.len != 0) {
//         t.end = n - 1;
//         book.push_back(t);
//     }
//     for(int i = 0; i < book.size(); i++) {
//         printf("%d %d\n", book[i].start, book[i].end);
//     }
//     int a, b, max_line = -1;
//     for(int j = 0; j < book.size(); j++) {
//         temp = arr;
//         a = book[j].start;
//         b = book[j].end;
//         for(int k = 0; a+k < b-k; k++) {
//             swap(temp[a+k], temp[b-k]);
//         }
//         a = 0;
//         for(int i = 0; i < n - 1; i++) {
//             if(temp[i] <= temp[i+1]) a++;
//             else {
//                 max_line = max(max_line, a);
//             }
//         }
//     }
//     return 0;
// }