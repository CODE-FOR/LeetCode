#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
    return a > b ? b : a;
}

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int min_len = nums.size() + 1;
        while (right < nums.size()) {
            sum += nums[right];
            right++;
            while (sum >= target) {
                min_len = min(right - left, min_len);
                sum -= nums[left];
                left++;                
            }
        }
        return min_len > nums.size() ? 0 : min_len;
    }
};