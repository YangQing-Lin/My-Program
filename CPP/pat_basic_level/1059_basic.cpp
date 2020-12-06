#include<iostream>
#include<cmath>
using namespace std;

int array[10000] = {0};

int isPrime(int n) {
    if(n == 2 || n == 3) {
        return 1;
    }
    if(n < 2 || n % 2 == 0) {
        return 0;
    }
    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int check(int n) {
    if(array[n] == 0) {
        printf(": Are you kidding?\n");
    } else if (array[n] == -1) {
        printf(": Checked\n");
    } else if (array[n] == 1) {
        printf(": Mystery Award\n");
        array[n] = -1;
    } else {
        if (isPrime(array[n]) == 1) {
            printf(": Minion\n");
        } else {
            printf(": Chocolate\n");
        }
        array[n] = -1;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        array[temp] = i + 1;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        printf("%04d", temp);
        check(temp);
    }
    return 0;
}