#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path_num_map(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                path_num_map[i][j] = path_num_map[i - 1][j] + path_num_map[i][j - 1];
            }
        }
        return path_num_map[m - 1][n - 1];
    }
};