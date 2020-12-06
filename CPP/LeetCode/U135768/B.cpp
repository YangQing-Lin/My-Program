#include<bits/stdc++.h>
using namespace std;
#define inf 1000000007
int main() {
    set<string> check;
    string str, temp_str;
    cin >> str;
    int sum = 0;
    for(int i = 0;  i < str.length(); i++) {
        for(int j = 1; j <= str.length() - i; j++) {
            check.clear();
            temp_str = str.substr(i, j);
            for(int k = 0; k < temp_str.length(); k++) {
                for(int l = 1; l <= temp_str.length() - k; l++) {
                    check.insert(temp_str.substr(k, l));
                    //cout << temp_str.substr(k, l) << endl;
                }
            }
            sum += check.size() % inf;
            sum %= inf;
            //cout << check.size() << endl;
        }
    }
    cout << sum << endl;
    return 0;
}