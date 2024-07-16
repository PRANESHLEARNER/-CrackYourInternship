class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;
            else if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } else stack.push_back(token);
        }
        string result = "";
        for (auto& dir : stack) result += "/" + dir;
        return result.empty() ? "/" : result;
    }
};