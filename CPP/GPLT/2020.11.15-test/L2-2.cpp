#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

struct node{
    int id, cnt;
    double money;
};

bool cmp(node a, node b) {
    return a.money > b.money;
    // if(a.money != b.money) return a.money > b.money;
    // else if(a.cnt != b.cnt) return a.cnt > b.cnt;
    // else return a.id < b.id;
}

int main() {
    int n, temp, a, b;
    cin >> n;
    // if(n == 0) {
    //     printf("0 0.00\n");
    //     return 0;
    // }
    double number;
    vector<node> arr(n);
    for(int i = 0; i < n; i++) {
        arr[i].id = i+1;
    }
    for(int i = 0; i < n; i++) {
        cin >> temp;
        // printf("#%d#\n", temp);
        number = 0;
        while(temp--) {
            cin >> a >> b;
            number += b * 1.0 / 100;
            arr[a-1].money += b * 1.0 / 100;
            arr[a-1].cnt++;
        }
        arr[i].money -= number;
    }
    sort(arr.begin(), arr.end(), cmp);
    for(int i = 0; i < n; i++) {
        printf("%d %.2lf\n", arr[i].id, arr[i].money);
    }
    return 0;
}