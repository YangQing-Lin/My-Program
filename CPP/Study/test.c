#include<stdio.h>
#include<math.h>

typedef struct {
    data_t data;
    tree_t * left;
    tree_t * right;
};

int
tree_deep(tree_t* t) {
    if(t == NULL) {
        return 0;
    }
    int deep_left_tree = tree_deep(t->left);
    int deep_right_tree = tree_deep(t->right);
    return deep_left_tree > deep_right_tree ? deep_left_tree+1 : deep_right_tree+1;
}

int
is_happy_tree(tree_t* t) {
    if(fabs(tree_deep(t->left) - tree_deep(t->right)) >= 2) {
        return 0;
    }
    if(t == NULL) return 1;
    return is_happy_tree(t->left) & is_happy_tree(t->right);
}

int 
tree_freq(tree_t* t, data_t* key) {
    if(t == NULL) return 0;
}



// int
// is_happy_tree(tree_t* t) {
//     // 从题干中可以看出，如果一棵树的节点中只要有一个节点不happy，那么整棵树就不happy
//     // 而且
//     if((t->left != NULL && t->right == NULL)
//     || (t->left == NULL && t->right != NULL)) {
//         return 0;
//     } else if(t->left == NULL && t->right == NULL) {
//         return 1;
//     } else {
//         return is_happy_tree(t->left) & is_happy_tree(t->right);
//     }
// }

int main() {
    return 0;
}