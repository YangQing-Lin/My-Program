#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define MAXSIZE 50

typedef struct Node{
	int data;
	Node* next;
}*LinkList;

typedef struct{
	int data[MAXSIZE];
	int length;
}SqList;

// 确定最大节点
int max_num(LinkList* L) {
    LinkList p = *L;
    int maxn = 0;
    while(p->next != NULL) {
        maxn = std::max(p->data, maxn);
        p = p->next;
    }
    return maxn;
}

// 删除给定范围内的所有元素
void delete_between_two_numbers(LinkList* L, int start, int end) {
    LinkList p = *L, start_l, end_l;
    int flag = 0;
    while(p->next != NULL) {
        if(!flag && p->next->data >= start) {
            start_l = p;
            flag = 1;
        }
        if(p->data >= end) {
            end_l = p;
            break;
        }
    }
    start_l->next = end_l->next;
}

// 删除值为item的元素
void delete_equals_item(SqList* S, int item) {
    int* p = S->data;
    int* q = S->data;
    for(int i = 0; i < (*S).length; i++) {
        if((*q) != item) {
            p++;
            q++;
        } else {
            q++;
            *p = *q;
        }
    }
    (*S).length -= q-p;
}