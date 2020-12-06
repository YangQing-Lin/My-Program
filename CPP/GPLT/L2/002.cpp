#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100000;
struct NODE {
    int address;
    int key;
    int next;
    int num;
} node[maxn];
bool exist[maxn];
int cmp(NODE a, NODE b) {
    return a.num < b.num;
}
int main() {
    for(int i = 0; i < maxn; i++) {
        node[i].num = maxn*2;
    }
    int start_address, n, cnt1 = 0, cnt2 = 0;
    int temp_address, temp_key, temp_next;
    scanf("%d %d", &start_address, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &temp_address, &temp_key, &temp_next);
        node[temp_address].address = temp_address;
        node[temp_address].key = temp_key;
        node[temp_address].next = temp_next;
    }
    for(int i = start_address; i != -1; i = node[i].next) {
        if(exist[abs(node[i].key)] == false) {
            exist[abs(node[i].key)] = true;
            node[i].num = ++cnt1;
        }
        else {
            node[i].num = maxn + (++cnt2);
        }
    }
    sort(node, node + maxn, cmp);
    int cnt = cnt1 + cnt2;
    for(int i = 0; i < cnt; i++) {
        if(i != cnt1-1 && i != cnt-1) {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
        }
        else {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }
    return 0;
}