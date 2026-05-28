class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        string key = s1 + "#" + s2;
        if(memo.count(key)) return memo[key];

        int n = s1.size();
        int freq[26] = {};
        for(int i = 0; i < n; i++) {
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        for(int i = 0; i < 26; i++)
            if(freq[i] != 0) return memo[key] = false;

        for(int i = 1; i < n; i++) {
            // no swap
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) &&
               isScramble(s1.substr(i), s2.substr(i)))
                return memo[key] = true;
            // swap
            if(isScramble(s1.substr(0,i), s2.substr(n-i)) &&
               isScramble(s1.substr(i), s2.substr(0,n-i)))
                return memo[key] = true;
        }
        return memo[key] = false;
    }
};