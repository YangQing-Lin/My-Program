/*
还是有点问题
但是马上CF开始了
这个留到以后吧

题干：
链接：https://ac.nowcoder.com/acm/contest/9715/B
来源：牛客网

题目描述 
给出一个仅包含小写字母的字符串s，你最多可以操作k次，使得任意一个小写字母变为与其相邻的小写字母（ASCII码差值的绝对值为1），请你求出可能的最长相等子序列（即求这个字符串修改至多k次后的的一个最长子序列，且需要保证这个子序列中每个字母相等）。
子序列：从原字符串中取任意多个字母按照先后顺序构成的新的字符串。
*/
#include<bits/stdc++.h>
using namespace std;

int string2(int k, string s) {
        vector<int> arr(s.length());
        for(int i = 0; i < s.length(); i++) {
            arr[i] = s[i] - 'a';
        }
        int maxn = INT_MIN;
        for(int i = 0; i < 26; i++) {
            int sum = 0, cnt = 1;
            set<int> ans;
            for(int j = 0; j < arr.size(); j++) {
                ans.insert(fabs(arr[j] - i));
            }
            for(auto it = ans.begin(); it != ans.end(); it++) {
                sum += *it;
                if(sum > k) break;
                cnt++;
            }
            // cout << cnt << endl;
            maxn = max(maxn, cnt);
            // cout << maxn << endl;
        }
        return maxn;
    }

int main() {
    cout << string2(2, "abcde") << endl;
    // cout << string2(10, "acesxd") << endl;
    return 0;
}