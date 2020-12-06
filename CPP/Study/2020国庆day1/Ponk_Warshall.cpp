#include<iostream>
#include<map>
using namespace std;
int main(){
    string str1, str2;
    int index = 0;
    char temp;
    cin >> str1 >> str2;
    for(int i = 0; i < str1.length()-1; i++) {
        if(str1[i] != str2[i]) {
            for(int j = i+1; j < str1.length(); j++) {
                if(str1[j] == str2[i] && str1[j] != str2[j]) {
                    index++;
                    temp = str1[j];
                    str1[j] = str1[i];
                    str1[i] = temp;
                    break;
                }
            }
        }
    }
    cout << index << endl;
    return 0;
}
// 部分正确