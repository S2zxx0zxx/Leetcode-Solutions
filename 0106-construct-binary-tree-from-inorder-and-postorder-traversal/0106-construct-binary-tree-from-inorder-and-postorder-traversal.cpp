class Solution {
public:
    unordered_map<int,int> inIdx;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) inIdx[inorder[i]] = i;
        return build(postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* build(vector<int>& post, int postL, int postR, int inL, int inR) {
        if (postL > postR) return nullptr;
        
        int rootVal = post[postR];
        int mid = inIdx[rootVal];
        int leftSize = mid - inL;
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(post, postL, postL + leftSize - 1, inL, mid - 1);
        root->right = build(post, postL + leftSize, postR - 1, mid + 1, inR);
        
        return root;
    }
};