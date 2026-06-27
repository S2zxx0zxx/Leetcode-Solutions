class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        
        for (int num : numSet) {
            if (!numSet.count(num - 1)) {
                int curr = num, len = 1;
                while (numSet.count(curr + 1)) { curr++; len++; }
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};