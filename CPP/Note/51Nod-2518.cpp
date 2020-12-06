/*
前缀和例题：和为S（51Nod-2518）
链接：https://blog.csdn.net/u011815404/article/details/97683443
代码看不懂，我以为要用O(n^2)的搜索
但是博主用了一个map就把复杂度降到O(n)
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
const int N = 40000+5;
using namespace std;
 
int a[N];
int sum[N];
map<int,int> mp;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        sum[i]=a[i]+sum[i-1];
    }
    //********自己加的
    for(int i=1; i<=n; i++){
        printf("%d ", sum[i]);
    }
    puts("");
    for(int i=1; i<=n; i++){
        printf("%d ", sum[i] - 3);
    }
    puts("");
    //************

    int k;
    scanf("%d",&k);
    int cnt=0;
    for(int i=1; i<=n; i++) {
        if(sum[i]==k)
            cnt++;
 
        cnt+=mp[sum[i]-k];
        //**********
        printf("^%d %d %d^\n", mp[sum[i]-k], sum[i]-k, sum[i]);
        //**********
        mp[sum[i]]++;
    }
    printf("%d\n",cnt);
    return 0;
}