#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, c, d;
    cin >> n;
    while(n--) {
        cin >> a >> b >> c >> d;
        a = max(a-c, c-1);
        b = max(b-d, d-1);
        cout << a + b << endl;
    }
    return 0;
}

/*
There is a prison that can be represented as a rectangular matrix with n rows and m columns. Therefore, there are n⋅m prison cells. There are also n⋅m prisoners, one in each prison cell. Let's denote the cell in the i-th row and the j-th column as (i,j).

There's a secret tunnel in the cell (r,c), that the prisoners will use to escape! However, to avoid the risk of getting caught, they will escape at night.

Before the night, every prisoner is in his own cell. When night comes, they can start moving to adjacent cells. Formally, in one second, a prisoner located in cell (i,j) can move to cells (i−1,j) , (i+1,j) , (i,j−1) , or (i,j+1), as long as the target cell is inside the prison. They can also choose to stay in cell (i,j).

The prisoners want to know the minimum number of seconds needed so that every prisoner can arrive to cell (r,c) if they move optimally. Note that there can be any number of prisoners in the same cell at the same time.

Input
The first line contains an integer t (1≤t≤104), the number of test cases.

Each of the next t lines contains four space-separated integers n, m, r, c (1≤r≤n≤109, 1≤c≤m≤109).

Output
Print t lines, the answers for each test case.
*/