#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<set<int> > arr(n);
    for(int i = 0; i < n; i++) {
        int number;
        int temp;
        cin >> number;
        for(int j = 0; j < number; j++) {
            cin >> temp;
            arr[i].insert(temp);
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;
        double nc = 0, nt = arr[q-1].size();
        for(auto it = arr[p-1].begin(); it != arr[p-1].end(); it++) {
            if(arr[q-1].find(*it) == arr[q-1].end()) {
                nt++;
            }
            else {
                nc++;
            }
        }
        printf("%.2lf%%\n", nc/nt*100);
    }
    return 0;
}