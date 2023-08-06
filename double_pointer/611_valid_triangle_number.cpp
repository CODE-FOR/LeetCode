#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int numsSize = nums.size();
        std::sort(nums.begin(), nums.end());
        int longgestVec = 2;
        int triangleNum = 0;
        while (longgestVec < numsSize) {
            int middleVec = longgestVec - 1;
            int shorttestVec = 0;
            while (shorttestVec < middleVec) {
                if (nums[shorttestVec] + nums[middleVec] > nums[longgestVec]) {
                    triangleNum += middleVec - shorttestVec;
                    middleVec--;
                } else {
                    shorttestVec++;
                }
            }
            longgestVec++;
        }
        return triangleNum;
    }
};