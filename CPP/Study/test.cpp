#include<iostream>
using namespace std;
int main() {
	char ch;
	while(ch = getchar(), ch != '\n') {cout << ch << endl;};
	return 0;
}



// #include<iostream>
// #include<map>
// using namespace std;
// int main() {
// 	map<string, int> m{{"a", 1}, {"b", 2}, {"c", 3}};
// 	for(auto p : m) {
// 		cout << p.first << ":" << p.second << endl;
// 	}
// 	return 0;
// }


// #include<iostream>
// using namespace std;
// int main() {
// 	double a = 5.5, b = 2.5;
// 	cout << (int)a + b/b << endl;
// 	cout << 5 + 1.0000 << endl;
// 	cout << 5 + 1.500 << endl;
// 	return 0;
// }


// #include<iostream>
// #include<vector>
// #include<set>
// using namespace std;
// int main() {
// 	vector<int> A = {4,2,5,7};
// 	for(int i = 0; i < A.size(); i += 2) {
// 		int j = 1;
// 		if((A[i] & 1) == 1) {
// 			printf("i = %d\n", i);
// 			for(; j < A.size(); j += 2) {
// 				if((A[j] & 1) == 0) {
// 					printf("j = %d\n", j);
// 					swap(A[i], A[j]);
// 					break;
// 				}
// 			}
// 		}
// 	}
// 	return 0;
// }