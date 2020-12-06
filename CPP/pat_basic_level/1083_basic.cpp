#include<iostream>
#include<map>
#include<cmath>
using namespace std;
int main() {
    int n;
    map<int, int> cards;
    cin >> n;
    int temp;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        cards[abs(temp - i)]++;
    }
    for(int i = n; i >= 0; i--) {
        if(cards[i] > 1) {
            printf("%d %d\n", i, cards[i]);
        }
    }
    return 0;
}