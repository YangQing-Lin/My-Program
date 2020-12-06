// Wina
#include<iostream>
#include<map>
#include<algorithm>

struct Node{
    int left;
    int right;
};

map<int, Node> check;

int arr[2001][2001] = {0};
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < 2*n; j+=2) {
            cin >> arr[i][j];
            check[arr[i][j]].left = i;
            check[arr[i][j]].right = j;
        }
    }
    sort(check.begin(); check.end());
}