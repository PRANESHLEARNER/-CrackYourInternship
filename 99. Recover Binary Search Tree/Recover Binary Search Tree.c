void swap(struct TreeNode* a, struct TreeNode* b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}

void findSwappedNodes(struct TreeNode* root, struct TreeNode** first, struct TreeNode** second, struct TreeNode** prev) {
    if (root == NULL) return;
    findSwappedNodes(root->left, first, second, prev);
    if (*prev && (*prev)->val > root->val) {
        if (!*first) *first = *prev;
        *second = root;
    }
    *prev = root;
    findSwappedNodes(root->right, first, second, prev);
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode *first = NULL, *second = NULL, *prev = NULL;
    findSwappedNodes(root, &first, &second, &prev);
    if (first && second) swap(first, second);
}