#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int resolve(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    int array[361] = {0};
    int max = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        array[resolve(temp)]++;
        if(array[resolve(temp)] == 1) {
            max++;
        }
    }
    printf("%d\n", max);
    bool flag = false;
    for(int i = 0; i < 361; i++) {
        if(array[i] > 0) {
            if(flag) {
                cout << " ";
            }
            cout << i;
            flag = true;
        }
    }
    return 0;
}