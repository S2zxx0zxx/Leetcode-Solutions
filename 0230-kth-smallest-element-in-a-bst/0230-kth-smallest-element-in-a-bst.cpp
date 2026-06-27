class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        inorder(root, k, result);
        return result;
    }
    
private:
    void inorder(TreeNode* node, int& k, int& result) {
        if (!node) return;
        inorder(node->left, k, result);
        if (--k == 0) { result = node->val; return; }
        inorder(node->right, k, result);
    }
};