#include<iostream>
#include<stack>
#include<string>
using namespace std;

double lastList_answer(){
    stack<double> test;
    char ch = getchar();
    double number = 0;
    while(ch != '\n'){
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            double number1, number2;
            number2 = test.top();
            test.pop();
            number1 = test.top();
            test.pop();
            switch(ch){
                case '+' :
                    test.push(number1 + number2);
                    break;
                case '-' :
                    test.push(number1 - number2);
                    break;
                case '*' :
                    test.push(number1 * number2);
                    break;
                case '/' :
                    test.push(number1 / number2);
                    break;
            }
        } else if(ch != ' ') {
            number = number * 10 + ch - '0';
        } else if(ch == ' ' && number != 0) {
            test.push(number);
            number = 0;
        }
        ch = getchar();
    }
    return test.top();
}

string mediumList_lastList(){
    stack<char> test;
    char ch = getchar();
    int number = 0;
    string list = "";
    while(ch != '\n') {
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ')'){
            if(ch == '*' || ch == '/') {
            	while(!test.empty() && test.top() != '(' && (test.top() == '*' || test.top() == '/')) {
	            	cout << test.top() << " ";
	            	list = list + test.top() + " ";
	            	test.pop();
	            }
                test.push(ch);
            } else if(ch == ')') {
                while(test.top() != '(') {
                    cout << test.top() << " ";
                    list = list + test.top() + " ";
                    test.pop();
                }
                test.pop();
            } else {
            	if(test.empty()) {
	            	test.push(ch);
	            } else {
            		while(!test.empty() && test.top() != '(') {
	                    cout << test.top() << " ";
	                    list = list + test.top() + " ";
	                    test.pop();
	                }
	                test.push(ch);
            	}
            }
        } else if(ch == '(') {
            test.push(ch);
        } else if(ch == ' ' && number != 0) {
            cout << number << " ";
            list += to_string(number) + " ";
            number = 0;
        } else if(ch >= '0' && ch <= '9') {
            number = number * 10 + ch - '0';
        }
        ch = getchar();
    }
    cout << number << " ";
    list += to_string(number) + " ";
    while(!test.empty()) {
    	cout << test.top() << " ";
        list = list + test.top() + " ";
    	test.pop();
    }
    cout << endl;
    return list;
}

int main(){
    cout << mediumList_lastList() << endl;
    return 0;
}
// 9 3 1 - 3 * + 10 2 / +
// 9 + ( 3 - 1 ) * 3 + 10 / 2