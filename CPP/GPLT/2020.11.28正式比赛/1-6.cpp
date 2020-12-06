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
	string check = "chi1 huo3 guo1";
	string ERROR = "-_-#\n";
	int count = -1, index = 0, cnt = 0;
	string temp, temp1;
	do {
		getline(cin, temp);	
		count++;
		if(temp.length() >= 14) {
			for(int i = 0; i <= temp.length() - 14; i++) {
				temp1 = temp.substr(i, 14);
				if(temp1 == check) {
					cnt++;
					if(index == 0) index = count+1;
					//printf("#%d %d#\n", index, cnt);
					break;
				}
			}
		}
	} while(temp != ".");
	printf("%d\n", count);
	if(index == 0) printf("%s", ERROR.c_str());
	else {
		printf("%d %d\n", index, cnt);
	}
	return 0;
}
