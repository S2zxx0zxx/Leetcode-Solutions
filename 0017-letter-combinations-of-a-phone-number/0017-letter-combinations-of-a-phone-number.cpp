class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string current;
        
        backtrack(digits, 0, current, mapping, result);
        return result;
    }
    
private:
    void backtrack(string& digits, int index, string& current, vector<string>& mapping, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, mapping, result);
            current.pop_back();
        }
    }
};