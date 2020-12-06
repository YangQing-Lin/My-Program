#include<bits/stdc++.h>
using namespace std;

struct node {
    int front, data, next;
};

int main() {
    int start, n;
    cin >> start >> n;
    map<int, node> check; // 以头指针为下标存储每个节点
    vector<node> v, answer; // 链表和最后输出的答案
    node temp_node;
    int temp = n;
    while(temp--) {
        cin >> temp_node.front >> temp_node.data >> temp_node.next;
        check[temp_node.front] = temp_node;
    }
    temp = start; // 使用头指针遍历链表并记录在数组中
    while(temp != -1) {
        v.push_back(check[temp]);
        temp = check[temp].next;
    }
    int r = v.size()-1, l = 0; // 一开始r的初始值给的是n-1
    // 但是以只有一个测试点过不去，后来发现题目有一个隐藏条件：
    // 输入的所有节点并不一定都是链表里的
    // 也就是说链表的最终长度可能比输入的n小！
    // 这题也太坑了吧……
    while(true) {
        answer.push_back(v[r]);
        r--;
        if(r < l) break;
        answer.push_back(v[l]);
        l++;
        if(r < l) break;
    }
    for(int i = 0; i < (int)answer.size(); i++) {
        if(i != (int)answer.size()-1) {
            printf("%05d %d %05d\n", answer[i].front, answer[i].data, answer[i+1].front);
        } else {
            printf("%05d %d -1\n", answer[i].front, answer[i].data);
        }
    }
    return 0;
}





// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int start, n;
//     cin >> start >> n;
//     vector<int> list; // 按照链表顺序生成节点值的数组
//     map<int, int> check; // 以头指针为下标查找尾指针
//     map<int, int> node_check; // 以节点值为下标查找头指针
//     map<int, int> book; // 以头指针为下标查找节点值
//     int temp = n, a, b, c;
//     while(temp--) {
//         cin >> a >> b >> c;
//         check[a] = c;
//         book[a] = b;
//         node_check[b] = a;
//     }
//     temp = start; // 使用头指针遍历链表并记录在数组中
//     while(temp != -1) {
//         list.push_back(book[temp]);
//         temp = check[temp];
//     }
//     int i = n-1, j = 0;
//     while(i >= j) { // i, j指针从数组两端开始向中间移动，每次输出对应的两个节点
//         printf("%05d %d %05d\n", node_check[list[i]], list[i], node_check[list[j]]);
//         printf("%05d %d ", node_check[list[j]], list[j]);
//         if(j+1 > i-1) {
//             printf("-1\n");
//             break;
//         } else {
//             printf("%05d\n", node_check[list[i-1]]);
//         }
//         i--;j++;
//         if(i == j) {
//             printf("%05d %d -1\n", node_check[list[i]], list[i]);
//             break;
//         }
//     }
//     return 0;
// }
/*
00100 5
00000 4 99999
00100 1 12309
33218 3 00000
99999 5 -1
12309 2 33218
*/
/*
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/