#include <vector>
#include <algorithm>
#include <iostream>

using std::max;
using std::cout;
using std::endl;
using std::vector;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int write_pos = m + n -1;
        while (write_pos >= 0) {
            if (m == 0) {
                nums1[write_pos] = nums2[n - 1];
                n--;
            } else if (n == 0) {
                nums1[write_pos] = nums1[m - 1];
                m--;
            } else {
                nums1[write_pos] = max(nums2[n - 1], nums1[m - 1]);
                if (nums2[n - 1] > nums1[m - 1]) {
                    n--;
                } else {
                    m--;
                }
            }
            write_pos--;
        }
    }
};


int main() {
    Solution *s = new Solution();
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {4, 5, 6};
    int m = 6, n = 3;
    s->merge(nums1, m, nums2, n);
    return 0;
}