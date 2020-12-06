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
	//string money[19] = {"10,000", "36", "720", "360", "80", "252", "108", "72", "54", "180", "72", "180", "119", "36", "306", "1,080", "144", "1,800", "3,600"};
	//for(int i = 0; i < 19; i++) printf("%d %d\n", i+6, money[i]);
	int money[19] = {10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};
	int arr[4][4] = {0};
	int sum = 45, x, y;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
			sum -= arr[i][j];
			if(arr[i][j] == 0) {
				x = i;y = j;
			}
		}
	}
	arr[x][y] = sum;
	for(int i = 0; i < 3; i++) {
		cin >> x >> y;
		cout << arr[x][y] << endl;
	}
	int temp;
	cin >> temp;
	sum = 0;
	for(int i = 1; i <= 3; i++) {
		if(temp <= 3) {
			sum += arr[temp][i];
		} else if (temp <= 6) {
			sum += arr[i][temp-3];
		} else if (temp == 7) {
			sum += arr[i][i];
		} else {
			sum += arr[4-i][4-i];
		}
	}
	cout << money[sum-6] << endl;
	return 0;
}
