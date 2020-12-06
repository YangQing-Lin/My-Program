#include<iostream>
#include<map>
using namespace std;
int main(){
    int m, n, s;
    cin >> m >> n >> s;
    map<string, int> check;
    bool flag = true;
    int cnt = 0;
    getchar();
    for(int i = 1; i <= m; i++) {
        string temp;
        getline(cin, temp);
        if(i == s) {
            check[temp] = 1;
            cout << temp << endl;
            flag = false;
        } else if(i > s) {
            cnt++;
            if(cnt % n == 0) {
                if(check[temp] == 0){
                    cout << temp << endl;
                    check[temp] = 1;
                    cnt = 0;
                } else {
                    cnt--;
                }
            }
        }
    }
    if(flag) {
        cout << "Keep going...\n";
    }
    return 0;
}