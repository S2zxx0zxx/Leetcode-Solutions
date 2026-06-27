class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;
        
        auto getCoords = [&](int num) -> pair<int,int> {
            int pos = num - 1;
            int row = pos / n;
            int col = pos % n;
            int r = n - 1 - row;
            int c = (row % 2 == 0) ? col : n - 1 - col;
            return {r, c};
        };
        
        vector<bool> visited(target + 1, false);
        queue<pair<int,int>> q;
        q.push({1, 0});
        visited[1] = true;
        
        while (!q.empty()) {
            auto [curr, moves] = q.front(); q.pop();
            
            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;
                if (next > target) break;
                
                auto [r, c] = getCoords(next);
                if (board[r][c] != -1) next = board[r][c];
                
                if (next == target) return moves + 1;
                
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        
        return -1;
    }
};