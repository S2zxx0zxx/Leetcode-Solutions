class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        vector<string> stack;
        string token;
        
        while (getline(iss, token, '/')) {
            if (token == "" || token == ".") continue;
            else if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }
        
        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i + 1 < stack.size()) result += "/";
        }
        
        return result;
    }
};