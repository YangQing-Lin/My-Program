#include <bits/stdc++.h>
#define int long long
#define scanf scanf_s
#define read(a) scanf("%lld",&a)
#define rep(i,x,y) for(int i=x;i<y;i++)
#define dep(i,x,y) for(int i=x;i>y;i--)
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int> 
#define out(x) cout<<x<<endl
#define fout(x) printf("%lld",x)
using namespace std;
const int maxn = 1e5 + 5;
const int inf = INT_MAX;
int cnt = 1;
int p[1000005];
void solve()
{
    int x;
    cin >> x;
    cout << p[x] << endl;
}

signed main()
{
    int t;
    cin >> t;
    int cnt = 2;
    int sum = 1;
    int flag = 1;
    for (int i = 1; i <= (int)1e6; i++)
    {
        if (i == sum)
        {
            p[i] = flag++;
            sum += cnt++;
        }
        else if (i == sum - 1)
        {
            p[i] = flag + 1;
        }
        else
        {
            p[i] = flag;
        }
    }
    while (t--)
    {
        solve();
    }
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// struct node {
//     int index, time;
// };

// int main() {
//     queue<node> q;
//     int arr[1000005];
//     int n;
//     cin >> n;
//     while(n--) {
//         while(!q.empty()) q.pop();
//         node temp = {0, 1};
//         int t;
//         cin >> t;
//         q.push(temp);
//         while(q.front().index != t) {
//             temp.time = q.front().time + 1;
//             temp.index = q.front().index + q.front().time;
//             q.push(temp);
//             temp.index = q.front().index - 1;
//             q.push(temp);
//             q.pop();
//         }
//         cout << q.front().time-1 << endl;
//     }
//     return 0;
// }