// #include<bits/stdc++.h>
// using namespace std;

// struct node{
//     string name;
//     unordered_set<int> book;
//     int cnt;
// };

// int main() {
//     int n, m, k;
//     cin >> n;
//     getchar();
//     vector<node> arr(3);
//     node input, temp;
//     for(int i = 0; i < n; i++) {
//         cin >> input.name;
//         scanf("%d", &m);
//         input.cnt = m;
//         while(m--) {
//             scanf("%d", &k);
//             input.book.insert(k);
//         }
//         getchar();
//         for(int j = 0; j < 3; j++) {
//             if(input.book.size() > arr[j].book.size()) {
//                 temp = input;
//                 input = arr[j];
//                 arr[j] = temp;
//             } 
//             // else if (input.book.size() == arr[j].book.size()
//             // && input.cnt < arr[j].cnt) {
//             //     temp = input;
//             //     input = arr[j];
//             //     arr[j] = temp;
//             // }
//         }
//     }
//     for(int i = 0; i < 3; i++) {
//         if(i != 0) printf(" ");
//         if(i <= n-1) printf("%s", arr[i].name.c_str());
//         else printf("-");
//     }
//     puts("");
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;

struct node{
    string name;
    unordered_set<int> book;
};

bool cmp(node a, node b) {
    return a.book.size() > b.book.size();
}

int main() {
    int n, m, k;
    cin >> n;
    getchar();
    vector<node> arr(n);
    node input;
    for(int i = 0; i < n; i++) {
        cin >> input.name;
        cin >> m;
        while(m--) {
            cin >> k;
            input.book.insert(k);
        }
        getchar();
        arr[i] = input;
    }
    sort(arr.begin(), arr.end(), cmp);
    int z = n >= 3 ? 3 : n;
    for(int i = 0; i < z; i++) {
        if(i != 0) printf(" ");
        printf("%s", arr[i].name.c_str());
    }
    if(n == 0) {
        printf("-");
        n++;
    }
    if(n < 3) {
        int i = 3 - n;
        while(i--) {
            printf(" -");
        }
    }
    puts("");
    return 0;
}