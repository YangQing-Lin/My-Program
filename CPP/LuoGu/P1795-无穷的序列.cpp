#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
int main() {
    // map<int, bool> book;
    vector<int> book;
    // unordered_set<int> book;
    int sum = 1;
    book.push_back(sum);
    for(int i = 1; sum <= 1e9; i++) {
        sum += i;
        book.push_back(sum);
    }
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &sum);
        bool check = binary_search(book.begin(), book.end(), sum);
        if(check) printf("1\n");
        else printf("0\n");
        // if(book.find(sum) != book.end()) printf("1\n");
        // else printf("0\n");
    }
    return 0;
}