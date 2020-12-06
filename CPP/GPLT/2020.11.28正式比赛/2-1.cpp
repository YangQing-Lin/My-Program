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
	int n, n1, n2;
	char op;
	stack<int> number;
	stack<char> oop;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> n1;
		number.push(n1);
	}
	for(int i = 0; i < n-1; i++) {
		cin >> op;
		oop.push(op);
	}
	while(!oop.empty()) {
		n1 = number.top();
		number.pop();
		n2 = number.top();
		number.pop();
		op = oop.top();
		oop.pop();
		switch (op) {
			case '+' :
				n1 = n2 + n1;
				break;
			case '-' :
				n1 = n2 - n1;
				break;
			case '*' :
				n1 *= n2;
				break;
		}
		if(op == '/') {
			if(n1 == 0) {
				printf("ERROR: %d/0\n", n2);
				return 0;
			} else {
				n1 = n2 / n1;
			}
		}
		number.push(n1);
		//printf("#");
	}
	cout << number.top() << endl;
	return 0;
}
