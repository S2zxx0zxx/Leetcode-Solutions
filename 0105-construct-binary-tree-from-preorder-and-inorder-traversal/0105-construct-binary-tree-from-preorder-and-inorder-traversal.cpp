class Solution {
public:
    unordered_map<int,int> inIdx;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) inIdx[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* build(vector<int>& pre, int preL, int preR, int inL, int inR) {
        if (preL > preR) return nullptr;
        
        int rootVal = pre[preL];
        int mid = inIdx[rootVal];
        int leftSize = mid - inL;
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(pre, preL + 1, preL + leftSize, inL, mid - 1);
        root->right = build(pre, preL + leftSize + 1, preR, mid + 1, inR);
        
        return root;
    }
};