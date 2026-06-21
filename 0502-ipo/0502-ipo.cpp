class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxHeap;
        int idx = 0;
        
        for (int i = 0; i < k; i++) {
            while (idx < n && projects[idx].first <= w) {
                maxHeap.push(projects[idx].second);
                idx++;
            }
            
            if (maxHeap.empty()) break;
            
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};