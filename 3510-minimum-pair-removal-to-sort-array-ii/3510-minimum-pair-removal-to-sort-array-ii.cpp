class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        vector<long long> val(n);
        vector<int> prevIdx(n), nextIdx(n);
        for (int i = 0; i < n; i++) {
            val[i] = nums[i];
            prevIdx[i] = i - 1;
            nextIdx[i] = (i + 1 < n) ? i + 1 : -1;
        }
        
        set<pair<long long,int>> pq; // (sum, left index) for every adjacent pair
        int badCount = 0; // number of adjacent pairs where val[i] > val[next]
        
        for (int i = 0; i != -1; i = nextIdx[i]) {
            int j = nextIdx[i];
            if (j != -1) {
                pq.insert({val[i] + val[j], i});
                if (val[i] > val[j]) badCount++;
            }
        }
        
        int ops = 0;
        while (badCount > 0) {
            auto it = pq.begin();
            long long sum = it->first;
            int i = it->second;
            pq.erase(it);
            
            int j = nextIdx[i];
            int p = prevIdx[i];
            int q = nextIdx[j];
            
            // remove this pair's contribution to badCount
            if (val[i] > val[j]) badCount--;
            
            // remove neighboring pairs (p,i) and (j,q) from pq and badCount
            if (p != -1) {
                pq.erase({val[p] + val[i], p});
                if (val[p] > val[i]) badCount--;
            }
            if (q != -1) {
                pq.erase({val[j] + val[q], j});
                if (val[j] > val[q]) badCount--;
            }
            
            // merge j into i
            val[i] = val[i] + val[j];
            nextIdx[i] = q;
            if (q != -1) prevIdx[q] = i;
            
            // add back new pairs
            if (p != -1) {
                pq.insert({val[p] + val[i], p});
                if (val[p] > val[i]) badCount++;
            }
            if (q != -1) {
                pq.insert({val[i] + val[q], i});
                if (val[i] > val[q]) badCount++;
            }
            
            ops++;
        }
        
        return ops;
    }
};