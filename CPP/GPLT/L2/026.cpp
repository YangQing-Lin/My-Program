/*
广度优先搜索
用ans遍历整个族谱，遍历的同时设置每个人的辈分并存入history中，记录最大的辈分为index
最后遍历history，输出辈分等于idnex的id
注意：index是从1开始计数的
*/
#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;

struct peo {
    int id, level;
};

signed main() {
    int n, index, temp;
    cin >> n;
    vector<vector<int> > arr(n+1);
    queue<peo> ans;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        if (temp == -1) {
            index = i;
        } else {
            arr[temp].push_back(i);
        }
    }
    peo p, q;
    vector<peo> history;
    p.id = index;
    p.level = 1;
    ans.push(p);
    history.push_back(p);
    index = 1;
    while(!ans.empty()) {
        p = ans.front();
        for(int i = 0; i < arr[p.id].size(); i++) {
            q.id = arr[p.id][i];
            q.level = p.level + 1;
            if(q.level > index) index = q.level;
            ans.push(q);
            history.push_back(q);
        }
        ans.pop();
    }
    cout << index << endl;
    for(int i = 0; i < history.size(); i++) {
        // printf("%lld ", history[i].level);
        if (history[i].level == index) {
            cout << history[i].id;
            if (i != history.size() - 1) cout << " ";
        }
    }
    puts("");
    return 0;
}







// struct Node {
//     int name;
//     // int next_name;
//     int level;
// };

// bool cmp (Node a, Node, b) {
//     return a.name < b.name;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<unordered_set<int> > tree(n);
//     queue<Node> book;
//     int temp, father;
//     for(int i = 1; i <= temp; i++) {
//         cin >> temp;
//         if(temp != -1)
//             tree[temp].insert(i);
//         else
//             father = i;
//     }
//     Node temp_Node;
//     int max_level = 1;
//     temp_Node.name = father;
//     temp_Node.level = 1;
//     book.push(temp_Node);
//     vector<Node> child;
//     while(!book.empty()) {
//         max_level++;
//         for(auto it = tree[book.front().name].begin(); it != tree[book.front().name].end(); it++) {
//             temp_Node.name = *it;
//             temp_Node.level = max_level;
//             if(tree[(*it)].size() == 0) {
//                 child.push_back(temp_Node);
//             } else {
//                 book.push(temp_Node);
//             }
//         }
//         book.pop();
//     }
//     bool flag = false;
//     sort(child.begin(), child.end(), cmp);
//     for(int i = 0; i < child.size(); i++) {
//         if(child[i].level == max_level) {
//             if(flag) printf(" ");
//             printf("%d", child[i].name);
//             flag = true;
//         }
//     }
//     puts("");
//     return 0;
// }