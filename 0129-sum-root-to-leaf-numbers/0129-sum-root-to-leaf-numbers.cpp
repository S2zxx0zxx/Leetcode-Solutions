class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;
        curr = curr * 10 + node->val;
        if (!node->left && !node->right) return curr;
        return dfs(node->left, curr) + dfs(node->right, curr);
    }
};