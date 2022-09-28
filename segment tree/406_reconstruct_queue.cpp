#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
private:
    vector<int> segment_tree;

    void build_segment_tree(int n) {
        int bit = 1;
        while(bit < n + 2) {
            bit <<= 1;
        }
        segment_tree = vector<int>(bit << 1, 0);
        for (int i = bit + 1; i <= bit + n; i++) {
            segment_tree[i] = 1;
        }
        for (int i = bit - 1; i; i--) {
            segment_tree[i] = segment_tree[i << 1] + segment_tree[(i << 1) | 1];
        }
    }

    int people_position(int k, int block) {
        int bit = segment_tree.size() >> 1;
        if (block > bit) {
            int position = block - bit - 1;
            while (block) {
                // cout << "block" << block << endl;
                segment_tree[block] -= 1;
                block >>= 1;
            }
            return position;
        }
        if (segment_tree[block << 1] < k) {
            return people_position(k - segment_tree[block << 1], (block << 1) + 1);
        } else {
            return people_position(k, block << 1);
        }
    }


public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& x, vector<int>& y) {
            return (x[0] == y[0]) ? (x[1] > y[1]) : x[0] < y[0];
        });
        build_segment_tree(people.size());
        vector<vector<int>> res = vector<vector<int>>(people.size());
        for (auto p: people) {
            // cout << p[0] << " " << p[1] << " " << people_position(p[1] + 1, 1) << endl;
            res[people_position(p[1] + 1, 1)] = p;
        }
        return res;
    }
};