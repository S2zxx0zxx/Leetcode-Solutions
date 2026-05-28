class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<unsigned long long> dp(n+1, 0);
        dp[0] = 1;

        for(int i = 0; i < m; i++)
            for(int j = n-1; j >= 0; j--)
                if(s[i] == t[j])
                    dp[j+1] += dp[j];

        return (int)dp[n];
    }
};