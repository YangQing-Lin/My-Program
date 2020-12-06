#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

typedef struct Node{
	int data;
	Node* next;
}*LinkList;

// typedef struct Node *LinkList;

int create_link_list(LinkList* L) {
    LinkList temp = (LinkList)malloc(sizeof(Node));
    *L = temp;
    LinkList p = *L;
	p->data = 0; // 链表头节点设为0
	p->next = NULL;
	return 1;
}

// 向指定位置插入数据
int input_data(LinkList* L, int n,int address) {
	LinkList temp = (LinkList)malloc(sizeof(Node));
	LinkList p = *L;
	int j = 1; 
	while(p->next && j < address) {
		p = p->next;
		j++;
	}
	if(!p->next || j < address) {
		printf("位置非法\n");
		return 0;
	}
    temp->data = n;
	temp->next = NULL;
	temp->next = p->next;
	p->next = temp;
	return 1;
}

// 向链表尾部插入数据
int push_back_data(LinkList* L, int n) {
    LinkList p = *L;
    LinkList temp = (LinkList)malloc(sizeof(Node));
    while(p->next) {
        p = p->next;
    }
    temp->data = n;
    temp->next = NULL;
    p->next = temp;
}

// 删除数据
int delete_data(LinkList* L,int address) {
	LinkList p = *L;
	int j = 1;
	while(p->next && j < address) {
		p = p->next;
		j++;
	}
	if(!p->next || j < address) {
		printf("位置非法\n");
		return 0;
	}
    LinkList temp = p->next;
    p->next = p->next->next;
    printf("删除的数据为：%d\n", temp->data);
	free(temp);
    return 1;
}

int print_link_list(LinkList* L, int number) {
    printf("输出链表\n");
	LinkList p = *L;
	printf("LinkList%d: ", number);
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
	puts("");
	return 1; 
}

// 合并链表
int link_together(LinkList* L1, LinkList* L2) {
    LinkList p = *L1;
    while(p->next) {
        p = p->next;
    }
    p->next = (*L2)->next;
    printf("合并成功\n");
}

void joseph_circle(LinkList* L3,int N,int M) {
	LinkList p = *L3;
	for(int i = 1; i <= N; i++) {
		push_back_data(&p, i);
	}
	while(p->next) {
        p = p->next;
    }
	print_link_list(L3, 3);
	p->next = (*L3)->next;
	p = p->next;
	int index = 0;
	while(p->next != p) {
		if(++index == M-1) {
			LinkList temp = p->next;
			p->next = p->next->next;
			printf("%d号出局    ", temp->data);
			free(temp);
			index = 0;
		}
		p = p->next;
	}
	printf("\n幸存者编号: %d\n", p->data);
}

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

int main(){
	LinkList L1, L2, L3;
	int data, address;

	create_link_list(&L1); // 创建L1链表
    create_link_list(&L2); // 创建L2链表
	create_link_list(&L3); // 创建L2链表
    
    // 插入初始数据
    for(int i = 0; i < 10; i++) {
        push_back_data(&L1, i+1);
        push_back_data(&L2, 10-i);
    }
    print_link_list(&L1, 1);
    print_link_list(&L2, 2);

    // 指定位置插入数据
	printf("数据和插入位置: ");
	scanf("%d %d", &data, &address);
	input_data(&L1, data, address);
	print_link_list(&L1, 1);

	printf("删除数据位置: ");
	scanf("%d", &address);
	delete_data(&L1, address);
	print_link_list(&L1, 1);

    link_together(&L1, &L2);
    print_link_list(&L1, 1);

	printf("***************约瑟夫环***************\n");
	int N, M;
	printf("输入总人数N、标志M: ");
	scanf("%d %d", &N, &M);
	joseph_circle(&L3, N, M);
	return 0;
}