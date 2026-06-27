class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s2t, t2s;
        
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            if (s2t.count(a) && s2t[a] != b) return false;
            if (t2s.count(b) && t2s[b] != a) return false;
            s2t[a] = b;
            t2s[b] = a;
        }
        
        return true;
    }
};