#include <iostream>
#include <string>
#include <vector>

using namespace std;


// class Solution {
// public:
//     int numDecodings(string s) {
//         vector<string> substrings;
//         int size = s.size();
//         int start = 0;
//         for (int i = 0; i < size; i++) {
//             if (s[i] - '0' == 0) {
//                 if (i == 0 || s[i - 1] - '0' == 0 || s[i - 1] - '0' > 2) {
//                     return 0;
//                 }
//                 substrings.push_back(s.substr(start, i - start - 1));
//                 start = i + 1;
//             }
//             else if (s[i] - '0' > 2) {
//                 if (i == 0 || s[i - 1] - '0' == 0 || s[i - 1] - '0' > 2 || (s[i] - '0' > 6 && s[i - 1] - '0' > 1)) {
//                     substrings.push_back(s.substr(start, i - start));
//                     start = i + 1;
//                 }
//             }
//         }
//         substrings.push_back(s.substr(start, s.size() - start));
//         int res = 1;
//         for (auto &legal_s: substrings) {
//             res *= decoding_nums_of_a_legal_string(legal_s);
//         }
//         return res;
//     }


//     int decoding_nums_of_a_legal_string(string s) {
//         if (s.size() < 2) {
//             return 1;
//         }
//         int num_n, num_last, num_before_last;
//         num_n = s[s.size() - 2] - '0' > 2 ? 1 : 2;
//         num_last = 1;
//         for (int i = int(s.size()) - 3; i >= 0; i--) {
//             num_before_last = num_last;
//             num_last = num_n;
//             num_n = s[i] - '0' > 2 ? num_last : num_last + num_before_last;
//         }
//         return num_n;
//     }
// };


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // a = f[i-2], b = f[i-1], c = f[i]
        int a = 0, b = 1, c;
        for (int i = 1; i <= n; ++i) {
            c = 0;
            if (s[i - 1] != '0') {
                c += b;
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                c += a;
            }
            a = b;
            b = c;
        }
        return c;
    }
};