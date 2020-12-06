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
	int n, m, a, b, c, k, count = 0, minn = INT_MAX, index = -1, temp, sum;
	cin >> n >> m;
	vector<vector<int> > arr(n+1);
	for(int i = 0; i <= n; i++) arr[i].resize(n+1);
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a][b] = arr[b][a] = c;
	}
	cin >> k;
	for(int i = 0; i < k; i++) {
		temp = 0;
		sum = 0;
		cin >> a;
		vector<int> check(a);
		for(int j = 0; j < a; j++) {
			cin >> check[j];
		}
		if(a != n) {
			continue;
		}
		for(int j = 0; j < a; j++) {
			sum += arr[temp][check[j]];
			temp = check[j];
		}
		sum += arr[temp][0];
		if(sum < minn) {
			count = 1;
			minn = sum;
			index = i+1;
		} else if (sum == minn) {
			count++;
		}
	}
	printf("%d\n%d %d\n", count, index, minn);
	return 0;
}
