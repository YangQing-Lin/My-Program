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
	double a, b;
	int check;
	double c;
	cin >> a >> check >> b;
	c = check == 0 ? 2.455 : 1.26;
	printf("%.2lf ", a * c);
	if(a * c <= b) {
		printf("^_^\n");
	} else {
		printf("T_T\n");
	}
	return 0;
}
