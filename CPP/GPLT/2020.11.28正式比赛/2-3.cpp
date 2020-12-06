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

int index, len;

void up() {
	if((index + 1) * 2 <= len) {
		index = (index + 1) * 2;
	} else {
		return;
	}
}

int main() {
	cin >> len;
	vector<int> v(len+1);
	for(int i = 1; i <= len; i++) {
		cin >> v[i];
	}
	index = len;
	while(index != 1) {
		printf(" %d", arr[index]);
		if(index % 2 == 0) {
			if(index + 1 <= len) {
				printf(" %d", arr[index]);
			}
			index /= 2;
		}
		if(index % 2 == 1) {
			up();
		}
	}
	return 0;
}
