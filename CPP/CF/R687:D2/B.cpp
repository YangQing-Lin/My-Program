#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,n,k,color[MAXN];
int dp[MAXN][105];
int read()
{
 int sum=0;
 char c=getchar();
 while(c<'0'||c>'9')c=getchar();
 while(c>='0'&&c<='9'){
  sum=sum*10+c-'0';
  c=getchar();
 }
 return sum;
}
int main()
{
 t=read();
 while(t--){
  n=read(),k=read();
  for(int i=1;i<=n;i++)color[i]=read();
  memset(dp[0],0,sizeof(dp[0]));
  for(int i=1;i<=100;i++)dp[1][i]=(color[1]==i?0:1);
  for(int i=2;i<=k;i++)
   for(int j=1;j<=100;j++)
    dp[i][j]=min(1,dp[i-1][j]+(color[i]==j?0:1));
  for(int i=k+1;i<=n;i++)
   for(int j=1;j<=100;j++)
    dp[i][j]=min(dp[i-k][j]+1,dp[i-1][j]+(color[i]==j?0:1));
  int minn=0x3f3f3f3f;
  for(int i=1;i<=100;i++)
   minn=min(minn,dp[n][i]);
  /*for(int i=1;i<=n;i++){
   cout<<i<<":";
   for(int j=1;j<=2;j++)
    cout<<dp[i][j]<<" ";
   cout<<endl;
  }*/
  cout<<minn<<endl;
 }
} 


#include<bits/stdc++.h>
using namespace std;
int main() {
    int book[105] = {0};
    int arr[100005] = {0};
    int n, m, k, t;
    cin >> n;
    while(n--) {
        memset(book, 0, sizeof(book));
        int max_index = 0;
        cin >> m >> k;
        for(int i = 1; i <= m; i++) {
            cin >> arr[i];
            book[arr[i]]++;
            if(book[arr[i]] > book[max_index]) max_index = arr[i];
        }
        if(book[max_index] == 1)
            cout << m-1 << endl;
        else {
            int num = 0, cnt = 0;
            for(int i = 1; i <= m; i++) {
                if(arr[i] == max_index) {
                    cnt += num / k;
                    if(num % k != 0) cnt++;
                    num = 0;
                } else {
                    num++;
                }
            }
            if(num != 0) {
                cnt += num / k;
                if(num % k != 0) cnt++;
                num = 0;
            }
            printf("%d %d %d\n", cnt, max_index, num);
        }
    }
    return 0;
}
/*
3
10 2
1 1 2 2 1 1 2 2 2 1
7 1
1 2 3 4 5 6 7
10 3
1 3 3 3 3 1 2 1 3 3

1
7 3
1 2 4 3 8 9 2 3 1 2 1
*/


/*
There is a street with n houses in a line, numbered from 1 to n. The house i is initially painted in color ci. The street is considered beautiful if all houses are painted in the same color. Tom, the painter, is in charge of making the street beautiful. Tom's painting capacity is defined by an integer, let's call it k.

On one day, Tom can do the following repainting process that consists of two steps:

He chooses two integers l and r such that 1≤l≤r≤n and r−l 1=k.
For each house i such that l≤i≤r, he can either repaint it with any color he wants, or ignore it and let it keep its current color.
Note that in the same day Tom can use different colors to repaint different houses.

Tom wants to know the minimum number of days needed to repaint the street so that it becomes beautiful.

Input
The first line of input contains a single integer t (1≤t≤104), the number of test cases. Description of test cases follows.

In the first line of a test case description there are two integers n and k (1≤k≤n≤105).

The second line contains n space-separated integers. The i-th of these integers represents ci (1≤ci≤100), the color which house i is initially painted in.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
Print t lines, each with one integer: the minimum number of days Tom needs to make the street beautiful for each test case.
*/