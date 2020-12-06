/*
这个程序来自于我昨晚的梦
昨晚连着做了3个梦
这个梦最短(大概只有10秒钟的样子)，但是给我的印象最深刻
那是一个形象的动画：
在白色的背景上，三个灰色的，带数字的圆圈组成了一个简单的二叉树
规则是根节点的值比左孩子大，且比右孩子小
第四个灰色圆圈一开始在二叉树之外，它的数字比根节点小，但是比左孩子大
紧接着它开始移动，从根节点的左边往下移，再从左孩子的右边往下移
最后它连接上左孩子，成为了它的右孩子

醒来后我仔细回忆那段动画，觉得非常有意思：
它向我演示了排序中一个单元的执行方式，以及构建堆的方法
这是我在书上没有看过的排序算法

编程思路：
主要思想是用数组来存储一个二叉树
每输入一个新的数字就比较堆顶数字和它的大小
如果它比堆顶数字小，就判断堆顶左孩子和它的大小；
否则与右孩子进行判断。
直到判断指针移动到叶子节点为止，将输入的数字赋值给叶子节点
至此，一个数字输入完成
*/
#include<iostream>
#include<cstring>
using namespace std;
#define MAX_SIZE 500
#define flag -1

int arr[MAX_SIZE];
int size = 1;

void insert_node(int number, int index) {
    if(arr[index] == flag) {
        arr[index] = number;
        return ;
    }
    if(number < arr[index]) {
        return insert_node(number, index*2);
    }
    else {
        return insert_node(number, index*2+1);
    }
}

void DLR(int index) {
    if(arr[index] == flag) return ;
    DLR(index*2);
    cout << arr[index] << " ";
    DLR(index*2+1);
}

int main() {
    memset(&arr[0], flag, sizeof(arr));
    printf("输入10个未排序的数:\n");
    int number;
    for(int i = 0; i < 10; i++) {
        cin >> number;
        insert_node(number, 1);
    }
    printf("排序后的结果为:\n");
    DLR(1);
    cout << endl;
    return 0;
}
// 4 3 5 9 1 18 4 73 6 1