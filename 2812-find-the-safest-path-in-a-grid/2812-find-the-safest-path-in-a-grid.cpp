class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        
        // Multi-source BFS: distance from every cell to nearest thief
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        // Max-heap Dijkstra: maximize the minimum dist along the path
        priority_queue<tuple<int,int,int>> pq; // (safeness, r, c)
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({dist[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto [safe, r, c] = pq.top(); pq.pop();
            if (visited[r][c]) continue;
            visited[r][c] = true;
            
            if (r == n - 1 && c == n - 1) return safe;
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.push({min(safe, dist[nr][nc]), nr, nc});
                }
            }
        }
        
        return -1; // unreachable given constraints
    }
};