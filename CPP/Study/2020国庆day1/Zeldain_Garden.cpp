#include<iostream>
#include<set>
using namespace std;
int main(){
    set<long long> check;
    long long index = 0;
    long long n, m;
    cin >> n >> m;
    for(long long i = n; i <= m; i++) {
        for(long long j = 1; j <= i/2; j++) {
            if(i % j == 0) {
                index++;
            }
        }
        index++;
    }
    cout << index << endl;
    return 0;
}