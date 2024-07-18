class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root) dfs(root, "", paths);
        return paths;
    }
    
private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        path += to_string(node->val);
        if(!node->left && !node->right) paths.push_back(path);
        if(node->left) dfs(node->left, path + "->", paths);
        if(node->right) dfs(node->right, path + "->", paths);
    }
};