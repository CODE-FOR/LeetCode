class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        }
        int zero_nums = 0;
        int five_power = 5;
        while (five_power <= n) {
            zero_nums += n / (five_power);
            five_power <<= 1;
            five_power += five_power >> 1;
        }
        return zero_nums;
    }
};