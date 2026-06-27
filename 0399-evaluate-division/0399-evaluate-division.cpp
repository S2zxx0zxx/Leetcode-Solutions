class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            graph[a][b] = values[i];
            graph[b][a] = 1.0 / values[i];
        }
        
        vector<double> result;
        for (auto& q : queries) {
            string src = q[0], dst = q[1];
            if (!graph.count(src) || !graph.count(dst)) {
                result.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                result.push_back(dfs(graph, src, dst, visited));
            }
        }
        
        return result;
    }
    
private:
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, string src, string dst, unordered_set<string>& visited) {
        if (src == dst) return 1.0;
        visited.insert(src);
        
        for (auto& [next, val] : graph[src]) {
            if (!visited.count(next)) {
                double res = dfs(graph, next, dst, visited);
                if (res != -1.0) return val * res;
            }
        }
        
        return -1.0;
    }
};