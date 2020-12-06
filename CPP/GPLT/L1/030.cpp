#include<bits/stdc++.h>
using namespace std;

struct node {
    bool sex;
    string name;
};

int main() {
    int n, check;
    cin >> n;
    node temp;
    vector<node> arr;
    getchar();
    for(int i = 0; i < n; i++) {
        cin >> check >> temp.name;
        temp.sex = check == 1;
        arr.push_back(temp);
    }
    for(int i = 0; i < n/2; i++) {
        auto it = arr.end() - 1;
        while((*it).sex == arr[i].sex) it--;
        printf("%s %s\n", arr[i].name.c_str(), (*it).name.c_str());
        arr.erase(it);
    }
    return 0;
}