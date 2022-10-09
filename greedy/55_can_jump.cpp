#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>

using namespace std;


// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int now_last = nums.size();
//         bool renew = true;
//         while (renew) {
//             renew = false;
//             for (int i = 0; i < now_last - 1; i++) {
//                 if (i + 1 + nums[i] >= now_last) {
//                     now_last = i + 1;
//                     renew = true;
//                     break;
//                 }
//             }
//         }
//         return now_last <= 1;
//     }
// };

class Solution {
    public:
    bool canJump(vector<int>& nums) {
        int now_bondary = 0;
        int start = 0;
        while (start <= now_bondary) {
            now_bondary = max(now_bondary, start + nums[start]);
            start++;
            if (now_bondary >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};