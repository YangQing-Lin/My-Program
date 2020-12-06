#include <iostream>
using namespace std;
int main() {
    string passwd;
    int cnt;
    string temp;
    cin >> passwd >> cnt;
    getchar();
    for(int i = 0; i < cnt; i++) {
        getline(cin, temp);
        if(temp == passwd) {
            printf("Welcome in\n");
            break;
        } else if (temp == "#") {
            break;
        } else {
            cout << "Wrong password: " << temp << endl;
            if(i == cnt - 1) {
                cout << "Account locked\n";
                break;
            }
        }
    }
    return 0;
}