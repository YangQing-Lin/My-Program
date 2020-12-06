#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

bool isnumber(char ch) {
	if(ch >= '0' && ch <= '9') return true;
	return false;
}

bool is_good(string str) {
	for(int i = 0;  i < str.length(); i++) {
		if(!isalpha(str[i]) && !isnumber(str[i]) && str[i] != '.') {
			return false;
		}
	}
	return true;
}

bool has_number(string str) {
	for(int i = 0;  i < str.length(); i++) {
		if(isnumber(str[i])) {
			return true;
		}
	}
	return false;
}

bool has_alpha(string str) {
	for(int i = 0;  i < str.length(); i++) {
		if(isalpha(str[i])) {
			return true;
		}
	}
	return false;
}

int main() {
    int n;
    string str;
    cin >> n;
    getchar();
    while(n--) {
    	getline(cin, str);
    	if(str.length() < 6) printf("Your password is tai duan le.\n");
    	else if(!is_good(str)) printf("Your password is tai luan le.\n");
    	else if(!has_number(str)) printf("Your password needs shu zi.\n");
    	else if(!has_alpha(str)) printf("Your password needs zi mu.\n");
    	else printf("Your password is wan mei.\n");
	}
	return 0;
}