class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;
        inorder(root, prev, minDiff);
        return minDiff;
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (!node) return;
        inorder(node->left, prev, minDiff);
        if (prev) minDiff = min(minDiff, node->val - prev->val);
        prev = node;
        inorder(node->right, prev, minDiff);
    }
};