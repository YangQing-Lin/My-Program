#include<stdio.h>
#include<iostream>

typedef struct node{
    int data;
    node* next;
} node;

typedef struct {
    node* front;
    node* rear;
    int length;
} LinkQueue;

int CreateQueue(LinkQueue* Q) {
    node* p;
    p = (node*)malloc(sizeof(node));
    if(!p) return 0;
    p->data = -1;
    p->next = NULL;
    Q->front = p;
    Q->rear = p;
    Q->length = 0;
    return 1;
}

int Push(LinkQueue* Q, int text) {
    node* p;
    p = (node*)malloc(sizeof(node));
    if(!p) return 0;
    p->data = text;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    // if(Q->length == 0) {
    //     Q->front = Q->front->next;
    // }
    Q->length++;
    return 1;
}

int Empty(LinkQueue* Q) {
    if(Q->front == Q->rear) {
        return 1;
    }
    return 0;
}

int Top(LinkQueue* Q, int* e) {
    if(Empty(Q) == 0) {
        *e = Q->front->next->data;
        return 1;
    }
    printf("GetTop ERROR!\n");
    return 0;
}

int Pop(LinkQueue* Q, int* e) {
    if(Empty(Q) == 1) {
        return 0;
    }
    Top(Q, e);
    Q->front = Q->front->next;
    Q->length--;
    return 1;
}

int LengthQueue(LinkQueue* Q) {
    return Q->length;
}

int Clear(LinkQueue* Q) {
    Q->front = Q->rear;
    Q->length = 0;
    return 1;
}

int EvaluateExperssion(LinkQueue Q) {
    CreateQueue(&Q);
    int n;
    for(int i = 10; i <= 20; i++) {
        Push(&Q, i);
    }
    printf("LengthQueue = %d\n", LengthQueue(&Q));
    if(Top(&Q, &n) == 1) {
        printf("Top = %d\n", n);
    }
    Pop(&Q, &n);
    printf("LengthQueue = %d\n", LengthQueue(&Q));
    Clear(&Q);
    printf("LengthQueue = %d\n", LengthQueue(&Q));
    return 0;
}

int Think(LinkQueue Q) {
    CreateQueue(&Q);
    char ch = getchar();
    int index = 1, n;
    while(ch != 'q') {
        if(ch == 'a') {
            Push(&Q, index);
            printf("%d号入队\n", index++);
        }
        else if (ch == 'n') {
            Pop(&Q, &n);
            printf("%d号出队", n);
        }
        do {
            ch = getchar();
        } while(ch == ' ' || ch == '\n');
    }
    while(Empty(&Q) == 0) {
        int n;
        Pop(&Q, &n);
        printf("%d号出队\n", n);
    }
    printf("看病结束!\n");
    return 0;
}

int main() {
    LinkQueue Q;
    //EvaluateExperssion(Q);
    Think(Q);
    return 0;
}