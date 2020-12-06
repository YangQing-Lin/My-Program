#include<iostream>
using namespace std;
int main() {
    int n;
    int sex, high, weight;
    int h, w;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> sex >> high >> weight;
        if(sex == 1) {
            h = 130;
            w = 27;
        } else {
            h = 129;
            w = 25;
        }
        if(high < h) printf("duo chi yu! ");
        else if(high > h) printf("ni li hai! ");
        else printf("wan mei! ");
        if(weight < w) printf("duo chi rou!\n");
        else if(weight > w) printf("shao chi rou!\n");
        else printf("wan mei!\n");
    }
    return 0;
}