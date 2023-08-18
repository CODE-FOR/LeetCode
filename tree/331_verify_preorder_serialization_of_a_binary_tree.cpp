#include <string>

using std::string;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int cnt = 1;
        int pos = 0;
        while (pos < preorder.size()) {
            if (cnt <= 0) {
                return false;
            }
            if (preorder[pos] == '#') {
                cnt--;
            } else if (preorder[pos] != ',') {
                while (pos < preorder.size() && preorder[pos] != ',') {
                    pos++;
                }
                cnt++;
            }
            pos++;
        }
        return cnt == 0;
    }
};