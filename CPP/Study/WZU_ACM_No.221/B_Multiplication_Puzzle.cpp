// WA
#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main(){
    int n, temp, temp_add, temp1, temp2, max_index = 0;
    int sum = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        arr[i] = temp;
    }
    for(int i = 1; i <= n-2; i++) {
        max_index = 1;
        while(arr[max_index] == 0) max_index++;
        for(int j = 1; j < n-1; j++) {
            if(arr[j] != 0) {
                if(arr[max_index] < arr[j]) {
                    max_index = j;
                } else if (max_index != j && arr[max_index] == arr[j]) {
                    int k = max_index-1, l = max_index+1;
                    while(arr[k] == 0) k--;
                    while(arr[l] == 0) l++;
                    temp1 = arr[k] * arr[l];
                    k = j-1, l = j+1;
                    while(arr[k] == 0) k--;
                    while(arr[l] == 0) l++;
                    temp2 = arr[k] * arr[l];
                    if(temp1 > temp2) {
                        max_index = j;
                    }
                }
            }
        }
        int k = max_index-1, l = max_index+1;
        while(arr[k] == 0) k--;
        while(arr[l] == 0) l++;
        temp1 = arr[k] * arr[l];
        sum += arr[max_index] * temp1;
        arr[max_index] = 0;
    }
    cout << sum << endl;
    return 0;
}