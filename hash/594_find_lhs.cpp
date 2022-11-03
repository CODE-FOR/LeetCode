#include <map>
#include <vector>

using std::vector;
using std::map;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> num_count;
        for (auto num : nums) {
            if (!num_count.count(num)) {
                num_count[num] = 0;
            }
            num_count[num]++;
        }
        // make sure now last_num not equal smallest plus one.
        int last_num = nums[0];
        int last_count = 0;
        int longest_sub = 0;
        for (auto num_and_count : num_count) {
            int sub = 0;
            if (num_and_count.first == last_num + 1) {
                sub += last_count + num_and_count.second;
                longest_sub = longest_sub > sub ? longest_sub : sub;
            }
            last_count = num_and_count.second;
            last_num = num_and_count.first;
        }
        return longest_sub;
    }
};