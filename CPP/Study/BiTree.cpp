//实验7提示及部分源程序：
#include "stdio.h"
#include "stdlib.h"
#define MaxSize 100
#define OK 1
#define ERROR 0
typedef int Status;
typedef int TElemType;

typedef struct BiTNode { /* 结点结构*/
    TElemType      data;
    struct BiTNode  *lchild, *rchild;      /* 左右孩子指针*/
} BiTNode, *BiTree,*SElemType;

typedef struct {
      SElemType elem[MaxSize];
      int top;/*栈顶元素的下标，栈空时为-1*/
  }SqStack;

Status InitStack(SqStack *s) /*栈的初始化*/
{    s->top=-1;
     return OK;
} /*InitStack;*/

void ClearStack(SqStack *s) /*把S置为空栈*/
{   s->top=-1;
}

Status StackEmpty(SqStack s) /*判断S是否为空栈*/
{  return(s.top==-1);
}

SElemType GetTop(SqStack s) /*取栈顶元素*/
{
     return(s.elem[s.top]);
   }/*GetTop*/

Status Push(SqStack *s,SElemType e) /*压栈操作*/
{   if(s->top>=MaxSize-1) return ERROR;/*栈满时不再入栈*/
   s->elem[++s->top]=e;
   return OK;
}

Status Pop(SqStack *s,SElemType *e) /*出栈操作*/
{ if(s->top==-1)return ERROR;/*空栈*/
   *e=s->elem[ s->top--];
  return OK;
}  /*Pop*/

Status in(SqStack s,SElemType e)/*判断e是否在栈s中*/
{	int i;
	if(StackEmpty(s)) return 0;
	for (i=1;i<=s.top;i++)
	if(s.elem[i]==e) return 1;
	return 0;
}

BiTree CreateBiTree_rc(void)/*用递归的思想来实现*/
{
  /*按先序次序输入二叉树中结点的值(数值),0表示空树*/
  /*构造二叉链表表示的二叉树T*/
  int value;
  BiTree newnode;
  scanf("%d",&value);
  if(value==0) return NULL;
  else
   {
	newnode=(BiTree)malloc(sizeof(BiTNode));
	newnode->data=value;
	newnode->lchild=CreateBiTree_rc();
	newnode->rchild=CreateBiTree_rc();
	return newnode;
   }
}

void PrintNode(BiTree T,int level)
{/*打印二叉树*/
    /*请完成函数*/
    while(level--) printf("  ");
    printf("%d\n", T->data);
}

void PreOrderTraverse(BiTree T)
{/*递归前序遍历算法*/
/*请完成函数*/
    SElemType p = T;
    if(!p) return ;    
    printf("%d ", p->data);
    PreOrderTraverse(p->lchild);
    PreOrderTraverse(p->rchild);
}

void InOrderTraverse(BiTree T)
{/*递归中序遍历算法*/
/*请完成函数*/
    SElemType p = T;
    if(!p) return ;
    InOrderTraverse(p->lchild);
    printf("%d ", p->data);
    InOrderTraverse(p->rchild);
}

void PostOrderTraverse(BiTree T)
{/*递归后序遍历算法*/
/*请完成函数*/
    SElemType p = T;
    if(!p) return ;
    PostOrderTraverse(p->lchild);
    PostOrderTraverse(p->rchild);
    printf("%d ", p->data);
}


void PreOrderTraverse1(BiTree T)
{/*先序遍历的非递归算法*/
SqStack s;
SElemType p;
   InitStack(&s);
   p=T;
   while(p||!StackEmpty(s) )
  {  
	if(p)
	{ printf("%d ",p->data);
      Push(&s,p);p=p->lchild;
	}
	else
	{Pop(&s,&p);
         p=p->rchild;
	}
  }
 }

void InOrderTraverse1(BiTree T)
{/*中序遍历的非递归算法*/
/*请完成函数*/
    SqStack s;
    int end = 0;
    SElemType p, q;
    InitStack(&s);
    p = T;
    while (p || !StackEmpty(s)) {
        if(p) {
            Push(&s, p);
            p = p->lchild;
        } else {
            Pop(&s, &p);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void PostOrderTraverse1(BiTree T)
{/*后序遍历的非递归算法*/
    SqStack s;
    int end=0;
    SElemType p,q;
    InitStack(&s);
    p=T;
    while(p&&end==0){  
        while(p){
            Push(&s,p);
            p=p->lchild ;
        }
        q=GetTop(s);
        while((p==q->rchild||!q->rchild )&&end==0 ) {
            Pop(&s,&p);
            printf("%d ",p->data);
            if(p==T)
                end=1;
            else
                q=GetTop(s);
        }
        p=q->rchild;
    }
}

void PrintBiTree(BiTree T)
{/*中序遍历打印整个树状结构*/
    SqStack s;
    int level = 0;
    SElemType p, q;
    InitStack(&s);
    p = T;
    while (p || !StackEmpty(s)) {
        if(p) {
            Push(&s, p);
            level++;
            p = p->lchild;
        } else {
            Pop(&s, &p);
            PrintNode(p, level);
            level--;
            p = p->rchild;
        }
    }
}

int main()
{/*此处编写主函数，调用前面的函数，自己设计测试数据来验证*/
    BiTree T = CreateBiTree_rc();
    printf("前序遍历-递归:   ");
    PreOrderTraverse(T);
    puts("");
    printf("前序遍历-非递归: ");
    PreOrderTraverse1(T);
    puts("");
    printf("中序遍历-递归:   ");
    InOrderTraverse(T);
    puts("");
    printf("中序遍历-非递归: ");
    InOrderTraverse1(T);
    puts("");
    printf("后序遍历-递归:   ");
    PostOrderTraverse(T);
    puts("");
    printf("后序遍历-非递归: ");
    PostOrderTraverse1(T);
    puts("");
    printf("打印树状结构: \n");
    PrintBiTree(T);
    return 0;
}
// 10 5 4 0 0 0 7 4 0 5 0 0 9 0 0

/*
10
5
4
0
0
0
7
4
0
5
0
0
9
0
0
*/