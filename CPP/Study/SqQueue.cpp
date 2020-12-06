#include<stdio.h>
#define MAX_Q_SIZE 15
typedef struct {
    int data[MAX_Q_SIZE];
    int front;
    int rear;
} SqQueue;

int CreateQueue(SqQueue* Q) {
    Q->front = 0;
    Q->rear = Q->front;
}

int LengthQueue(SqQueue* Q) {
    return (Q->rear + MAX_Q_SIZE - Q->front) % MAX_Q_SIZE;
}

int Push(SqQueue* Q, int text) {
    if(LengthQueue(Q) == MAX_Q_SIZE-1) {
        printf("Queue is FULL!\n");
        return 0;
    }
    Q->data[Q->rear] = text;
    Q->rear = Q->rear == MAX_Q_SIZE-1 ? 0 : Q->rear+1;
    return 1;
}

int Empty(SqQueue* Q) {
    if(Q->rear == Q->front) {
        printf("Queue is Empty!\n");
        return 1;
    }
    return 0;
}

int Top(SqQueue* Q) {
    if(Empty(Q) == 0) {
        return Q->data[Q->front];
    }
    return 0;
}

int Pop(SqQueue* Q, int* e) {
    *e = Top(Q);
    if(*e != 0) {
        Q->front = Q->front == MAX_Q_SIZE-1 ? 0 : Q->front+1;
        return 1;
    }
    return 0;
}

int clear(SqQueue* Q) {
    Q->front = Q->rear;
}

int EvaluateExperssion(SqQueue Q) {
    CreateQueue(&Q);
    for(int i = 3; i <= 15; i++) {
        Push(&Q, i);
    }
    printf("LengthQueue = %d\n", LengthQueue(&Q));
    int n;
    printf("TopQueue = %d\n", Top(&Q));
    Pop(&Q, &n);
    printf("LengthQueue = %d\n", LengthQueue(&Q));
    clear(&Q);
    printf("After Clear LengthQueue = %d\n", LengthQueue(&Q));
    return 0;
}

int main() {
    SqQueue Q;
    EvaluateExperssion(Q);
    return 0;
}