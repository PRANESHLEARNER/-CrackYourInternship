void dfs(struct TreeNode* root, long long int targetSum, long long int currentSum, int* count) {
    if (root == NULL) {
        return;
    }
    
    currentSum += root->val;
    if (currentSum == targetSum) {
        (*count)++;
    }
    
    dfs(root->left, targetSum, currentSum, count);
    dfs(root->right, targetSum, currentSum, count);
}

int pathSum(struct TreeNode* root, long long int targetSum) {
    if (root == NULL) {
        return 0;
    }
    
    int count = 0;
    dfs(root, targetSum, 0, &count);
    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);
    
    return count;
}