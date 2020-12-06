#include<bits/stdc++.h>
using namespace std;

int string2(int k, string s) {
        vector<int> arr(s.length());
        for(int i = 0; i < s.length(); i++) {
            arr[i] = s[i] - 'a';
        }
        int maxn = INT_MIN;
        for(int i = 0; i < 26; i++) {
            int sum = 0, cnt = 0;
            set<int> ans;
            for(int j = 0; j < arr.size(); j++) {
                ans.insert(fabs(arr[j] - i));
            }
            for(auto it = ans.begin(); it != ans.end(); it++) {
                sum += *it;
                if(sum > k) break;
                cnt++;
            }
            maxn = max(maxn, cnt);
            cout << maxn << endl;
        }
        return maxn;
    }

int main() {
    cout << string2(2, "abcde") << endl;
    // for(int i = 0; i < 26; i++) {
    //     printf("%c %d\n", 'a' + i, i);
    // }


    // string str = "acesxd";
    // int arr[6] = {0, 2, 4, 18, 23, 3};
    // int maxn = INT_MIN;
    // int n = 10;
    // for(int i = 0; i < 26; i++) {
    //     int sum = 0, cnt = 0;
    //     set<int> ans;
    //     for(int j = 0; j < 6; j++) {
    //         ans.insert(fabs(arr[j] - i));
    //     }
    //     for(auto it = ans.begin(); it != ans.end(); it++) {
    //         sum += *it;
    //         if(sum > n) break;
    //         cnt++;
    //     }
    //     maxn = max(maxn, cnt);
    // }
    // cout << maxn << endl;
    return 0;
}