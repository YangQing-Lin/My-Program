#include<iostream>
#include<list>
using namespace std;
int main() {
    list<int> arr;
    int n, m;
    while(true) {
        cin >> n >> m;
        printf("*\n");
        if(n == m && m == 0) break;
        printf("*\n");
        for(int i = 1; i <= n; i++) {
            arr.push_back(i);
            cout<< i << " &" << endl;
        }
        auto it = arr.begin();
        for(int i = 0; i < 40; i++) {
            cout << *it << endl;
            it++;
            if(it == arr.end()) it++;
        }
    }
    return 0;
}