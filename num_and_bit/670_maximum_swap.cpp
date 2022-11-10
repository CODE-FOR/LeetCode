#include <vector>
#include <algorithm>

using std::vector;
using std::iter_swap;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> each_num;
        int tmp_num = num;
        while (tmp_num > 0) {
            each_num.push_back(tmp_num % 10);
            tmp_num /= 10;
        }
        int swap_first = 0, swap_second = 0;
        int max = 0;
        int max_pos = 0;
        for (int i = 0; i < each_num.size(); i++) {
            if (each_num[i] > max) {
                max = each_num[i];
                max_pos = i;
            } else if (each_num[i] == max) {
                continue;
            } else {
                swap_first = i;
                swap_second = max_pos;
            }
        }
        iter_swap(each_num.begin() + swap_first, each_num.begin() + swap_second);
        tmp_num = 0;
        for (int i = each_num.size() - 1; i >= 0; i--) {
            tmp_num *= 10;
            tmp_num += each_num[i];
        }
        return tmp_num;
    }
};