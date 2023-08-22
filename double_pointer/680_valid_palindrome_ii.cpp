#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool validPalindrome(string s) {
        bool is_left_deleted = false;
        bool is_right_deleted = false;
        int left = 0;
        int right = s.size() - 1;
        int delete_paused_left = 0;
        int delete_paused_right = 0;
        while (left < right) {
            if (s.at(left) == s.at(right)) {
                left++;
                right--;
            } else if (!is_left_deleted) {
                delete_paused_left = left;
                delete_paused_right = right - 1;
                left++;
                is_left_deleted = true;
            } else if (!is_right_deleted) {
                left = delete_paused_left;
                right = delete_paused_right;
                is_right_deleted = true;
            } else {
                break;
            }
        }
        return left >= right;
    }
};