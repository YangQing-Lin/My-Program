#include<iostream>
#include<list>
using namespace std;
int main() {
    list<int> arr;
    int n, m;
    while(true) {
        cin >> n >> m;
        if(n == m && m == 0) break;
        for(int i = 1; i <= n; i++) {
            arr.push_back(i);
        }
        int index = 0;
        auto it = arr.begin();
        bool flag = false;
        while(arr.size() > 2) {
            ++index;
            flag = false;
            if(index == m) {
                printf("%d**\n", *it);
                arr.erase(it++);
                if(it == arr.end()) it++;
                flag = true;
                index = 0;
            } else printf("%d\n", *it);
            if(!flag) it++;
        }
        cout << *it << endl;
        arr.clear();
    }
    return 0;
}