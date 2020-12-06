#include <iostream>
using namespace std;
#define ll long long
ll M=9999999967;
ll  mul(ll  a, ll b,ll  p) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        a = (a + a) % p;
        b = b >> 1;
    }
    return ans;
}
ll fast_pow_mod(ll base, ll power) {
    ll result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = mul(result,base,M)%M;
        }
        power >>= 1;//此处等价于power=power/2
        base = mul(base,base,M)%M;
    }
    return result;
}
 
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll a;
        ll b;
        cin>>a>>b;
        ll ans;
        ans=fast_pow_mod(a,b);
        cout<<ans<<endl;
 
    }
    system("pause");
    return 0;
}