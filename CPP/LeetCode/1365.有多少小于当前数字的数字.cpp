#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums = {5,0,10,0,10,6};
    vector<int> check(105);
    for(int i = 0; i < nums.size(); ++i) {
        ++check[nums[i]];
    }
    for(int i = 1; i < 104; i++) {
        check[i] += check[i-1];
    }
    vector<int> answer;
    for(int i = 0; i < nums.size(); i++) {
        answer.push_back(check[nums[i]-1]);
    }
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return 0;
}