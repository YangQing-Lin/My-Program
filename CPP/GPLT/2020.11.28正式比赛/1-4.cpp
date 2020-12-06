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
	int n;
	double sum = 0, temp;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		sum += 1.0/temp;
	}
	printf("%.2lf\n", 1.0/(sum/n));
	return 0;
}
