#include<stdio.h>
#include<iostream>
#include<string>
#include<cctype>
#define MAXSIZE 30
using namespace std;

typedef struct {
    string data[MAXSIZE];
    int top;
} Stack;

void create_stake(Stack* s) {
    s->top = 0;
}

string pop(Stack* s) {
    string e;
    if(s->top != 0){
        s->top--;
        e = s->data[s->top];
        return e;
    }
    else {
        // 栈空，弹出数据失败
        return "-1";
    }
}

string top(Stack* s) {
    return s->data[s->top-1];
}

void clear(Stack* s) {
    s->top = 0;
    printf("清空完成\n");
}

void push(Stack* s, string e) {
    if(s->top < MAXSIZE-1) {
        s->data[s->top] = e;
        s->top++;
    }
}

int size(Stack* s) {
    return s->top;
}

int calculate(int a, string Operator, int b) {
    if(Operator == "+") {
        return a+b;
    }
    else if(Operator == "-") {
        return a-b;
    }
    else if(Operator == "*") {
        return a*b;
    }
    else {
        return (int)a/b;
    }
}

void Polish() {
    Stack s;
    create_stake(&s);
    int n;
    printf("将要输入字符的总个数：\n");
    cin >> n;
    string input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        // 如果是运算符就直接输入
        if(input == "*" || input == "/" || input == "+" || input == "-") {
            push(&s, input);
        }
        // 如果是数字就进行判断
        else {
            string temp;
            temp = top(&s);
            bool flag = true;
            // 判断栈顶元素是不是数字
            // 如果不是数字，直接入栈(需要考虑负数的情况)
            if(temp.length() == 1 && (temp < "0" || temp > "9")) {
                push(&s, input);
            }
            // 若栈顶元素是数字
            // 则弹出数字以及后面的运算符进行运算
            // 并把运算结果入栈
            else {
                int a = stoi(pop(&s));
                string Operator = pop(&s);
                push(&s, to_string(calculate(a, Operator, stoi(input))));
            }
        }
    }
    // 如果输入的是 - 5 * 6 7，最后栈里还会剩下一些元素没有进行运算
    // 通过while循环把栈里所有的元素都取出来运算
    while(size(&s) > 1) {
        int b = stoi(pop(&s));
        int a = stoi(pop(&s));
        string Operator = pop(&s);
        push(&s, to_string(calculate(a, Operator, b)));
    }
    printf("答案：%d\n", stoi(pop(&s)));
}

int main() {
    Polish();
    return 0;
}
/*
输入样例：
5
- 5 * 6 7
*/