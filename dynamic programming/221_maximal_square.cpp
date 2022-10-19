#include <iostream>
#include <vector>

using namespace std;
// my dp version
// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> static_column_continous_num(m, vector<int>(n));
//         int global_max = 0;
//         for (int j = 0; j < n; j++) {
//             static_column_continous_num[0][j] = (matrix[0][j] == '1');
//         }
//         for (int i = 1; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 static_column_continous_num[i][j] = (matrix[i][j] == '0' ? 0 : static_column_continous_num[i - 1][j] + 1);       
//             }
//         }
//         vector<vector<int>> static_row_continous_num(m, vector<int>(n));
//         for (int i = 0; i < m; i++) {
//             static_row_continous_num[i][0] = (matrix[i][0] == '1');
//         }
//         for (int j = 1; j < n; j++) {
//             for (int i = 0; i < m; i++) {
//                 static_row_continous_num[i][j] = (matrix[i][j] == '0' ? 0 : static_row_continous_num[i][j - 1] + 1);
//             }
//         }
        
//         vector<vector<int>> wings(m, vector<int>(n));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 wings[i][j] = min(static_column_continous_num[i][j], static_row_continous_num[i][j]);
//                 global_max = global_max > 0 ? global_max : wings[i][j];
//             }
//         }
//         global_max = global_max ? 1 : 0;
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (wings[i][j] < 2) {
//                     continue;
//                 }
//                 if (wings[i][j] > wings[i - 1][j - 1] + 1) {
//                     wings[i][j] = wings[i - 1][j - 1] + 1;
//                 }
//                 if (wings[i][j] > global_max) {
//                     global_max = wings[i][j];
//                 }
//             }
//         }
//         return global_max * global_max;
//     }
// };


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};
