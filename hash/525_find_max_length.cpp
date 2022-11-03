#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> goal_difference = vector<int>(nums.size(), 0);
        goal_difference[0] = nums[0] == 1 ? 1 : -1;
        for (int i = 1; i < nums.size(); i++) {
            goal_difference[i] = goal_difference[i - 1] + (nums[i] == 1 ? 1 : -1);
        }
        /// @brief record the earlyest;
        unordered_map<int, int> goal_difference_to_occur_position;
        goal_difference_to_occur_position[0] = -1;
        int longest_subarray = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (goal_difference_to_occur_position.count(goal_difference[i])) {
                longest_subarray = longest_subarray > i - goal_difference_to_occur_position[goal_difference[i]] ? 
                                    longest_subarray : i - goal_difference_to_occur_position[goal_difference[i]];
            }
            else
                goal_difference_to_occur_position[goal_difference[i]] = i;
        }
        return longest_subarray;
    }
};