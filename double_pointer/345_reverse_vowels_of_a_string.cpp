#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        stringstream res;
        int alphabet_pointer = 0;
        int vowel_pointer = next_vowel(s, int(s.size()) - 1);
        while (alphabet_pointer < s.size()) {
            if (!is_vowel(s[alphabet_pointer])) {
                res << s[alphabet_pointer];
            } else {
                res << s[vowel_pointer];
                vowel_pointer = next_vowel(s, vowel_pointer - 1);
            }
            alphabet_pointer++;
        }
        return res.str();
    }

    bool is_vowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        c = c - 'A' + 'a';
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    int next_vowel(string &s, int pos) {
        while (pos >= 0) {
            if (is_vowel(s[pos])) {
                return pos;
            }
            pos--;
        }
        // -1 means not found
        return -1;
    }
};