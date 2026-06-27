class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [curr, len] = q.front(); q.pop();
            
            for (int i = 0; i < curr.size(); i++) {
                string next = curr;
                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;
                    if (next == endWord) return len + 1;
                    if (wordSet.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, len + 1});
                    }
                    next[i] = curr[i];
                }
            }
        }
        
        return 0;
    }
};