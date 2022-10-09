#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
    vector<vector<string>> res;
    vector<string> generateParenthesis(int n) {
        res.push_back(vector<string>({""}));
        res.push_back(vector<string>({"()"}));
        for (int i = 2; i <= n; i++) {
            vector<string> res_i;
            for (int within = 0; within <= i - 1; within++) {
                for (auto &within_pattern: res[within]) {
                    for (auto &out_pattern: res[i - 1 - within]) {
                        res_i.push_back('(' + within_pattern + ')' + out_pattern);
                    }
                }
            }
            res.push_back(res_i);
        }
        return res[n];
    }
};


/// dfs version
// class Solution {
// public:
//     vector<string> res;
//     vector<string> generateParenthesis(int n) {
//         generate(0, "", 0, n);
//         return res;
//     }

//     void generate(int left_patern_num, string tmp_s, int right_pattern_num, int n) {
//         if (right_pattern_num == n) {
//             res.push_back(tmp_s);
//             return;
//         }
//         if (left_patern_num > right_pattern_num) {
//             generate(left_patern_num, tmp_s + ')', right_pattern_num + 1, n);
//         }
//         if (left_patern_num < n) {
//             generate(left_patern_num + 1, tmp_s + '(', right_pattern_num, n);
//         }
//     }
// };