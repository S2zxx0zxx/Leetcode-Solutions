class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int maxLen = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (lastSeen.count(s[i]) && lastSeen[s[i]] >= start) {
                start = lastSeen[s[i]] + 1;
            }
            lastSeen[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};