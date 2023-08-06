#include <vector>
#include <algorithm>

using std::max;
using std::vector;


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int subArrayLeft = 0;
        int subArrayRight = 1;
        int maxLength = 1;
        while (subArrayRight < nums.size()) {
            if (nums[subArrayRight] > nums[subArrayRight - 1]) {
                subArrayRight++;
            } else {
                maxLength = max(maxLength, subArrayRight - subArrayLeft);
                subArrayLeft = subArrayRight;
                subArrayRight = subArrayLeft + 1;
            }
        }
        maxLength = max(maxLength, subArrayRight - subArrayLeft);
        return maxLength;
    }
};