#include <vector>

using std::vector;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        vector<int> remainder;
        if (b[0] == 0) {
            return 1;
        }
        int tmp = a % 1337;
        remainder.push_back(tmp);
        tmp = (tmp * (a % 1337)) % 1337;
        while (tmp != remainder[0]) {
            remainder.push_back(tmp);
            tmp = (tmp * (a % 1337)) % 1337;
        }
        int rerender_length = remainder.size();
        int b_cast_in_remainder = 0;
        for (int i = 0; i < b.size(); i++) {
            b_cast_in_remainder *= 10;
            b_cast_in_remainder += b[i];
            if (b_cast_in_remainder >= rerender_length) {
                b_cast_in_remainder %= rerender_length;
            }
        }
        if (b_cast_in_remainder == 0) {
            return remainder[remainder.size() - 1];
        }
        return remainder[b_cast_in_remainder - 1];
    }
};