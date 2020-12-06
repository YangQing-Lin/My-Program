#include<bits/stdc++.h>
using namespace std;
//priority_queue<int, vector<int>, greater<int> > min_heap;
//priority_queue<int, vector<int> > max_heap;

/*
int find(x) {
	while(x != fa[x]) {
		x = fa[x] = fa[fa[x]];
	}
	return x;
}
*/

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	string temp;
	getchar();
	int sum, index;
	while(m--) {
		sum = 0;
		index = 0;
		cin >> temp;
		for(int i = 0; i < n; i++) {
			arr[i] = temp[i] == 'y' ? 0 : 1;
		}
		for(int i = n-1; i >= 0; i--, index++) {
			if(arr[i] == 1)
				sum += pow(2, index);
		}
		cout << sum+1 << endl;
	}
	return 0;
}
