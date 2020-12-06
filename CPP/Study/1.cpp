// 毒瘤题
#include<iostream>
#include<bitset>
using namespace std;
bitset<100000000> arr;
int main() {
	int n, k, temp;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if(arr.test(temp)) {
            arr.reset(temp);
        } else {
            arr.set(temp);
        }
	}
	for(int i = 0; i < 100000000; i++) {
		if(arr.test(i)) {
			cout << i;
			if(k == 2) cout << " ";
			k--;
		}
		if(k == 0) break;
	}
    cout << endl;
	return 0;
}