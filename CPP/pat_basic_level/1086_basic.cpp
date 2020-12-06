#include<iostream>
#include<string>
using namespace std;
int main() {
    long n, m;
    string answer;
    cin >> n >> m;
    answer = to_string(n * m);
    bool flag = true;
    for(int i = answer.length() - 1; i >= 0; i--) {
        if(answer[i] == '0' && flag) continue;
        cout << answer[i];
        flag = false;
    }
    cout << endl;
    return 0;
}