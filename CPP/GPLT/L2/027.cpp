#include<iostream>
#include<algorithm>
using namespace std;

struct NODE {
    string id;
    int code;
} node[10005];

int ranks[10005] = {0};

bool cmp(NODE a, NODE b) {
    if(a.code != b.code) return a.code > b.code;
    else return a.id < b.id;
}

int main() {
    int n, g, k, sum = 0;
    cin >> n >> g >> k;
    for(int i = 0 ; i < n; i++) {
        cin >> node[i].id >> node[i].code;
        if(node[i].code >= g) sum += 50;
        else if(node[i].code >= 60) sum += 20;
    }
    sort(node, node+n, cmp);
    cout << sum << endl;
    int temp = 1;
    ranks[0] = 1;
    for(int i = 1; i < n; i++) {
        if(node[i].code == node[i-1].code) {
            ranks[i] = temp;
        }
        else {
            ranks[i] = temp = i+1;
        }
        //cout << ranks[i] << endl;
    }
    // 注意for循环的判断条件！！！
    for(int i = 0; ranks[i] <= k && i < n; i++) {
        printf("%d %s %d\n", ranks[i], node[i].id.c_str(), node[i].code);
    }
    /*
    cout << "1 "+node[0].id+" " << node[0].code << endl;
    for(int i = 1; i < k; i++) {
        if(node[i].code == node[i-1].code) {
            cout << temp << " ";
        }
        else {
            cout << i+1 << " ";
            temp = i+1;
        }
        cout << node[i].id+" " << node[i].code << endl;
    }
    int i = 5;
    while(node[i].code == node[i-1].code && i < n) {
        cout << temp << " "+node[i].id+" " << node[i].code << endl;
        i++;
    }
    */
}