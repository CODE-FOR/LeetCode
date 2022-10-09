#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


class Solution {
vector<int> nums;
vector<int> merged;

public:
    int reversePairs(vector<int> &nums) {
        this->nums = nums;
        this->merged = vector<int>(nums.size());
        return reverse_pairs(0, nums.size() - 1);
    }

    int reverse_pairs(int l, int r) {
        if (l == r) {
            return 0;
        }
        int num = 0;
        int mid = (l + r) >> 1;
        num += reverse_pairs(l, mid);
        num += reverse_pairs(mid + 1, r);
        int left_point = l;
        int right_point = mid + 1;
        while (left_point <= mid && right_point <= r) {
            long long tmp_num = nums[right_point];
            if (tmp_num * 2 < nums[left_point]) {
                num += mid - left_point + 1;
                right_point++;
            } else {
                left_point++;
            }
        }
        (r-l+1);
        left_point = l;
        right_point = mid + 1;
        int pos = 0;
        while (left_point <= mid && right_point <= r) {
            if (nums[right_point] < nums[left_point]) {
                merged[pos++] = (nums[right_point]);
                right_point++;
            } else {
                merged[pos++] = (nums[left_point]);
                left_point++;
            }
        }
        while (left_point <= mid) {
            merged[pos++] = (nums[left_point]);
            left_point++;
        }
        while (right_point <= r) {
            merged[pos++] = (nums[right_point]);
            right_point++;
        }
        for (int i = l; i <= r; i++) {
            nums[i] = merged[i - l];
        }
        return num;
    }
};