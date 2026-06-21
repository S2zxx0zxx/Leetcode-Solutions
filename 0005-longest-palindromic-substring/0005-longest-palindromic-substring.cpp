class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }
            
            l = i; r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }
        }
        
        return s.substr(start, maxLen);
    }
};