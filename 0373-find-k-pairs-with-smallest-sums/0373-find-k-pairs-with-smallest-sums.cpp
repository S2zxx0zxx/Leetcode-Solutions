class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int m = nums1.size(), n = nums2.size();
        
        auto cmp = [&](pair<int,int>& a, pair<int,int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);
        
        for (int i = 0; i < min(m, k); i++) {
            minHeap.push({i, 0});
        }
        
        while (k-- > 0 && !minHeap.empty()) {
            auto [i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < n) {
                minHeap.push({i, j + 1});
            }
        }
        
        return result;
    }
};