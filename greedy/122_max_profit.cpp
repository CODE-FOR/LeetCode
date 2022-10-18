#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool is_up = false;
        int up_start = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (!is_up && prices[i] > prices[i - 1]) {
                is_up = true;
                up_start = i - 1;
            }
            if (is_up && prices[i] < prices[i - 1]) {
                is_up = false;
                profit += prices[i - 1] - prices[up_start];
            }
            if (is_up && i + 1 == prices.size()) {
                profit += prices[i] - prices[up_start];
            }
        }
        return profit;
    }
};