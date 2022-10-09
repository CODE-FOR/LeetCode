#include <iostream>
#include <vector>


using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int> &nums) {
//         vector<int> dp(nums.size() + 1, 0);
//         int max = nums[0];
//         for (int i = 0; i < nums.size(); i++) {
//             if (dp[i] > 0) {
//                 dp[i + 1] = dp[i] + nums[i];
//             } else {
//                 dp[i + 1] = nums[i];
//             }
//             if (dp[i + 1] > max) {
//                 max = dp[i + 1];
//             } 
//         }
//         return max;
//     }    
// };



/// prefix_sum角度
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> prefix_sum(nums.size() + 1);
        prefix_sum[0] = 0;
        for (int i = 1; i < nums.size() + 1; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
        int min_prefix_sum = 0;
        int max_sub_array = prefix_sum[1];
        for (int i = 1; i < nums.size() + 1; i++) {
            if (prefix_sum[i] - min_prefix_sum > max_sub_array) {
                max_sub_array = prefix_sum[i] - min_prefix_sum;
            }
            if (prefix_sum[i] < min_prefix_sum) {
                min_prefix_sum = prefix_sum[i];
            }
        }
        return max_sub_array;
    }
};