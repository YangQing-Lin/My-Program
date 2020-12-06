#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d, temp;
    cin >> a >> b;
    vector<vector<int> > arr1(a);
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cin >> temp;
            arr1[i].push_back(temp);
        }
    }
    cin >> c >> d;
    vector<vector<int> > arr2(c);
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < d; j++) {
            cin >> temp;
            arr2[i].push_back(temp);
        }
    }
    if(b != c) {
        printf("Error: %d != %d\n", b, c);
        return 0;
    }
    printf("%d %d\n", a, d);
    // vector<vector<int> > arr3(a);
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < d; j++) {
            temp = 0;
            for(int k = 0; k < b; k++) {
                temp += arr1[i][k] * arr2[k][j];
            }
            // arr3[i].push_back(temp);
            if(j != 0) cout << " ";
            cout << temp;
        }
        puts("");
    }
    return 0;
}