#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> keys(100000);
    for(int i = 0; i < N; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        keys[temp1].push_back(temp2);
        keys[temp2].push_back(temp1);
    }
    for(int i = 0; i < M; i++) {
        map<int, int> check;
        int n;
        cin >> n;
        bool flag = true;
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            check[temp] = 1;
            for(int k = 0; k < keys[temp].size(); k++) {
                if(check[keys[temp][k]] == 1) {
                    cout << "No" << endl;
                    flag = false;
                    break;
                }
            }
            if(flag == false) {
                break;
            }
        }
        if(flag == true) {
            cout << "Yes" << endl;
        }
    }
    return 0;
}