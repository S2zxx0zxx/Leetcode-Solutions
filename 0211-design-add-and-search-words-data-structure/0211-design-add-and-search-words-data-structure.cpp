class WordDictionary {
public:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
private:
    bool dfs(string& word, int idx, TrieNode* node) {
        if (idx == word.size()) return node->isEnd;
        
        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && dfs(word, idx + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int i = c - 'a';
            if (!node->children[i]) return false;
            return dfs(word, idx + 1, node->children[i]);
        }
    }
};