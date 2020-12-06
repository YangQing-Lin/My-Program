#include<iostream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
int main() {
    int n, cor;
    double sum = 0, index = 200000;
    string name;
    map<int, string> book;
    vector<int> check;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) {
        cin >> name >> cor;
        book[cor] = name;
        check.push_back(cor);
        sum += cor;
    }
    sum /= n*2;
    for(int i = 0; i < n; i++) {
        if (fabs(check[i] - sum) < index) {
            index = fabs(check[i] - sum);
            cor = check[i];
        }
    }
    cout << (int)sum << " " + book[cor] << endl;
    return 0;
}