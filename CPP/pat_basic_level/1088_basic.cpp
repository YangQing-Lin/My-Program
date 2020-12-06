#include<iostream>
#include<cmath>
using namespace std;

void my_print(int n) {
    cout << " ";
    if(n == 0)
        cout << "Ping";
    else if(n > 0)
        cout << "Gai";
    else
        cout << "Cong";
}

int main(){
    int y, x, m, a, b, c, i = 0;
    cin >> m >> x >> y;
    if(y - x == 0 || y == 0 || x == 0) { // 其实判断y-x==0就够了，但我决定还是把所有情况都写出来
        cout  << "No Solution\n";
        return 0;
    }
    for(i = 99; i > 9; i--) {
        if((y*i) % (x+y) != 0 && (y*i) % (y-x) != 0){
            continue;
        }
        if((y*i / (x+y) == i%10*10 + i/10) || (y*i / (y-x) == i%10*10 + i/10)) {
            a = i;
            b = i%10*10 + i/10;
            c = b / y;
            break;
        }
    }
    if(i > 9) {
        cout << a;
        my_print(m - a);
        my_print(m - b);
        my_print(m - c);
        cout << endl;
    } else {
        cout << "No Solution\n";
    }
    return 0;
}