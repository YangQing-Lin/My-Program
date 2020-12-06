#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
struct student{
    string name;
    int p;
    int mid_term = -1;
    int final = -1;
    int g;
} stu[30001];
int main(){
    int p, m, n;
    int address = 1;
    cin >> p >> m >> n;
    map<string, int> check;
    getchar();
    for(int i = 1; i <= p+m+n; i++) {
        string temp;
        if (i <= p) {
            cin >> temp;
            check[temp] = address;
            stu[address].name = temp;
            cin >> stu[address].p;
            address++;
        } else if (i <= p+m) {
            cin >> temp;
            if(check[temp] != 0) {
                cin >> stu[check[temp]].mid_term;
            } else {
                check[temp] = address;
                stu[address].name = temp;
                cin >> stu[address].mid_term;
                address++;
            }
        } else {
            cin >> temp;
            if(check[temp] != 0) {
                cin >> stu[check[temp]].final;
            } else {
                check[temp] = address;
                stu[address].name = temp;
                cin >> stu[address].final;
                address++;
            }
        }
    }
    for(int i = 1; i < address; i++) {
        if(stu[i].p >= 200) {
            if(stu[i].mid_term > stu[i].final) {
                stu[i].g = (double)stu[i].mid_term*0.4 + (double)stu[i].final*0.6 + 0.5;
            } else {
                stu[i].g = stu[i].final;
            }
        }
    }
    while (true) {
        int flag = 1;
        for(int i = 1; i < address; i++) {
            if(stu[i].g > stu[flag].g) {
                flag = i;
            } else if (stu[i].g == stu[flag].g) {
                if(stu[i].name < stu[flag].name) {
                    flag = i;
                }
            }
        }
        if(stu[flag].g >= 60) {
            cout << stu[flag].name + ' ' << stu[flag].p << ' ' << stu[flag].mid_term << ' ' << stu[flag].final << ' ' << stu[flag].g << endl;
            stu[flag].g = -1;
        } else {
            break;
        }
    }
    return 0;
}