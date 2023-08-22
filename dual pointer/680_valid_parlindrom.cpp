#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                break;
            }
            start ++;
            end--;
        }
        // whether start >= end, then return true
        // or s[start] != s[end] & start < end, should test delete.
        //     1. delete start 
        //     2. delete end
        if (start >= end) {
            return true;
        }
        return is_parlindrom(s, start + 1, end) | is_parlindrom(s, start, end - 1);
    }

    bool is_parlindrom(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                break;
            }
            start ++;
            end--;
        }
        if (start >= end) {
            return true;
        }
        return false;
    }
};