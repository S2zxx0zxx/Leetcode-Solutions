class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> p2w;
        unordered_map<string,char> w2p;
        
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) words.push_back(word);
        
        if (pattern.size() != words.size()) return false;
        
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            if (p2w.count(c) && p2w[c] != w) return false;
            if (w2p.count(w) && w2p[w] != c) return false;
            
            p2w[c] = w;
            w2p[w] = c;
        }
        
        return true;
    }
};