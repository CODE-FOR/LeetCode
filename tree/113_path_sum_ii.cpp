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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return vector<vector<int>>();
        }
        vector<vector<int>> leftRes;
        vector<vector<int>> rightRes;
        if (!root->right && !root->left) {
            if (root->val == targetSum) {
                vector<int> tmp = vector<int>({root->val});
                leftRes.push_back(tmp);
                return leftRes;
            } else {
                return vector<vector<int>>();
            }
        }
        if (root->left) {
            leftRes = pathSum(root->left, targetSum - root->val);
            for (auto& path : leftRes) {
                path.insert(path.begin(), root->val);
            }
        }
        if (root->right) {
            rightRes = pathSum(root->right, targetSum - root->val);
            for (auto& path : rightRes) {
                path.insert(path.begin(), root->val);
            }
        }
        leftRes.insert(leftRes.end(), rightRes.begin(), rightRes.end());
        return leftRes;
    }
};