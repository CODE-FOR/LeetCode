class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            if (((left >> i) & 1) != ((right >> i) & 1)) {
                break;
            }
            res += ((left >> i) & 1) << i;
        }
        return res;
    }
};