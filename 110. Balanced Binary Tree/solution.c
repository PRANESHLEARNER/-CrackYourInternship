int height(struct TreeNode* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) return -1;
    return fmax(leftHeight, rightHeight) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return height(root) != -1;
}