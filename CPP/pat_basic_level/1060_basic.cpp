#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int array[1000000] = {0}; // 一天骑行i英里的次数
    int n;
    int max = 0;
    int max_size = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        array[temp]++;
        if(temp > max_size) {
            max_size = temp;
        }
    }
    for(int i = max_size; i > 0; i--) {
        for(int j = 0; j < array[i]; j++) {
            if(max + 1 >= i) {
                break;
            } else {
                max++;
            }
        }
        if(max + 1 >= i) {
            break;
        }
    }
    printf("%d\n", max);
    return 0;
}