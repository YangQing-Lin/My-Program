/*学长的代码：*/
#include<bits/stdc++.h>
#define pb push_back
#define ef(i,u) for(int i=b[u];i;i=nxt[i])
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,b,a) for(int i=b;i>=a;--i)
#define gcd(a,b) __gcd(a,b)
#define MEM(a,x) memset(a,x,sizeof(a))
#define VI vector<int>
#define PII pair<int,int>
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e6+5;
struct node{
    int d,v;
}b[N];
int n,m,a[N];
bool cmp(node x,node y){
    return y.v<x.v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    rep(i,1,m)cin>>b[i].d;
    rep(i,1,m)cin>>b[i].v;
    sort(a+1,a+1+n,greater<int>());
    sort(b+1,b+1+m,cmp);
    int now=1;
    int ans=0;
    rep(i,1,n){
        while(b[now].d>=a[i]&&now<=m)now++;
        if(a[i]>b[now].d&&now<=m&&b[now].v>0)ans+=b[now].v;
    }
    cout<<ans<<'\n';
	return 0;
}


/*我的代码：*/
// #include<bits/stdc++.h>
// using namespace std;

// struct node {
//     int hp, value;
// };

// bool cmp(node a, node b) {
//     if (a.value != b.value) return a.value > b.value;
//     return a.hp < b.hp;
// }

// inline int read() {
//     int x = 0, w = 1;
//     char c = getchar();
//     while (c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
//     while (c >= '0' && c <= '9') 
//         x = (x << 3) + (x << 1) + c - '0', c = getchar();
//     return x * w;
// }

// int main() {
//     int n, m;
//     // cin >> n >> m;
//     scanf("%d %d", &n, &m);
//     vector<int> plane(n);
//     vector<node> country(m);
//     for(int i = 0; i < n; i++) {
//         plane[i] = read();
//     }
//     for(int i = 0;  i < m; i++) {
//         country[i].hp = read();
//     }
//     for(int i = 0;  i < m; i++) {
//         country[i].value = read();
//         if(country[i].value < 0) country[i].value = 0;
//     }
//     sort(country.begin(), country.end(), cmp);
//     int sum = 0, j;
//     for(int i = 0; i < n; i++) {
//         for(j = 0; j < m; j++) {
//             if(plane[i] > country[j].hp && country[j].value > 0) {
//                 sum += country[j].value;
//                 break;
//             }
//         }
//     }
//     printf("%d\n", sum);
//     return 0;
// }