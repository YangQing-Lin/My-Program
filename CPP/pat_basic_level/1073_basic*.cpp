#include<iostream>
#include<map>
using namespace std;

struct title {
    int code; // 满分值
    int choice_number; // 选项个数
    int true_choice_number; // 正确选项个数
    map<char, bool> true_choice; // 正确选项
    map<char, int> false_choice; // 选中的错误选项和选错次数
};

struct stu {
    int code; // 得分数
    int 
};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    struct title this_title[m];
    string temp;
    getchar();
    for(int i = 0; i < m; i++) {
        getline(cin, temp);
        this_title[i].code = temp[0] - '0';
        this_title[i].choice_number = temp[2] - '0';
        this_title[i].true_choice_number = temp[4] - '0';
        for(int j = 1; j < this_title[i].true_choice_number * 2; j += 2) {
            this_title[i].true_choice[temp[4 + j]] = true;
        }
    }
    map<int, double> student[n];
    int max_cont_false_choice = 0;
    for(int i = 0; i < n; i++) {
        getline(cin, temp);
        int this_address = 1;
        int choice_number = temp[1] - '0';
        for(int j = 0; j < 4; j++) {
            int k;
            for(k = 0; k < choice_number; k++) {
                this_address += 2;
                if(!this_title[j].true_choice[temp[this_address]]) {
                    break;
                }
            }
            if(k >= choice_number) {
            }
        }
    }
    return 0;
}