#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total_nums = nums.size();
        int i = 0;
        while(i < nums.size()) {
            // 如果是连续几个相等的，如果第一个不满足，后面满足肯定是恰好nums[i]=total_nums
            // 因此不需要下面注释掉的代码
            if (nums[i] >= total_nums) {
                if (i == 0) {
                    return total_nums;
                }
                else if (nums[i - 1] < total_nums) {
                    return total_nums;
                }
            }
            // if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {    
            //     i++;
            //     continue;
            // }
            i++;
            total_nums = nums.size() - i;
        }
        return -1;
    }
};