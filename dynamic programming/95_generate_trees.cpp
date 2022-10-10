#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* add_func(TreeNode* origin_tree, int add_num) {
    if (!origin_tree) {
        return origin_tree;
    }
    TreeNode* copyed_tree = new TreeNode(origin_tree->val + add_num);
    if (origin_tree->left) {
        copyed_tree->left = add_func(origin_tree->left, add_num);
    }
    if (origin_tree->right) {
        copyed_tree->right = add_func(origin_tree->right, add_num);
    }
    return copyed_tree;
}

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> res;
        res.push_back(vector<TreeNode*>());
        res[0].push_back(new TreeNode());
        for (int i = 1; i <= n; i++) {
            res.push_back(vector<TreeNode*>());
            for (int root = 0; root < i; root++) {
                for (auto left_sub_tree : res[root]) {
                    left_sub_tree = left_sub_tree->val == 0 ? nullptr : left_sub_tree;
                    for (auto right_sub_tree : res[i - root - 1]) {
                        right_sub_tree = right_sub_tree->val == 0 ? nullptr : right_sub_tree;
                        res[i].push_back(new TreeNode(root + 1, left_sub_tree, add_func(right_sub_tree, root + 1)));
                    }
                }
            }
        }
        return res[n];
    }
};