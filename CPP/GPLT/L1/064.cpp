#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    getchar();
    string str;
    for(int i = 0; i < n; i++) {
        getline(cin, str);
        cout << str << endl;
        vector<string> arr;
        string temp_str = "";
        // 将整句话按空格拆分成单词
        for(int j = 0; j < str.size(); j++) {
            if(str[j] == ' ' && temp_str != "") {
                arr.push_back(temp_str);
                temp_str = "";
            }
            else if(str[j] != ' ') {
                if(str[j]==',' || str[j]=='\'') {
                    if(temp_str != "") arr.push_back(temp_str);
                    if(str[j]==',')
                        arr.push_back(",");
                    else
                        arr.push_back("\'");
                    temp_str = "";
                }
                else {
                    char temp_char = str[j];
                    // temp_char != '?' && temp_char != '!'
                    if(isalpha(temp_char) && temp_char != 'I') {
                        temp_char = tolower(temp_char);
                    } 
                    else if (temp_char == '?') temp_char = '!';
                    temp_str += temp_char;
                }
            }
        }
        if(temp_str != "") arr.push_back(temp_str);

        // for(int j = 0; j < arr.size(); j++) {
        //     if(arr[j] == "I") cout << "you" << endl;
        // }
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] == "I" || arr[j] == "me") {
                arr[j] = "you";
            }
            else if(j < arr.size()-1 
            && (arr[j] == "can" || arr[j] == "could") 
            && arr[j+1] == "you") {
                arr[j+1] = arr[j];
                arr[j] = "I";
            }
        }
        printf("AI: ");
        for(int j = 0;  j < arr.size(); j++) {
            if(j != 0
            && arr[j] != ","
            && arr[j-1] != ","
            && arr[j] != "\'"
            && arr[j-1] != "\'"
            && arr[j] != "!"
            && arr[j] != ".") printf(" ");
            cout << arr[j];
        }
        cout << endl;
    }
    return 0;
}