#include <cmath>

using std::sqrt;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int factor_sum = 1;
        int i = 0;
        if (num == 1) {
            return false;
        }
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                factor_sum += i + num / i;
            }
        }
        if (i * i == num) {
            factor_sum -= i;
        }
        return factor_sum == num;
    }
};