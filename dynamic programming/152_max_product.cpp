#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int globalMax = nums[0];
        vector<int> maxProductSubarray(size);
        vector<int> minProductSubarray(size);
        maxProductSubarray[0] = minProductSubarray[0] = nums[0];
        for (int i = 1; i < size; i++) {
            if (nums[i] < 0) {
                maxProductSubarray[i] = minProductSubarray[i - 1] > 1 ? nums[i] : minProductSubarray[i - 1] * nums[i];
                minProductSubarray[i] = maxProductSubarray[i - 1] < 1 ? nums[i] : maxProductSubarray[i - 1] * nums[i];
            } else {
                minProductSubarray[i] = minProductSubarray[i - 1] > 1 ? nums[i] : minProductSubarray[i - 1] * nums[i];
                maxProductSubarray[i] = maxProductSubarray[i - 1] < 1 ? nums[i] : maxProductSubarray[i - 1] * nums[i];
            }
            if (globalMax < maxProductSubarray[i]) {
                globalMax = maxProductSubarray[i];
            }
        }
        return globalMax;
    } 
};