#include <vector>

using std::vector;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> max_integer_break = vector<int>(n + 1);
        max_integer_break[0] = 0;
        max_integer_break[1] = 1;
        max_integer_break[2] = 1;
        for (int i = 3; i <= n; i++) {
            int max = 0;
            for (int sep = 1; sep <= (i >> 1); sep++) {
                int break_l = max_integer_break[sep] > sep ? max_integer_break[sep] : sep;
                int break_r = max_integer_break[i - sep] > i - sep ? max_integer_break[i - sep] : i - sep;
                max = break_l * break_r > max ? break_l * break_r : max;
            }
            max_integer_break[i] = max;
        }
        return max_integer_break[n];
    }
};