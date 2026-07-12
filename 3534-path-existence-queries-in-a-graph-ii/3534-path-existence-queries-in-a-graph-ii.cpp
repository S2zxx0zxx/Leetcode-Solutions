class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums[a] < nums[b]; });
        
        vector<int> pos(n), sorted(n);
        for (int i = 0; i < n; i++) { pos[idx[i]] = i; sorted[i] = nums[idx[i]]; }
        
        vector<int> comp(n);
        int c = 0; comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (sorted[i] - sorted[i-1] > maxDiff) c++;
            comp[i] = c;
        }
        
        // nxt[i] = farthest position reachable in one step from i (largest j with sorted[j]-sorted[i] <= maxDiff)
        int LOG = 1; while ((1 << LOG) < n) LOG++; LOG++;
        vector<vector<int>> up(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int lo = i, hi = n - 1, res = i;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (sorted[mid] - sorted[i] <= maxDiff) { res = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            up[0][i] = res;
        }
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k-1][up[k-1][i]];
        
        vector<int> ans;
        for (auto &q : queries) {
            int pu = pos[q[0]], pv = pos[q[1]];
            if (pu > pv) swap(pu, pv);
            if (pu == pv) { ans.push_back(0); continue; }
            if (comp[pu] != comp[pv]) { ans.push_back(-1); continue; }
            int cur = pu, steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < pv) { cur = up[k][cur]; steps += (1 << k); }
            }
            ans.push_back(steps + 1);
        }
        return ans;
    }
};