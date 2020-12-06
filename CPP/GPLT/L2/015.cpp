#include<bits/stdc++.h>
using namespace std;

bool cmp(double a, double b) { return a > b; }

int main() {
    int n, k, m, maxn, minn, temp, sum;
    cin >> n >> k >> m;
    vector<double> score(n);
    for(int i = 0; i < n; i++) {
        sum = maxn = 0;
        // minn初始化为int最大值（2147483647）
        minn = INT_MAX;
        for(int j = 0; j < k; j++) {
            cin >> temp;
            maxn = max(temp, maxn);
            minn = min(temp, minn);
            // 不管是不是极值都先加起来
            sum += temp;
        }
        // 减去两个极值（在线操作，不用开额外的数组把输入的数字存起来）
        sum -= minn + maxn;
        // 计算平均值
        score[i] = sum * 1.0 / (k - 2);
    }
    // 降序排序
    sort(score.begin(), score.end(), cmp);
    for(int i = m-1; i >= 0; i--) {
        // 倒序输出输出题目要求的数字即可
        printf("%.3lf", score[i]);
        if(i != 0) printf(" ");
    }
    puts("");
    return 0;
}