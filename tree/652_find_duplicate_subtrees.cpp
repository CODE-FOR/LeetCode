#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <functional>


using std::size_t;
using std::pair;
using std::hash;
using std::unordered_set;
using std::unordered_map;
using std::tuple;
using std::vector;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {repeted_subtree_type.begin(), repeted_subtree_type.end()};
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        auto tree = tuple{root->val, dfs(root->left), dfs(root->right)};
        if (subtree_type.find(tree) != subtree_type.end()) {
            repeted_subtree_type.insert(subtree_type.find(tree)->second.first);
            return subtree_type.find(tree)->second.second;
        }
        subtree_type[tree] = {root, ++subtree_type_cnt};
        return subtree_type_cnt;
    }

private:
    struct tri_hash {
        size_t operator() (const tuple<int, int, int>& o) const {
            auto hash_int_fn = hash<int>();
            auto&& [x, y, z] = o;
            return (hash_int_fn(x) << 24) ^ (hash_int_fn(y) << 8) ^ hash_int_fn(z);
        }
    };
    

    int subtree_type_cnt = 0;

    unordered_map<tuple<int, int, int>, pair<TreeNode*, int>, tri_hash> subtree_type;
    unordered_set<TreeNode*> repeted_subtree_type;
};