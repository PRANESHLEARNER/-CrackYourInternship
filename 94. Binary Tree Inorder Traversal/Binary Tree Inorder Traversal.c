/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;
    inorder(root->left, result, returnSize);
    result[(*returnSize)++] = root->val;
    inorder(root->right, result, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = malloc(100 * sizeof(int)); // Assuming the tree has at most 100 nodes
    inorder(root, result, returnSize);
    return result;
}