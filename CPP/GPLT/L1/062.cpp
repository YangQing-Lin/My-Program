#include<iostream>
using namespace std;
int main() {
    string str;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str[0]+str[1]+str[2] 
        == str[str.length()-1]+str[str.length()-2]+str[str.length()-3]) {
            printf("You are lucky!\n");
        } else {
            printf("Wish you good luck.\n");
        }
    }
    return 0;
}