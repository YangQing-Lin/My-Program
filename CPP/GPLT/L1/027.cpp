#include<bits/stdc++.h>
using namespace std;
int main() {
    int index[10] = {0};
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++) index[str[i]-'0'] = 1;
    vector<int> arr;
    for(int i = 9; i >= 0; i--) {
        if(index[i] == 1) {
            arr.push_back(i);
        }
    }
    int ans[11] = {0};
    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] == str[i]-'0') {
                ans[i] = j;
                break;
            }
        }
    }
    printf("int[] arr = new int[]{");
    for(int i = 0; i < arr.size(); i++) {
        if(i != 0) printf(",");
        cout << arr[i];
    }
    printf("};\nint[] index = new int[]{");
    for(int i = 0; i < 11; i++) {
        if(i != 0) printf(",");
        cout << ans[i];
    }
    printf("};\n");
    return 0;
}