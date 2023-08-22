#include <vector>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode *> nodePerLevel;
        vector<int> valPerLevel;
        vector<TreeNode *>tmp;
        vector<vector<int>> resLevelOrder;
        if (root == nullptr) {
            return resLevelOrder;
        }
        nodePerLevel.push_back(root);
        while(!nodePerLevel.empty()) {
            for (auto& node : nodePerLevel) {
                valPerLevel.push_back(node->val);
                if (node->left) {
                    tmp.push_back(node->left);
                }
                if (node->right) {
                    tmp.push_back(node->right);
                }
            }
            nodePerLevel = tmp;
            tmp.clear();
            resLevelOrder.push_back(valPerLevel);
            valPerLevel.clear();
        }
        return resLevelOrder;
    }
};