#include<iostream>
using namespace std;
int main() {
    int n, m, count = 0, temp;
    cin >> n >> m;
    for(int i = 0; i < 3; i++) {
        cin >> temp;
        if(temp == 0) count++;
    }
    bool flag = false;
    if((n > m && count > 0) || (n < m && count == 3)) {
        printf("The winner is a: %d + %d\n", n, count);
    } else {
        printf("The winner is b: %d + %d\n", m, 3 - count);
    }
    return 0;
}