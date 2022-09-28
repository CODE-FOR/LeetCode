#include <iostream>


using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int first_occur[26] = {0};
        int last_occur[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            last_occur[s[i] - 'a'] = i + 1;
        }
        for (int i = (int)s.size() - 1; i > -1; i--) {
            first_occur[s[i] - 'a'] = i + 1;
        }
        int max = -1;
        for (int i = 0; i < 26; i++) {
            if (last_occur[i] - first_occur[i] - 1 > max) {
                max = last_occur[i] - first_occur[i] - 1;
            }
        }
        return max;
    }
};