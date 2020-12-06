#include<iostream>
#include<map>
using namespace std;

struct node{
    string name;
    string xing;
    bool sex;// true is boy, false is girl
} ;

int main() {
    int n;
    string str1, str2;
    map<string, node> book;
    node temp;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str1 >> str2;
        if (str2[str2.length()-1] == 'm' 
        || str2[str2.length()-1] == 'f') {
            temp.sex = str2[str2.length()-1] == 'm';
            str2 = str2.substr(0, str2.length()-1);
        } else if (str2[str2.length()-1] == 'n') {
            temp.sex = true;
            str2 = str2.substr(0, str2.length()-4);
        } else {
            temp.sex = false;
            str2 = str2.substr(0, str2.length()-7);
        }
        temp.name = str1;
        temp.xing = str2;
        book[str1] = temp;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name1, name2, xing1, xing2;
        cin >> name1 >> xing1 >> name2 >> xing2;
        if (book.find(name1) == book.end() || book.find(name2) == book.end()) {
            printf("NA\n");
        } else if (book[name1].sex == book[name2].sex) {
            printf("Whatever\n");
        } else {
            int j;
            map<string, bool> check;
            string temp_xing = xing1;
            for(j = 0; j < 3; j++) {
                if (book.find(temp_xing) != book.end()) {
                    check[temp_xing] = true;
                    temp_xing = book[temp_xing].xing;
                    // cout << temp_xing << endl;
                }
            }
            temp_xing = xing2;
            for(j = 0; j < 3; j++) {
                if (check[temp_xing] == true) {
                    printf("No\n");
                    break;
                }
                temp_xing = book[temp_xing].xing;
                // cout << "^"+temp_xing << endl;
            }
            if(j == 3) printf("Yes\n");
        }
    }
    return 0;
}