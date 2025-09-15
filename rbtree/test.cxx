#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct RBTreeNode {
    int data;
    Color color;
    struct RBTreeNode *left, *right, *parent;
} RBTreeNode;

// 全局哨兵节点（所有叶子节点指向它）
RBTreeNode *NIL;

// 初始化哨兵节点
void initNIL() {
    NIL = (RBTreeNode *)malloc(sizeof(RBTreeNode));
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = NIL;
}

// 创建新节点
RBTreeNode* createNode(int data) {
    RBTreeNode *node = (RBTreeNode *)malloc(sizeof(RBTreeNode));
    node->data = data;
    node->color = RED; // 新节点初始为红色
    node->left = node->right = node->parent = NIL;
    return node;
}

/*------------ 旋转操作 ------------*/
// 左旋
void leftRotate(RBTreeNode **root, RBTreeNode *x) {
    RBTreeNode *y = x->right;
    x->right = y->left;
    
    if (y->left != NIL) {
        y->left->parent = x;
    }
    
    y->parent = x->parent;
    
    if (x->parent == NIL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

// 右旋
void rightRotate(RBTreeNode **root, RBTreeNode *y) {
    RBTreeNode *x = y->left;
    y->left = x->right;
    
    if (x->right != NIL) {
        x->right->parent = y;
    }
    
    x->parent = y->parent;
    
    if (y->parent == NIL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    
    x->right = y;
    y->parent = x;
}

/*------------ 插入操作 ------------*/
// 插入修复
void insertFixup(RBTreeNode **root, RBTreeNode *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBTreeNode *y = z->parent->parent->right;
            if (y->color == RED) { // Case 1: 叔叔是红色
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) { // Case 2: 叔叔是黑色且当前节点是右孩子
                    z = z->parent;
                    leftRotate(root, z);
                }
                // Case 3: 叔叔是黑色且当前节点是左孩子
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            // 对称情况（与上面相反方向）
            RBTreeNode *y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

// 插入节点
void insert(RBTreeNode **root, int data) {
    RBTreeNode *z = createNode(data);
    RBTreeNode *y = NIL;
    RBTreeNode *x = *root;
    
    // 标准BST插入
    while (x != NIL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    
    z->parent = y;
    if (y == NIL) {
        *root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }
    
    insertFixup(root, z);
}

/*------------ 删除操作 ------------*/
// 替换子树（将u替换为v）
void transplant(RBTreeNode **root, RBTreeNode *u, RBTreeNode *v) {
    if (u->parent == NIL) {
        *root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// 查找最小节点
RBTreeNode* minimum(RBTreeNode *x) {
    while (x->left != NIL) {
        x = x->left;
    }
    return x;
}

// 删除修复
void deleteFixup(RBTreeNode **root, RBTreeNode *x) {
    while (x != *root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBTreeNode *w = x->parent->right;
            if (w->color == RED) { // Case 1: 兄弟是红色
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) { // Case 2
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) { // Case 3
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                // Case 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(root, x->parent);
                x = *root;
            }
        } else {
            // 对称情况（与上面相反方向）
            RBTreeNode *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(root, x->parent);
                x = *root;
            }
        }
    }
    x->color = BLACK;
}

// 删除节点
void deleteNode(RBTreeNode **root, int data) {
    RBTreeNode *z = *root;
    // 查找要删除的节点
    while (z != NIL) {
        if (data == z->data) {
            break;
        } else if (data < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    }
    if (z == NIL) return; // 未找到节点

    RBTreeNode *y = z;
    RBTreeNode *x;
    Color y_original_color = y->color;
    
    if (z->left == NIL) {
        x = z->right;
        transplant(root, z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        transplant(root, z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    
    if (y_original_color == BLACK) {
        deleteFixup(root, x);
    }
    free(z);
}

/*------------ 遍历和验证 ------------*/
// 中序遍历
void inorder(RBTreeNode *root) {
    if (root == NIL) return;
    inorder(root->left);
    printf("%d(%s) ", root->data, root->color == RED ? "RED" : "BLACK");
    inorder(root->right);
}

// 验证红黑树性质
int verifyProperties(RBTreeNode *node) {
    if (node == NIL) return 1;
    
    // 性质4：红色节点的子节点必须是黑色
    if (node->color == RED) {
        if (node->left->color != BLACK || node->right->color != BLACK) {
            printf("Violation: Red node %d has red child\n", node->data);
            return 0;
        }
    }
    
    return verifyProperties(node->left) && verifyProperties(node->right);
}

// 计算黑高度（用于验证性质5）
int blackHeight(RBTreeNode *node) {
    if (node == NIL) return 0; // 哨兵节点不算高度
    int leftHeight = blackHeight(node->left);
    int rightHeight = blackHeight(node->right);
    if (leftHeight == -1 || rightHeight == -1 || leftHeight != rightHeight) {
        return -1; // 表示错误
    }
    return leftHeight + (node->color == BLACK ? 1 : 0);
}

/*------------ 主函数 ------------*/
int main() {
    initNIL();
    RBTreeNode *root = NIL;
    
    // 插入测试
    int testData[] = {7, 3, 18, 10, 22, 8, 11, 26};
    for (size_t i = 0; i < sizeof(testData)/sizeof(testData[0]); i++) {
        insert(&root, testData[i]);
    }
    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    
    // 验证红黑树性质
    if (root->color != BLACK) {
        printf("Violation: Root is not black\n");
    }
    
    if (!verifyProperties(root)) {
        printf("Red-Black tree properties violated\n");
    } else if (blackHeight(root) == -1) {
        printf("Red-Black tree properties violated\n");
    } else {
        printf("All Red-Black tree properties are satisfied\n");
        printf("Black height: %d\n", blackHeight(root));
    }
    
    // 删除测试
    deleteNode(&root, 18);
    printf("After deleting 18: ");
    inorder(root);
    printf("\n");
    
    return 0;
}
