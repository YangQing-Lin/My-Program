#include <iostream>
using namespace std;
int main() {
    int n;
    int map[100000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp_1, temp_2;
        cin >> temp_1 >> temp_2;
        map[temp_2] = temp_1;
        map[temp_1] = temp_2;
    }
    cin >> n;
    int array[100001] = {0};
    for(int i = 0; i < 100001; i++) {
        array[i] = -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(array[map[temp]] == 1) {
            array[map[temp]] = -1;
            sum--;
        } else if(array[map[temp]] == -1) {
            array[temp] = 1;
            sum++;
        }
    }
    bool flag = false;
    printf("%d\n", sum);
    for(int i = 0; i < 100001; i++) {
        if(array[i] == 1) {
            if(flag) {
                cout << " ";
            }
            printf("%05d", i);
            flag = true;
        }
    }
    return 0;
}