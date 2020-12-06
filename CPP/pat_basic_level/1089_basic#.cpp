#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> said(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> said[i];
    }
    for(int i = 1; i <= n-1; i++) {
        for(int j = i+1; j <= n; j++) {
            vector<int> is_wolf(n+1, 1);
            is_wolf[i] = -1;
            is_wolf[j] = -1;
            vector<int> lie;
            for(int k = 1; k <= n; k++) {
                if(said[k] * is_wolf[abs(said[k])] < 0) {
                    lie.push_back(k);
                }
            }
            if(lie.size() == 2 && is_wolf[lie[0]] + is_wolf[lie[1]] == 0) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}