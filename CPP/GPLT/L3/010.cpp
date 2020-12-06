#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, temp;
    cin >> n;
    vector<int> arr(n * 2 + 1);
    fill(arr.begin(), arr.end(), -1);
    // 先存储根节点
    cin >> temp;
    arr[1] = temp;
    bool flag = true; // 用于判断是不是完全二叉树
    for(int i = 1; i < n; i++) {
        cin >> temp;
        int index = 1;
        while(true) {
            // 如果当前节点已经有数据了，就判断大小
            if(arr[index] != -1) {
                if(temp > arr[index]) {
                    // 如果比当前节点大，就移动到左孩子
                    index *= 2;
                } else {
                    // 否则移动到右孩子
                    index = index * 2 + 1;
                }
            } else {
                // 如果当前节点没有存数据，直接存入temp
                arr[index] = temp;
                break;
            }
        }
    }
    // count：输出有效节点的计数器（用于输出完所有节点之后结束循环）
    // index：当前遍历到的节点下标
    int count = 0, index = 1;
    while (true) {
        if(arr[index] == -1) {
            // 在遍历到尾部之前就出现未存放数据的节点就说明不是完全二叉树
            flag = false;
        } else {
            if(count != 0) printf(" ");
            printf("%d", arr[index]);
            count++;
        }
        // 如果所有元素都输出了，就打印一个回车并结束循环
        if(count == n) {
            puts("");
            break;
        }
        index++;
    }
    if(flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}