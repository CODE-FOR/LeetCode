#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string prefix = "";
        if (digits.size() == 0) {
            return letter_combination;
        }
        letterCombinations(digits, prefix, 0);
        return letter_combination;
    }

private:

    void letterCombinations(string& digits, string prefix, int pos) {
        if (pos == digits.size()) {
            letter_combination.push_back(prefix);
            return;
        }
        vector<char> alphabet = get_digit_to_alphabet(digits[pos] - '0');
        for (auto& c : alphabet) {
            letterCombinations(digits, prefix + c, pos + 1);
        }
    }

    vector<string> letter_combination;

    vector<char> get_digit_to_alphabet(int digit) {
        vector<char> alphabet;
        int start = (digit - 2) * 3 + (digit > 7 ? 1 : 0);
        for (int i = 0; i < 3; i++) {
            alphabet.push_back('a' + start + i);
        }
        if (digit == 7 || digit == 9) {
            alphabet.push_back('a' + start + 3);
        }
        return alphabet;
    }
};