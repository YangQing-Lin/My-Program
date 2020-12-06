#include<iostream>
#include<string>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string str1;
    getchar();
    cin >> str1;
    string str2(str1.rbegin(), str1.rend());
    //cout << str1 << " " << str2<< endl;
    int i = 0;
    bool flag = false;
    for(i = 0; i < str1.length()-1; i++) {
        flag = true;
        for(int j = i; j < n; j++) {
            if(str1[j] != str2[j-i]) {
                flag = false;
                break;
            }
        }
        if(flag == true) {
            printf("%d\n", i);
            break;
        }
    }
    if(i == str1.length()-1) {
        cout << i << endl;
    }
    return 0;
}