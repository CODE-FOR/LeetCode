#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <set>
#include <math.h>

using std::priority_queue;
using std::unordered_map;
using std::vector;
using std::set;
using namespace std;


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int size = nums.size();
        set<long> rec;
        for (int i = 0; i < size; i++) {
            auto iter = rec.lower_bound((long)nums[i] - valueDiff);
            if (iter != rec.end() && *iter <= (long)nums[i] + valueDiff) {
                return true;
            }
            rec.insert(nums[i]);
            if (i >= indexDiff) {
                rec.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};


int main() {
    Solution s = Solution();
    vector<int> input = vector({1,5,9,1,5,9});
    s.containsNearbyAlmostDuplicate(input, 2, 3);
}