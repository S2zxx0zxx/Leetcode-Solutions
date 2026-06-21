class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        for (int i = 1; i < m; i++) {
            int diff = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + diff);
        }
        
        for (int i = m - 2; i >= 0; i--) {
            int diff = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + diff);
        }
        
        int result = 0;
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            int sumH = restrictions[i][1] + restrictions[i - 1][1];
            int peak = (dist + sumH) / 2;
            result = max(result, peak);
        }
        
        return result;
    }
};