#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    double max = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        double temp1, temp2, temp3;
        cin >> temp1 >> temp2;
        temp3 = sqrt(pow(temp1, 2) + pow(temp2, 2));
        if(max < temp3) {
            max = temp3;
        }
    }
    printf("%.2lf\n", max);
    return 0;
}