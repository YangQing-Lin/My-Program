// 思路：用线段树来维护每个区间的最小值，如果某次更新完后房间内的待更新灯泡数变为零，那么不在考虑此房间，这样每次查找符合条件的房间就只需要O(logn)的时间，还要注意如果可以要尽量从左儿子开始更新，因为题意是从左向右更新！

// 代码：

#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    int l,r,rt,v;
}a[1008611];

struct Node1 {
    int l,r;
}b[1008611];
int ans1=0,ans2,cou;

void push_up(int rt) {
    if(a[rt*2].v!=0&&a[rt*2+1].v!=0)
       a[rt].v=min(a[rt*2].v,a[rt*2+1].v);
    else if(a[rt*2].v==0&&a[rt*2+1].v!=0) {
        a[rt].v=a[rt*2+1].v;
    }
    else if(a[rt*2+1].v==0&&a[rt*2].v!=0) {
        a[rt].v=a[rt*2].v;
    }
    else if(a[rt*2+1].v==0&&a[rt*2].v==0) {
        a[rt].v=0;
    }
}

void build(int rt,int l,int r) {
    a[rt].l=l;
    a[rt].r=r;
    int m=(l+r)/2;
    if(l==r) {
        scanf("%d",&a[rt].v);
        return;
    }
    build(rt*2,l,m);
    build(rt*2+1,m+1,r);
    push_up(rt);
}

void update(int rt){
    int m=(a[rt].l+a[rt].r)/2;
    if(a[rt].l==a[rt].r) {
        ans2-=a[rt].v;
        a[rt].v=0;
        cou++;
        ans1++;
        return;
    }
    if(ans2>=a[rt].v&&a[rt].v!=0) {
        if(ans2>=a[rt*2].v&&a[rt*2].v!=0)
        update(rt*2);
        else if(ans2>=a[rt*2+1].v) {
            update(rt*2+1);
        }
        push_up(rt);
    }
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    ans2=m;
    int i,k=1;
    build(1,1,n);
    while(cou<n) {
        while(ans2>=a[1].v&&a[1].v!=0) {
            update(1);
        }
        if(ans2>=a[1].v) {
             b[k].l=ans1;
             b[k++].r=ans2;
             ans2+=m;
        }
        while(ans2<a[1].v) {
            b[k].l=ans1;
            b[k++].r=ans2;
            ans2+=m;
        }
    }
    int mm;
    scanf("%d",&mm);
    for(i=1;i<=mm;i++) {
        int t;
        scanf("%d",&t);
        if(t>=k)
            printf("%d %d\n",b[k-1].l,b[k-1].r);
        else
            printf("%d %d\n",b[t].l,b[t].r);
    }
    return 0;
}
// 线段树能做的事还是很多的，一种很强大的数据结构！似乎只要是对连续的区间进行处理都有可能用到线段树。



// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// vector<bool> book(1e8);

// int main() {
//     int n, m, k, temp;
//     set<int> arr;
//     cin >> n >> m;
//     while(n--) {
//         cin >> temp;
//         arr.insert(temp);
//     }
//     auto its = arr.begin();
//     for(auto it = arr.begin(); it != arr.end(); it++) {
//         for(its = it+1; its != arr.end(); its++) {
//             arr.insert(*it + *its);
//         }
//     }
//     for(auto it = arr.begin(); it != arr.end(); it++) {
//         printf("%d ", *it);
//     }
//     puts("");
//     return 0;
// }