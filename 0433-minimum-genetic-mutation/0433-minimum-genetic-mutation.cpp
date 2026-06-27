class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene)) return -1;
        
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({startGene, 0});
        visited.insert(startGene);
        
        string genes = "ACGT";
        
        while (!q.empty()) {
            auto [curr, moves] = q.front(); q.pop();
            
            for (int i = 0; i < 8; i++) {
                for (char c : genes) {
                    string next = curr;
                    next[i] = c;
                    
                    if (next == endGene) return moves + 1;
                    
                    if (bankSet.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, moves + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};