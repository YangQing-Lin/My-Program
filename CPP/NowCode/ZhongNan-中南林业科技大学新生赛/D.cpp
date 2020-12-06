#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+7
#define ll long long

ll fast(ll b, ll p, ll k) {
	ll ans = 1;
	while(p) {
		if(p & 1) {
			ans = ans * b % k; // 累乘，快 
		}
		b = b * b % k;
		p >>= 1; // 位运算，快 
	}
	return ans - 1;
}

ll my_pow(ll m) {
    ll sum = 1;
    for(int i = 0; i < m; i++) {
        sum *= 2;
        if(sum > inf) sum %= (int)inf;
    }
    return sum - 1;
}

int main() {
    int n;
    cin >> n;
    // cout << my_pow(n) << endl;
    cout << fast(2, n, (ll)inf)%(ll)inf << endl;
    return 0;
}







// #include <iostream>
// using namespace std;

// void Towers(int n,char a,char b,char c){
// 	if(n==1){
// 		cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<endl;
// 	}
// 	else{
// 		Towers(n-1,a,c,b);
// 		cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<endl;
// 		Towers(n-1,b,a,c);
	
		
// 	}
// }
// int main(int argc, char *argv[]) {
// 	int n;
// 	cin>>n;
// 	Towers(n,'A','B','C');
// 	cout<< endl;
	
	
// }