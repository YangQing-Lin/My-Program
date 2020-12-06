#include<stdio.h>
#define MAXSIZE 30

typedef struct {
    int data[MAXSIZE];
    int top;
} Stack;

void create_stake(Stack* s) {
    s->top = 0;
}

int pop(Stack* s) {
    int e;
    if(s->top != 0){
        s->top--;
        e = s->data[s->top];
        return e;
    }
    else {
        // 栈空，弹出数据失败
        return -1;
    }
}

int top(Stack* s) {
    return s->data[s->top-1];
}

void clear(Stack* s) {
    s->top = 0;
    printf("清空完成\n");
}

void push(Stack* s, int e) {
    if(s->top < MAXSIZE-1) {
        s->data[s->top] = e;
        s->top++;
    }
}

int size(Stack* s) {
    return s->top;
}

int main() {
    Stack s;
    create_stake(&s);
    for(int i = 0; i < 10; i++) {
        push(&s, 10-i);
    }
    printf("栈顶元素：%d\n", top(&s));
    printf("栈的大小：%d\n", size(&s));
    pop(&s);
    printf("第二个元素：%d\n", top(&s));
    clear(&s);
    printf("清空后栈的大小：%d\n", size(&s));
    return 0;
}