#include<iostream>
using namespace std;
int main() {
    int month, day, year;
    scanf("%d-%d-%d\n", &month, &day, &year);
    printf("%d-%02d-%02d\n", year, month, day);
    return 0;
}