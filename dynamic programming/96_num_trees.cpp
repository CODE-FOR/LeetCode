#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int res[n + 1];
        res[0] = 1;
        for (int i = 1; i <= n; i++) {
            res[i] = 0;
            for (int root = 0; root < i; root++) {
                res[i] += res[root] * res[i - root -1];
            }
        }
        return res[n];
    }
};