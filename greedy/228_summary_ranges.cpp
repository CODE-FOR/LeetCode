#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.empty()) {
            return ranges;
        }
        // 为了更好的判断结尾部分，dummy_end。
        nums.push_back(nums.back());
        int last_num = nums[0];
        int continuous_length = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (last_num != 2147483647 && num == last_num + 1) {
                continuous_length += 1;
            } else {
                ranges.push_back(continuous_length > 0 ? to_string(last_num - continuous_length) + "->" + to_string(last_num) :
                                                         to_string(last_num));
                continuous_length = 0;
            }
            last_num = num;
        }
        
        return ranges;
    }
};