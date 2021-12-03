#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};
//二叉树的前序遍历（迭代）
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* a = (int*)malloc(100 * sizeof(int));
    struct TreeNode* ts[100];
    int t = -1;

    while (t > -1 || root != NULL) {
        while (root != NULL) {
            a[(*returnSize)++] = root->val;
            ts[++t] = root;
            root = root->left;
        }
        root = ts[t--];
        root = root->right;
    }
    return a;
}
//二叉树的中序遍历（递推）
void traverse(struct TreeNode* root, int* returnSize, int* a) {
    if (root == NULL) {
        return;
    }
    traverse(root->left, returnSize, a);
    a[(*returnSize)++] = root->val;
    traverse(root->right, returnSize, a);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* a = (int*)malloc(100 * sizeof(int));
    traverse(root, returnSize, a);
    return a;
}
//二叉树的后续遍历（递推）
void traverse(struct TreeNode* root, int* returnSize, int* a) {
    if (root == NULL) {
        return;
    }
    traverse(root->left, returnSize, a);
    traverse(root->right, returnSize, a);
    a[(*returnSize)++] = root->val;
    return;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* a = (int*)malloc(100 * sizeof(int));
    traverse(root, returnSize, a);
    return a;
}