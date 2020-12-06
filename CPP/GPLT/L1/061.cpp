#include<iostream>
#include<cmath>
using namespace std;
int main() {
    double n, m;
    cin >> n >> m;
    double check = n/pow(m, 2);
    printf("%.1lf\n", check);
    if(check > 25) {
        printf("PANG\n");
    } else {
        printf("Hai Xing\n");
    }
    return 0;
}