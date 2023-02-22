#include <vector>

using std::vector;

#define max(x, y) (((x) > (y)) ? (x) : (y))

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max_price_in_the_future(prices.size(), 0);
        int max_profit = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            max_price_in_the_future[i] = max(max_price_in_the_future[i + 1], prices[i + 1]);
            max_profit = max(max_profit, max_price_in_the_future[i] - prices[i]);
        }
        return max_profit;
    }
};