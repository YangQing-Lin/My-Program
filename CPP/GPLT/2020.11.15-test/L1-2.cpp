#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int> > max_heap;

int main() {
    double a, b;
    cin >> a >> b;
    printf("%.2lf\n", a * b / 10);
    return 0;
}