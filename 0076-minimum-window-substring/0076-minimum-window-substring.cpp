class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = need.size();
        int formed = 0;
        unordered_map<char, int> window;

        int left = 0, right = 0;
        int minLen = INT_MAX, minStart = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char lc = s[left];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};