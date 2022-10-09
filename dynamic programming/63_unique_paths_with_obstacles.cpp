#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> path_num_map(m, vector<int>(n, 0));
        path_num_map[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < m; i++) {
            path_num_map[i][0] = path_num_map[i - 1][0] * (1 - obstacleGrid[i][0]);
        }
        for (int i = 1; i < n; i++) {
            path_num_map[0][i] = path_num_map[0][i - 1] * (1 - obstacleGrid[0][i]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                path_num_map[i][j] = (path_num_map[i - 1][j] + path_num_map[i][j - 1]) * (1 - obstacleGrid[i][j]);
            }
        }
        return path_num_map[m - 1][n - 1];
    }
};