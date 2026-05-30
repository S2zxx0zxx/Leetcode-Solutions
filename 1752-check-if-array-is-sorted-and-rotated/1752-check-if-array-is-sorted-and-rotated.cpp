class Solution {
public:
    bool check(vector<int>& nums) {
        int drops = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i+1]) drops++;
        }
        if (nums[n-1] > nums[0]) drops++;
        return drops <= 1;
    }
};