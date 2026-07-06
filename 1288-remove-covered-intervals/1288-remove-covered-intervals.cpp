class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int count = 0, maxEnd = 0;
        for (auto& iv : intervals) {
            if (iv[1] > maxEnd) {
                count++;
                maxEnd = iv[1];
            }
        }
        return count;
    }
};