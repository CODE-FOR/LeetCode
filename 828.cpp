#include <iostream>


using namespace std;


class Solution {
private:
    int cur[26];
    int last[26];
    int res = 0;

public:
    int uniqueLetterString(string s) {
        for (int position = 0; position < s.length(); position++) {
            int this_char = s.at(position) - 'A';
            int real_position_from_one = position + 1;
            if (cur[this_char] == 0) {
                cur[this_char] = real_position_from_one;
                continue;
            }
            res += (cur[this_char] - last[this_char]) * (real_position_from_one - cur[this_char]);
            last[this_char] = cur[this_char];
            cur[this_char] = real_position_from_one;
        }
        for (int i = 0; i < 26; i++) {
            if (cur[i] == 0) {
                continue;
            }
            res += (cur[i] - last[i]) * (s.length() + 1 - cur[i]);
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    int res = s->uniqueLetterString("ABA");
    cout << res << endl;
    delete s;
    return 0;
}