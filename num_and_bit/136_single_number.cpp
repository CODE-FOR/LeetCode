#include <vector>

using std::vector;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int aim_num = 0;
        for (auto &num : nums){
            aim_num ^= num;
        }
        return aim_num;
    }
};