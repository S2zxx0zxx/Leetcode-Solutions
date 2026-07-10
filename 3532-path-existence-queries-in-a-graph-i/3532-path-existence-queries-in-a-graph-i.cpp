class Solution {
public:
    vector<int> par;
    int find(int x){ return par[x]==x?x:par[x]=find(par[x]); }
    void unite(int a,int b){ a=find(a);b=find(b); if(a!=b) par[a]=b; }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
        for(int i=1;i<n;i++) if(nums[i]-nums[i-1]<=maxDiff) unite(i,i-1);
        vector<bool> ans;
        for(auto&q:queries) ans.push_back(find(q[0])==find(q[1]));
        return ans;
    }
};