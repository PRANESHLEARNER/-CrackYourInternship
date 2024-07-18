class BSTIterator {
private:
    stack<TreeNode*> stk;

    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = stk.top();
        stk.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};