#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
        }
        int max_len = 1;
        int begin = 0;
        for (int len = 2; len <= s.length(); len++) {
            for (int left = 0; left + len - 1 < s.length() ; left++) {
                int r = left + len - 1;
                dp[left][r] = s[left] == s[r] ? (len < 3 ? true : dp[left + 1][r - 1]) : false;
                if (dp[left][r] == true) {
                    max_len = max_len > len ? max_len : len;
                    begin = max_len > len ? left: begin;
                }
            }
        }
        return s.substr(begin, max_len);
    }
};