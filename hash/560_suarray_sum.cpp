#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix_sum = vector<int>(nums.size(), 0);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        unordered_map<int, int> prefix_sum_to_occur_num;
        prefix_sum_to_occur_num[0] = 1;
        int subarray_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (prefix_sum_to_occur_num.count(prefix_sum[i] - k)) {
                subarray_sum += prefix_sum_to_occur_num[prefix_sum[i] - k];
            }
            if (!prefix_sum_to_occur_num.count(prefix_sum[i])) {
                prefix_sum_to_occur_num[prefix_sum[i]] = 0;
            }
            prefix_sum_to_occur_num[prefix_sum[i]]++;
        }
        return subarray_sum;
    }
};