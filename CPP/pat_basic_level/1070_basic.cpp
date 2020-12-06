#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int cnt;
    cin >> cnt;
    vector<int> array(cnt);
    for(int i = 0; i < cnt; i++) {
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    double result = array[0];
    for(int i = 1; i < cnt; i++) {
        result = (result + (double)array[i]) / 2.0;
    }
    printf("%d\n", (int)result);
    return 0;
}