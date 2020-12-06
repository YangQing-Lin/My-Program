#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int topic[101] = {0};
    bool answer[101] = {0};
    for(int i = 0; i < m; i++) {
        cin >> topic[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> answer[i];
    }
    for(int i = 0; i < n; i++) {
        int center = 0;
        for(int j = 0; j < m; j++) {
            bool temp;
            cin >> temp;
            if(temp == answer[j]) {
                center += topic[j];
            }
        }
        printf("%d\n", center);
    }
    return 0;
}