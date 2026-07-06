class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n) return {};

        vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) pCount[c - 'a']++;

        vector<int> result;

        for (int i = 0; i < n; i++) {
            sCount[s[i] - 'a']++;

            if (i >= m) {
                sCount[s[i - m] - 'a']--;
            }

            if (i >= m - 1 && sCount == pCount) {
                result.push_back(i - m + 1);
            }
        }
        return result;
    }
};