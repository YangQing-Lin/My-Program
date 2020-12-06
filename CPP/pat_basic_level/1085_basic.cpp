#include<iostream>
#include<map>
#include<cctype>
using namespace std;
struct stu{
    string school;
    double fraction = 0.0;
    int student_number = 0;
    bool has_checked = false;
} ranking_list[100000];

void my_print(int cnt, int address);

int main() {
    int address = 0;
    int n;
    map<int, bool> check_id;
    cin >> n;
    int school_number = n;
    getchar();
    for(int i = 0; i < n; i++) {
        int id;
        double temp_fraction;
        string school_name;
        char value = getchar();
        cin >> id >> temp_fraction;
        getchar();
        cin >> school_name;
        for(int j = 0; j < school_name.length(); j++) {
            school_name[j] = tolower(school_name[j]);
        }
        getchar();
        if(value == 'B') temp_fraction /= 1.5;
        else if (value == 'T') temp_fraction *= 1.5;
        int j;
        for(j = 0; j < address; j++) {
            if(ranking_list[j].school == school_name) {
                school_number--;
                break;
            }
        }
        if(j == address) {
            address++;
            ranking_list[j].school = school_name;
            if(!check_id[id]) {
                check_id[id] = true;
            }
        }
        ranking_list[j].fraction += temp_fraction;
        ranking_list[j].student_number++;
        /**/
    }
    cout << school_number << endl;
    int last_fraction = 0;
    int cnt = 1;
    for (int i = 0; i < address; i++) {
        //my_print(i+1, i);
        int max_fraction_address;
        for (int j = 0; j < address; j++) {
            if (!ranking_list[j].has_checked) {
                max_fraction_address = j;
                break;
            }
        }
        for (int j = max_fraction_address + 1; j < address; j++) {
            if (!ranking_list[j].has_checked && ranking_list[j].fraction == ranking_list[max_fraction_address].fraction) {
                if (ranking_list[j].student_number == ranking_list[max_fraction_address].student_number) {
                    if (ranking_list[j].school < ranking_list[max_fraction_address].school) {
                        max_fraction_address = j;
                    }
                } else if (ranking_list[j].student_number < ranking_list[max_fraction_address].student_number) {
                    max_fraction_address = j;
                }
            } else if (!ranking_list[j].has_checked && ranking_list[j].fraction > ranking_list[max_fraction_address].fraction) {
                max_fraction_address = j;
            }
        }
        if (last_fraction != (int)ranking_list[max_fraction_address].fraction) cnt = i + 1;
        last_fraction = ranking_list[max_fraction_address].fraction;
        my_print(cnt, max_fraction_address);
    }
    return 0;
}

void my_print(int cnt, int address) {
    printf("%d ", cnt);
    cout << ranking_list[address].school;
    printf(" %d %d\n", (int)ranking_list[address].fraction, ranking_list[address].student_number);
    ranking_list[address].has_checked = true;
}