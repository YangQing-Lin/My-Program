#include<iostream>
#include<map>
#include<vector>
#define ull unsigned long long;
using namespace std;
int main() {
    string str;
    cin >> str;
    int maxn = 0;
    vector<int> pro(str.length() + 1);
    map<int, int> check;
    for(int i = 0; i < str.length(); i++) {
        int temp = str[i] - '0';
        check[temp]++;
        if(i == 0) pro[i] = temp;
        else pro[i] = temp + pro[i-1];
        if(temp > maxn) maxn = temp;
    }
    int cnt = 0;
    if(pro[str.length()-1] % 3 == 0) {
        cout << 0 << endl;
    } else {
        int n = pro[str.length()-1] % 3;
        int temp = n;
        while(n) {
            if(check[temp] != 0) {
                n -= temp;
                cnt++;
            } else {
                temp--;
            }
        }
        if(cnt == str.length()) cout << -1 << endl;
        else cout << cnt << endl;
    }
    return 0;
}