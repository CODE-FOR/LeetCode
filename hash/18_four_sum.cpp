#include <algorithm>
#include <vector>

using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int first_loop_index, second_loop_index;
        int inner_left_pointer, inner_right_pointer;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        int size = nums.size();
        for (first_loop_index = 0; first_loop_index < size; first_loop_index++) {
            if (first_loop_index > 0 && nums[first_loop_index] == nums[first_loop_index - 1]) {
                continue;
            }
            for (second_loop_index = first_loop_index + 1; second_loop_index < size; second_loop_index++) {
                if (second_loop_index > first_loop_index + 1 && nums[second_loop_index] == nums[second_loop_index - 1]) {
                    continue;
                }
                inner_left_pointer = second_loop_index + 1;
                inner_right_pointer = size - 1;
                long long aim_sum = (long long)target - nums[first_loop_index] - nums[second_loop_index];
                while (inner_left_pointer < inner_right_pointer) {
                    long long sum = nums[inner_left_pointer] + nums[inner_right_pointer];
                    if (sum == aim_sum) {
                        vector<int> tmp({nums[first_loop_index], nums[second_loop_index], nums[inner_left_pointer], nums[inner_right_pointer]});
                        res.push_back(tmp);
                        do {
                            inner_left_pointer++;
                        } while(inner_left_pointer < inner_right_pointer && nums[inner_left_pointer] == nums[inner_left_pointer - 1]);
                        do {
                            inner_right_pointer--;
                        } while(inner_left_pointer < inner_right_pointer && nums[inner_right_pointer] == nums[inner_right_pointer + 1]);
                    } else if (sum < aim_sum) {
                        inner_left_pointer++;
                    } else {
                        inner_right_pointer--;
                    }
                }
            }
        }
        return res;
    }
};