#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:

    bool dfs(vector<int> &nums, vector<bool> &dp, int state, int cur_sum, int per) {
        if (state == 0) {
            return true;
        }
        if (!dp[state]) {
            return false;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (cur_sum + nums[i] > per) {
                dp[state] = false;
                return false;
            }
            if ((state >> i) & 1 && dfs(nums, dp, state ^ (1 << i), (cur_sum + nums[i]) % per, per)) {
                // dp[state] = true;
                return true;
            } 
        }
        dp[state] = false;
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        vector<int> used = vector<int>(nums.size(), 0);
        for (int num : nums) {
            sum += num;
        }
        if (sum % k) {
            return false;
        }
        int per = sum / k;
        if (nums[0] > per) {
            return false;
        }
        vector<bool> dp = vector<bool>(1 << nums.size(), true);
        return dfs(nums, dp, (1 << int(nums.size())) - 1, 0, per);
    }
};