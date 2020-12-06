#include<iostream>
using namespace std;
int main() {
    double money, size;
    cin >> money >> size;
    printf("%.2lf\n", money * size / 10);
    return 0;
}