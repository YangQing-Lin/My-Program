#include<iostream>
using namespace std;

int find_index(string str) {
    int index = 0, i;
    for(i = str.length()-1; i >= 0; i--) {
        if(str[i] == ' ') {
            index++;
            if(index == 3) break;
        }
    }
    // printf("^%d^\n", index);
    return i+1;
}

string exchange(string str) {
    int index = find_index(str);
    return str.substr(0, index) + "qiao ben zhong.";
}

bool is_good(string str) {
    bool flag1 = false;
    bool flag2 = false;
    if(str.length() <= 8) return false;
    if(str.substr(str.length() - 4, 3) == "ong") {
        flag1 = true;
    }
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ',' && str.substr(i - 3, 3) == "ong") {
            flag2 = true;
            break;
        }
    }
    // if(flag1) printf("<11>\n");
    // if(flag2) printf("<22>\n");
    return flag1 & flag2;
}

int main() {
    int n;
    string str;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) {
        getline(cin, str);
        // cout << str << endl;
        if(!is_good(str)) {
            printf("Skipped\n");
        } else {
            cout << exchange(str) << endl;
        }
    }
    return 0;
}