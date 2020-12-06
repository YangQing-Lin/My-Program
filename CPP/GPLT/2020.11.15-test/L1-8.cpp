#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

int main() {
    int n;
    cin >> n;
    int a, h, m;
    int count, time;
    char ch, temp;
    map<int, int> book;
    while(n--) {
        book.clear();
        count = time = 0;
        while(true) {
            cin >> a >> ch >> h >> temp >> m;
            if(a == 0) {
                if(count == 0) printf("0 0\n");
                else printf("%d %d\n", count, (int)(time * 1.0 / count + 0.5));
                break;
            }
            if(ch == 'S') {
                book[a] = h * 60 + m;
            } else if (ch == 'E' && book[a] != 0) {
                count++;
                time += h * 60 + m - book[a];
                book[a] = 0;
            }
        }
    }
    return 0;
}