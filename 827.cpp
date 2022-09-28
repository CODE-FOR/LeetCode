#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>() (pair.first) ^ std::hash<T2>() (pair.second);
    }
};

class Solution {
private:
    int seperate_grid_into_partitions(vector<vector<int>> &grid, int i, int j, int partition, vector<vector<int>> &grid_to_partition) {
        int area = 1;
        grid[i][j] = 2;
        // grid_to_partition[{i, j}] = partition;
        grid_to_partition[i][j] = partition;
        if (i > 0 && grid[i - 1][j] == 1) {
            area += seperate_grid_into_partitions(grid, i - 1, j, partition, grid_to_partition);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
            area += seperate_grid_into_partitions(grid, i + 1, j, partition, grid_to_partition);
        }
        if (j > 0 && grid[i][j - 1] == 1) {
            area += seperate_grid_into_partitions(grid, i, j - 1, partition, grid_to_partition);
        }
        if (j + 1 < grid.size() && grid[i][j + 1] == 1) {
            area += seperate_grid_into_partitions(grid, i, j + 1, partition, grid_to_partition);
        }
        return area;
    }

public:
    // unordered_map<pair<int, int>, int, pair_hash> grid_to_partition;
    int largestIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        vector<int> partition_to_area;
        vector<vector<int>> grid_to_partition(grid.size(), vector<int>(grid.size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 1) {
                    int partition = partition_to_area.size();
                    int area = seperate_grid_into_partitions(grid, i, j, partition, grid_to_partition);
                    if (area > max_area) {
                        max_area = area;
                    }
                    partition_to_area.push_back(area);
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> paritions_around_this_zero;
                    if (i > 0 && grid[i - 1][j] == 2) {
                        // paritions_around_this_zero.insert(grid_to_partition[{i - 1, j}]);
                        paritions_around_this_zero.insert(grid_to_partition[i - 1][j]);
                    }
                    if (i + 1 < grid.size() && grid[i + 1][j] == 2) {
                        // paritions_around_this_zero.insert(grid_to_partition[{i + 1, j}]);
                        paritions_around_this_zero.insert(grid_to_partition[i + 1][j]);
                    }
                    if (j > 0 && grid[i][j - 1] == 2) {
                        paritions_around_this_zero.insert(grid_to_partition[i][j - 1]);
                    }
                    if (j + 1 < grid.size() && grid[i][j + 1] == 2) {
                        // paritions_around_this_zero.insert(grid_to_partition[{i, j + 1}]);
                        paritions_around_this_zero.insert(grid_to_partition[i][j + 1]);
                    }
                    int area = 1;
                    for (int parition : paritions_around_this_zero) {
                        area += partition_to_area[parition];
                    }
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }
        return max_area;
    }
};