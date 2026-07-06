class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num < 0) swap(maxProd, minProd);
            maxProd = max(num, maxProd * num);
            minProd = min(num, minProd * num);
            result = max(result, maxProd);
        }
        return result;
    }
};