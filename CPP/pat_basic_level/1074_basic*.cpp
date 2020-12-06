#include<iostream>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
int main() {
    int flag[21];
    string temp;
    cin >> temp;
    for(int i = temp.length() - 1; i >= 0; i--) {
        flag[temp.length() - i] = (temp[i] - '0') == 0 ? 10 : temp[i] - '0';
    }
    int number_1, number_2;
    cin >> number_1 >> number_2;
    vector<int> sum_number(1);
    while(number_1) {
        sum_number.push_back(number_1 % 10);
        number_1 /= 10;
    }
    int address = 1;
    while(number_2) {
        if(address < sum_number.size()) {
            sum_number[address] += number_2 % 10;
        } else {
            sum_number.push_back(number_2 % 10);
        }
        number_2 /= 10;
        address++;
    }
    stack<int> answer;
    sum_number.push_back(0);
    for(int i = 1; i < sum_number.size(); i++) {
        if(i <= 20) {
            answer.push(sum_number[i] % flag[i]);
            sum_number[i + 1] += sum_number[i] / flag[i];
        } else {
            answer.push(sum_number[i] % 10);
            sum_number[i + 1] += sum_number[i] / 10;
        }
    }
    while(answer.top() == 0) {
        answer.pop();
    }
    while(answer.size() != 0) {
        cout << answer.top();
        answer.pop();
    }
    return 0;
}