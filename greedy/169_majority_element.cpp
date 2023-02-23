#include <vector>

using std::vector;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int maj;
        for (int num : nums) {
            if (count == 0) {
                maj = num;
            }
            if (maj == num) {
                count++;
            } else {
                count--;
            }
        }
        return maj;
    }
};