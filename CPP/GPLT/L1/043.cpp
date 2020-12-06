#include<iostream>
#include<map>
using namespace std;
int main() {
    int n;
    char ch;
    cin >> n;
    while(n--) {
        int cnt = 0, sum = 0;
        int a, b, c;
        char temp;
        map<int, int> book;
        map<int, bool> check;
        getchar();
        while(true) {
            cin >> a >> ch >> b >> temp >> c;
            // printf("%d %c %d:%d\n", a, ch, b, c);
            if(a == 0) {
                printf("%d %d\n", cnt, cnt == 0 ? 0 : (int)(1.0 * sum / cnt + 0.5));
                break;  
            } else {
                if (ch == 'S') {
                    book[a] = b * 60 + c;
                    check[a] = true;
                } else if (ch == 'E' && check[a] == true) {
                    cnt++;
                    sum += b * 60 + c - book[a];
                    book[a] = 0;
                    check[a] = false;
                }
            }
        }
    }   
    return 0;
}