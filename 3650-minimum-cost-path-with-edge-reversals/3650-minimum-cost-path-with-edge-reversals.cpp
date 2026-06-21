class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,long long>>> adj(n), radj(n);
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            radj[v].push_back({u, (long long)2 * w}); // from v, reverse edge u->v to go v->u
        }
        
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        
        dist[0] = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (auto& [v, w] : adj[u]) {
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
            
            // switch at u: use ONE incoming edge reversed, independently usable every time we're at u
            for (auto& [v, w] : radj[u]) {
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        
        return dist[n-1] == LLONG_MAX ? -1 : (int)dist[n-1];
    }
};