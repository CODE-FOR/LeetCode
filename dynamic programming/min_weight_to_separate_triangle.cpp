#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;
const int INT_MAX = (-1) ^ (1 << 31);
const int N = 8;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};


unordered_set<pair<int, int>, pair_hash> trace_back (int i, int j, vector<vector<int>>& separate_point, unordered_set<pair<int, int>, pair_hash>& t) {
    if (j - i < 2) {
        return t;
    }
    int k = separate_point[i][j];
    if (k - i > 1){
        t.emplace(i, k);
        trace_back(i, k, separate_point, t);
    }
    if (j - k > 1) {
        t.emplace(k, j);
        trace_back(k, j, separate_point, t);
    }
    return t;
}


unordered_set<pair<int, int>, pair_hash> min_weight_triangle_split(vector<vector<int>>& w) {
    vector<vector<int>> separate_point(N, vector<int>(N, 0));
    vector<vector<int>> min_weight(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N - 1; i++) {
        min_weight[i][i] = 0;
        min_weight[i][i + 1] = 0;
    }
    min_weight[N - 1][N - 1] = 0;
    unordered_set<pair<int, int>, pair_hash> t;
    for (int size = 2; size < N; size++) {
        for (int i = 0; i < N - size; i++) {
            int j = i + size;
            for (int k = i + 1; k < j; k++) {
                if (min_weight[i][j] > min_weight[i][k] + min_weight[k][j] + w[i][k] + w[k][j] + w[i][j]) {
                    min_weight[i][j] = min_weight[i][k] + min_weight[k][j] + w[i][k] + w[k][j] + w[i][j];
                    separate_point[i][j] = k;
                }
            }
        }
    }
    cout << "min_weight_to_separate_triangle: " << min_weight[0][N - 1] << endl;
    return trace_back(0, N - 1, separate_point, t);
}


int main() {
    vector<vector<int>> w = {
	{ 0,14,25,27,10,11,24,16 },
	{ 14,0,18,15,27,28,16,14 },
	{ 25,18,0,19,14,19,16,10 },
	{ 27,15,19,0,22,23,15,14 },
	{ 10,27,14,22,0,14,13,20 },
	{ 11,28,19,23,14,0,15,18 },
	{ 24,16,16,15,13,15,0,27 },
	{ 16,14,10,14,20,18,27,0 }};

    unordered_set<pair<int, int>, pair_hash> t = min_weight_triangle_split(w);
    cout << "edge set:" << endl;
    for (auto& edge: t) {
        cout << edge.first << "--" << edge.second << endl;
    }
    return 0;
}