#include<map>
#include<iostream>
using namespace std;
int friends[105];
int animy[105][105] = {0};

int find(int root) {
    int temp, son;
    son = root;
    while(root != friends[root]) {
        root = friends[root];
    }
    while(son != root) {
        temp = friends[son];
        friends[son] = root;
        son = temp;
    }
    return root;
}

int main() {
    for(int i = 0; i < 105; i++) check[i] = i;
    int n, m, k;
    cin >> n >> m >> k;

    return 0;
}