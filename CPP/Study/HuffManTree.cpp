#include<bits/stdc++.h>
using namespace std;
#define MAX_NODE 80

struct node {
    unsigned int weight, parent, lchild, rchild;
    string code;
    char ch;
};

// 0号位置的weight数据用来存储当前树内的节点个数
node arr[MAX_NODE];
int n = 26;

void init() {
    node temp = {0, 0, 0, 0, ""};
    for(int i = 0; i < MAX_NODE; i++) {
        arr[i] = temp;
        if(i <= 26) arr[i].ch = 'a' + i - 1;
    }
    printf("输入26个数字: \n");
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i].weight);
    }
    arr[0].weight = n;
}
// 10 16 20 6 30 24 10 16 20 6 30 24 10 16 20 6 30 24 10 16 20 6 30 24 56 2

void print_huffman_tree() {
    printf("\n---------------HuffManTree---------------\n");
    printf("index  weight  parent  lchild  rchild ch  code\n");
    for(int i = 1; i <= arr[0].weight; i++) {
        printf("%6d %6d %6d %6d %6d    %c   %s\n",
        i, arr[i].weight, arr[i].parent,
        arr[i].lchild, arr[i].rchild,
        arr[i].ch, arr[i].code.c_str());
    }
    puts("");
}

void calculation_huffmancode(int n, string str) {
    if(arr[n].lchild == 0) {
        arr[n].code = str;
        return ;
    }
    calculation_huffmancode(arr[n].lchild, str + '0');
    calculation_huffmancode(arr[n].rchild, str + '1');
}

void huffmancode_to_string(string str) {
    string temp = "", ans = "";
    int j;
    // 这里的时间复杂度可以优化，用set和它自带的find函数
    for(int i = 0; i < str.length(); i++) {
        temp += str[i];
        for(j = 1; j <= 26; j++) {
            if(arr[j].code == temp) break;
        }
        if (j <= 26) {
            ans += arr[j].ch;
            temp = "";
        }
    }
    printf("String: %s\n", ans.c_str());
}

// 从根节点开始根据huffmancode一步一步搜索来解码
// 时间复杂度：O(nlog(n))  n是解码之后字符的长度
// 空间复杂度：O(1)   主要优化了空间复杂度
void huffmancode_to_string_optimize(string str) {
    int index = 51;
    string ans = "";
    for(int i = 0; i < str.length(); i++) {
        index = str[i] == '0' ? arr[index].lchild : arr[index].rchild;
        if(arr[index].lchild == 0) {
            ans += arr[index].ch;
            index = 51;
        }
    }
    printf("String: %s\n", ans.c_str());
}

void create_huffman_tree() {
    int lindex, rindex;
    for (int i = n + 1; i <= 2 * n - 1; i++) {
        lindex = rindex = -1;
        for(int i = 1; i <= arr[0].weight; i++) {
            if (arr[i].parent != 0) continue;
            if (lindex == -1) lindex = i;
            if (arr[i].weight < arr[lindex].weight) {
                lindex = i;
            }
        }
        for(int i = 1; i <= arr[0].weight; i++) {
            if (arr[i].parent != 0 || i == lindex) continue;
            if (rindex == -1) rindex = i;
            if (arr[i].weight < arr[rindex].weight) {
                rindex = i;
            }
        }
        arr[0].weight++;
        arr[arr[0].weight].weight = arr[lindex].weight + arr[rindex].weight;
        arr[arr[0].weight].lchild = lindex;
        arr[arr[0].weight].rchild = rindex;
        arr[lindex].parent = arr[0].weight;
        arr[rindex].parent = arr[0].weight;
    }
    calculation_huffmancode(n * 2 - 1, "");
    print_huffman_tree();
}

string string_to_huffmancode() {
    string str = "";
    char ch;
    while (ch = getchar(), ch != '\n');
    printf("Input the String: ");
    while (ch = getchar(), ch != '\n') {
        str += arr[ch - 'a' + 1].code;
    }
    printf("HuffManCode: %s\n", str.c_str());
    return str;
}

void run() {
    init();
    create_huffman_tree();
    string str = string_to_huffmancode();
    huffmancode_to_string(str);
    huffmancode_to_string_optimize(str);
}

int main() {
    run();
    return 0;
}