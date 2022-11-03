#include <unordered_set>
#include <vector>


using std::vector;
using std::unordered_set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for (auto num : nums) {
            if (num_set.find(num) != num_set.end()) {
                return true;
            }
            num_set.emplace(num);
        }
        return false;
    }
};