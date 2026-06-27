class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixCount;
        prefixCount[0] = 1;
        return dfs(root, 0, targetSum, prefixCount);
    }
    
private:
    int dfs(TreeNode* node, long long currSum, int target, unordered_map<long long, int>& prefixCount) {
        if (!node) return 0;
        
        currSum += node->val;
        int count = prefixCount[currSum - target];
        
        prefixCount[currSum]++;
        count += dfs(node->left, currSum, target, prefixCount);
        count += dfs(node->right, currSum, target, prefixCount);
        prefixCount[currSum]--;
        
        return count;
    }
};