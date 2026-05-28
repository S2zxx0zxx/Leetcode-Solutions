class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        
        # isPalin[i][j] = True if s[i..j] is palindrome
        isPalin = [[False] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j - i <= 2 or isPalin[i+1][j-1]):
                    isPalin[i][j] = True
        
        # dp[i] = min cuts for s[0..i]
        dp = list(range(n))
        for i in range(1, n):
            if isPalin[0][i]:
                dp[i] = 0
                continue
            for j in range(1, i + 1):
                if isPalin[j][i]:
                    dp[i] = min(dp[i], dp[j-1] + 1)
        
        return dp[n-1]