#include <vector>
#include <string>

using std::string;
using std::vector;
using std::stoi;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores = vector<int> ();
        for (auto &operation : operations) {
            if (operation == "+") {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            } else if (operation == "D") {
                scores.push_back(scores[scores.size() - 1] * 2);
            } else if (operation == "C") {
                scores.erase(scores.begin() + scores.size() - 1);
            } else {
                scores.push_back(stoi(operation));
            }
        }
        int score_sum = 0;
        for (auto &score : scores) {
            score_sum += score;
        }
        return score_sum;
    }
};