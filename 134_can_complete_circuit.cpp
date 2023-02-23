#include <vector>

using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_left = 0;
        int start_index = 0;
        int total_gas_minus_total_cost = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_gas_minus_total_cost += gas[i] - cost[i];
            gas_left += gas[i] - cost[i];
            if (gas_left < 0) {
                gas_left = 0;
                start_index = i + 1;
            }
        }
        if (total_gas_minus_total_cost < 0) {
            return -1;
        }
        return start_index;
    }
};