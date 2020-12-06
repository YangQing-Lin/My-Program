#include<iostream>
#include<map>
using namespace std;
int main(){
    int n, l, r;
    int index = 0;
    scanf("%d", &n);
    map<int, int> check;
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d", &l, &r);
        if(++check[l]>2) index++;
        if(++check[r]>2) index++;
    }
    cout << index << endl;
    return 0;
}