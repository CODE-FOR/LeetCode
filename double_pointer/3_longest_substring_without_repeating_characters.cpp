#include <string>
#include <algorithm>

using std::max;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alphabet_map[256] = {0};
        int occar_pos[256] = {0};
        int subArrayLeft = 0;
        int subArrayRight = 0;
        int maxLength = 0;
        while (subArrayRight < s.size()) {
            if (alphabet_map[s[subArrayRight]] == 1) {
                maxLength = max(maxLength, subArrayRight - subArrayLeft);
                subArrayLeft = occar_pos[s[subArrayRight]] + 1;
                for (int i = 0; i < 256; i++) {
                    if (occar_pos[i] < subArrayLeft) {
                        alphabet_map[i] = 0;
                    }
                }
            }
            alphabet_map[s[subArrayRight]] = 1;
            occar_pos[s[subArrayRight]] = subArrayRight;
            subArrayRight++;
        }
        maxLength = max(maxLength, subArrayRight - subArrayLeft);
        return maxLength;
    }
};