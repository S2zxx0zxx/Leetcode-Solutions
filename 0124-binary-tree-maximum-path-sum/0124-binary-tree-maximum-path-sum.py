class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = float('-inf')
        
        def dfs(node):
            if not node:
                return 0
            
            left  = max(dfs(node.left), 0)
            right = max(dfs(node.right), 0)
            
            self.res = max(self.res, node.val + left + right)
            
            return node.val + max(left, right)
        
        dfs(root)
        return self.res     