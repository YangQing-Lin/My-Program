#include<stdio.h>
#define MAXSIZE 50

typedef struct{
	int data[MAXSIZE];
	int length;
}SqList;

int create_list(SqList* L) {
    for(int i = 0; i < 10; i++) {
        L->data[i] = i+1;
    }
    L->length = 10;
    return 1;
}

int insert_data(SqList* L, int data, int address) {
    for(int i = L->length; i > address; i--) {
        L->data[i] = L->data[i-1];
    }
    L->data[address] = data;
    L->length++;
    return 1;
}

int delete_data(SqList* L, int address) {
    printf("删除元素: %d\n", L->data[address]);
    for(int i = address; i < L->length-1; i++) {
        L->data[i] = L->data[i+1];
    }
    L->length--;
    return 1;
}

int link_list(SqList* L1, SqList* L2) {
    for(int i = L1->length; i < L1->length + L2->length; i++) {
        L1->data[i] = L2->data[i - L1->length];
    }
    L1->length += L2->length;
    return 1;
}

int print_list(SqList* L) {
    for(int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    puts("");
}

int main() {
    SqList L1;
    SqList L2;
    create_list(&L1);
    print_list(&L1);
    create_list(&L2);
    print_list(&L2);

    insert_data(&L1, 8, 3);
    print_list(&L1);

    delete_data(&L1, 6);
    print_list(&L1);
    
    link_list(&L1, &L2);
    print_list(&L1);
    return 0;
}