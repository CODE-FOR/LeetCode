#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>


using std::unordered_map;
using std::vector;
using std::string;
using std::unordered_set;

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> strs = split(s, " ");
        unordered_map<char, string> pattern_char_to_string;
        unordered_set<string> string_set;
        if (strs.size() != pattern.size()) 
            return false;
        for (int i = 0; i < strs.size(); i++) {
            if (!pattern_char_to_string.count(pattern.at(i))) {
                if (string_set.count(strs[i])) {
                    return false;
                }
                string_set.emplace(strs[i]);
                pattern_char_to_string[pattern.at(i)] = strs[i];
            } else {
                if (pattern_char_to_string[pattern.at(i)] != strs[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};