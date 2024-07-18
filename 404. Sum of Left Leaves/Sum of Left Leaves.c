int sumOfLeftLeavesHelper(struct TreeNode* node, int isLeft) {
    if (!node) return 0;
    if (!node->left && !node->right && isLeft) return node->val;
    return sumOfLeftLeavesHelper(node->left, 1) + sumOfLeftLeavesHelper(node->right, 0);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return sumOfLeftLeavesHelper(root, 0);
}