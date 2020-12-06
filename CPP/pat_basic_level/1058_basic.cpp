#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

struct stu{
	int fraction;//满分值
	int number;//选项个数
	string answer;//正确个数和所有正确选项 
	int wron;
};

int main(){
	int n;//学生人数
    int cnt;//多选题个数
    int students[1001] = {0}, max_faction = 0;
	cin >> n >> cnt;
	stu topic[cnt + 1];//给每道题申请空间
	string temp;
	for(int i = 1; i <= cnt; i++){
		getline(cin, temp);
        while(temp.length() < 4){
    		getline(cin, temp);
        }
		topic[i].fraction = temp[0] - '0';
		topic[i].number = temp[2] - '0';
        topic[i].answer = temp.substr(4);
		topic[i].wron = 0;
	}
	for(int i = 1; i <= n; i++){
		getline(cin, temp);
		int position = 0;//当前位置 
		for(int j = 0; j < temp.length(); j++){
			if(temp[j] == '(') {
                position++;
                if (topic[position].answer == temp.substr(j+1, topic[position].answer.length())) {
                    students[i] += topic[position].fraction;
                } else {
                    topic[position].wron++;
                    max_faction = max_faction < topic[position].wron ? topic[position].wron : max_faction;
                }
            }
		}
	}
	for(int i = 1; i <= n; i++) {
        printf("%d\n", students[i]);
    }
	if(max_faction != 0){
        int max_faction_index = 0;
        printf("%d", max_faction);
        for(int i = 1; i <= cnt; i++) {
            if(topic[i].wron == max_faction) {
                printf(" %d", i);
            }
        }
	} else {
        printf("Too simple");
    }
	return 0;
}
/*
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
*/
