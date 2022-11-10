class Solution {
public:
    bool isPalindrome(int x) {
        int rec = x;
        long long reversed = 0;
        while (x > 0) {
            reversed *= 10;
            reversed += x % 10;
            x /= 10;
        }
        return reversed == rec;
    }
};