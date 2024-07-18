class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false; // If the main tree is empty, there can't be a subtree.
        if (isSameTree(root, subRoot)) return true; // If the trees are identical, return true.
        // Recursively check each subtree of the main tree.
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
private:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true; // Both trees are empty.
        if (!s || !t) return false; // One tree is empty, and the other is not.
        if (s->val != t->val) return false; // The values of the nodes don't match.
        // Recursively check the left and right subtrees.
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};