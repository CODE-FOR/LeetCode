class Solution {
public:
    int findComplement(int num) {
        unsigned int power_of_two_greater_than_num = 1;
        while (power_of_two_greater_than_num <= (unsigned int)num) {
            power_of_two_greater_than_num <<= 1;
        }
        return num ^ (power_of_two_greater_than_num - 1);
    }
};