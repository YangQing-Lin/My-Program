#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    int num = 1;
    int count = 1;
    cin >> n;
    vector<int> ans;
    while (num % n != 0) {
        ans.push_back(num / n);
        num %= n;
        num = num * 10 + 1;
        count++;
    }
    if(num != 0) ans.push_back(num / n);
    bool flag = false;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] != 0) flag = true;
        if(ans[i] == 0 && flag || ans[i] != 0) {
            cout << ans[i];
        }
    }
    printf(" %d\n", count);
    return 0;
}



// #include<iostream>
// #include<vector>
// using namespace std;
// int main() {
//     int n = 1, m, count = 1;
//     cin >> m;
//     string str = "";
//     while(n % m != 0) {
//         n = n * 10 + 1;
//         count++;
//         if (n > m) {
//             if (n / m > 10) str += n / m / 10 + '0';
//             str += n / m % 10 + '0';
//             cout << n / m << " " << n << endl;
//             n %= m;
//         }
//     }
//     if (n != 0) str += n / m + '0';
//     cout << n / m << " " << n << endl;
//     printf("%s %d\n", str.c_str(), count);
//     return 0;
// }