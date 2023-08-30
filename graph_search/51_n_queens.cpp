#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        visited = vector<vector<int>>(n, vector<int>(n, 0));
        solveNQueens(n, 0);
        return res;
    }


    void solveNQueens(int n, int dep) {
        if (n == dep) {
            res.push_back(posList);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[dep][i]) {
                continue;
            }
            posList.push_back(calcString(i, n));
            for (int j = dep + 1; j < n; j++) {
                visited[j][i]++;
                if (i + j - dep < n) {
                    visited[j][i + j - dep]++;
                }
                if (i - j + dep >= 0) {
                    visited[j][i - j + dep]++;
                }
            }
            solveNQueens(n, dep + 1);
            posList.pop_back();
            for (int j = dep + 1; j < n; j++) {
                visited[j][i]--;
                if (i + j - dep < n) {
                    visited[j][i + j - dep]--;
                }
                if (i - j + dep >= 0) {
                    visited[j][i - j + dep]--;
                }
            }
        }
    }

    string calcString(int pos, int n) {
        stringstream ss;
        for (int i = 0; i < pos; i++) {
            ss << '.';
        }
        ss << 'Q';
        for (int i = pos + 1; i < n; i++) {
            ss << '.';
        }
        return ss.str();
    }

    vector<vector<int>> visited;
    vector<vector<string>> res;
    vector<string> posList;
};

int main() {
    Solution* s = new Solution();
    s->solveNQueens(4);
    return 0;
}