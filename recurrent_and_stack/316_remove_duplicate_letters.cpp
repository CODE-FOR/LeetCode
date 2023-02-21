#include <string>
#include <stack>

using std::stack;
using std::string;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string buffer;
        int in_buffer[26] = {0}, num[26] = {0};
        for (auto c : s) {
            num[c - 'a']++;
        }
        for (auto c : s) {
            num[c - 'a']--;
            if (in_buffer[c - 'a']) {
                continue;
            }
            while (!buffer.empty() && buffer.back() > c) {
                if (num[buffer.back() - 'a'] > 0) {
                    in_buffer[buffer.back() - 'a'] = 0;
                    buffer.pop_back();
                } else {
                    break;
                }
            }
            in_buffer[c - 'a'] = 1;
            buffer.push_back(c);
        }
        return buffer;
    }
};
