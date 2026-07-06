class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            if (prefixCount.count(sum - k)) {
                count += prefixCount[sum - k];
            }
            prefixCount[sum] = prefixCount.count(sum) ? prefixCount[sum] + 1 : 1;
        }
        return count;
    }
};