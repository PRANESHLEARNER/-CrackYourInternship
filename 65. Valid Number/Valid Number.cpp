class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        unordered_map<int, unordered_map<int, int>> transfer{
            {0, {{' ', 0}, {'s', 1}, {'d', 2}, {'.', 4}}},
            {1, {{'d', 2}, {'.', 4}}},
            {2, {{'d', 2}, {'.', 3}, {'e', 5}, {' ', 8}}},
            {3, {{'d', 3}, {'e', 5}, {' ', 8}}},
            {4, {{'d', 3}}},
            {5, {{'s', 6}, {'d', 7}}},
            {6, {{'d', 7}}},
            {7, {{'d', 7}, {' ', 8}}},
            {8, {{' ', 8}}}
        };
        for (char c : s) {
            int id;
            if (c >= '0' && c <= '9') id = 'd';
            else if (c == '+' || c == '-') id = 's';
            else if (c == 'e' || c == 'E') id = 'e';
            else if (c == '.' || c == ' ') id = c;
            else id = '?';
            if (!transfer[state].count(id)) return false;
            state = transfer[state][id];
        }
        return state == 2 || state == 3 || state == 7 || state == 8;
    }
};