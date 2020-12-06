#include<bits/stdc++.h>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

bool check(int n) {
	if(n == 2 || n == 3) return true;
	if(n <= 1 || n % 2 == 0) return false;
	for(int i = 3; i <= sqrt(n); i += 2) {
		if(n % i == 0) return false;
	}
	return true;
}

int string_to_int(string str) {
	int n = 0;
	for(int i = 0; i < str.length(); i++) {
		n = n * 10 + str[i] - '0';
	}
	return n;
}

int main() {
	int n, m, is;
	cin >> n >> m;
	getchar();
	string str, temp;
	cin >> str;
	int len = str.length();
	for(int i = 0 ; i < len - m + 1; i++) {
		temp = str.substr(i, m);
		is = string_to_int(temp);
		if(check(is)) {
			cout << temp << endl;
			return 0;
		}
	}
	cout << 404 << endl;
    return 0;
}