class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.size();
        int numWords = words.size();
        int wordLen = words[0].size();
        int totalLen = numWords * wordLen;
        
        if (n < totalLen) return result;
        
        unordered_map<string, int> wordCount;
        for (string& w : words) wordCount[w]++;
        
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> window;
            
            for (int j = i; j + wordLen <= n; j += wordLen) {
                string w = s.substr(j, wordLen);
                
                if (wordCount.find(w) != wordCount.end()) {
                    window[w]++;
                    count++;
                    
                    while (window[w] > wordCount[w]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    
                    if (count == numWords) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        
        return result;
    }
};