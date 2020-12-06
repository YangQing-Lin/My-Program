#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int n1,n2,m1,m2,k;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    if(n1*m2 > n2*m1) {
        swap(n1, n2);
        swap(m1, m2);
    }
    double start, end;
    end = (double)n2/m2;
    int temp = (double)n1*k/m1 + 1;
    int flag = 0;
    while((double)temp/k < end) {
        if(gcd(temp, k) == 1) {
            if(flag) cout << " ";
            printf("%d/%d", temp, k);
            flag = 1;
        }
        temp++;
    }
    return 0;
}
