#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a, b, c, d;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        cout << min(a+b, c+d) << endl;
    }
    return 0;
}