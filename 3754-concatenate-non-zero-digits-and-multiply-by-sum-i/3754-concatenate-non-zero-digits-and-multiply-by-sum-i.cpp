class Solution {
public:
    long long sumAndMultiply(long long n) {
        string s = to_string(n), t;
        long long sum = 0;
        for (char c : s) if (c != '0') { t += c; sum += c - '0'; }
        long long x = t.empty() ? 0 : stoll(t);
        return x * sum;
    }
};