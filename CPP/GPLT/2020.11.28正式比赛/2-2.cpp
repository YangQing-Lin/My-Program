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



struct node {
	char name;
	string id;
	int check;
	int time;
	int next_day;
};

bool cmp(node a, node b) {
	return a.time < b.time;
}

int main() {
	unordered_set<string> s;
	vector<node> v;
	int n, p;
	node tmp;
	char ch;
	string tmep;
	cin >> n >> p;
	getchar();
	map<string, int> mapp;
	for(int i = 1; i <= n; i++) {
		int m, num, a, b;
		vector<node> arr;
		cin >> m >> num;
		getchar();
		for(int l = 0; l < m; l++) {
			cin >> tmp.name >> tmp.id >> tmp.check >> a >> ch >> b;
			getchar();
			tmp.time = a * 60 + b;
			if(tmp.id.length() == 18) {
				arr.push_back(tmp);
			} 
			if(tmp.check == 1 && s.find(tmp.id) == s.end() && tmp.id.length() == 18) {
				s.insert(tmp.id);
				v.push_back(tmp);
			}
		}
		int len = (int)arr.size();
		//sort(arr.begin(), arr.end(), cmp);
		for(int j = len-1; j >= 0; j--) {
			for(int k = 0; k < j; k++) {
				if(arr[k].time > arr[k+1].time) swap(arr[k], arr[k+1]);
			}
		}
		int index = 0;
		for(int j = 0; j < len; j++) {
			if(mapp[arr[j].id] <= i || mapp[arr[j].id] == 0) {
				printf("%c %s\n", arr[j].name, arr[j].id.c_str());
				//printf("#%d#\n", mapp[arr[j].id]);
				mapp[arr[j].id] = i + p + 1;
				num--;
			}
			if(num == 0) break;
		}
	}
	for(int i = 0; i < (int)v.size(); i++) {
		printf("%c %s\n", v[i].name, v[i].id.c_str());
	}
	return 0;
}
