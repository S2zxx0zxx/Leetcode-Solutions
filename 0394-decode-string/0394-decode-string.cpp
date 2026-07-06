class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string current = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(num);
                strStack.push(current);
                num = 0;
                current = "";
            } else if (c == ']') {
                int count = countStack.top();
                countStack.pop();
                string prev = strStack.top();
                strStack.pop();
                string temp = "";
                for (int i = 0; i < count; i++) {
                    temp += current;
                }
                current = prev + temp;
            } else {
                current += c;
            }
        }
        return current;
    }
};