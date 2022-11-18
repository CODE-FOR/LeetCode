#include <stack>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;
using std::stack;


class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pattern_match_map = unordered_map<char, char>();
        pattern_match_map[')'] = '(';
        pattern_match_map[']'] = '[';
        pattern_match_map['}'] = '{';
        stack<char> pattern_stack;
        for (auto &c : s) {
            if (pattern_match_map.count(c)) {
                if (pattern_stack.empty() || pattern_stack.top() != pattern_match_map[c]) {
                    return false;
                }
                pattern_stack.pop();
                continue;
            }
            pattern_stack.push(c);
        }
        return pattern_stack.empty();
    }
};