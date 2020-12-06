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
	int arr[5];
	int minn, temp;
	cin >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> minn >> temp;
	int count = 0, maxn = 0, index = 0, cnt = 0;
	for(int i = 1; i <= 4; i++) maxn = max(maxn, arr[i]);
	for(int i = 1; i <= 4; i++) {
		if(maxn - arr[i] > temp) {
			count++;
			index = i;
		}
		if(arr[i] < minn) {
			cnt++;
			index = i;
		}
	}
	if(count >= 2 || cnt >= 2) {
		printf("Warning: please check all the tires!\n");
	} else if(count != 0 || cnt != 0) {
		printf("Warning: please check #%d!\n", index);
	} else {
		printf("Normal\n");
	}
	return 0;
}
