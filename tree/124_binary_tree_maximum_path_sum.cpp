#include <algorithm>

using std::max;

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
    int maxPathSum(TreeNode* root) {
        res = root->val;
        pathSumUpperCanUse(root);
        return res;
    }

    int pathSumUpperCanUse(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_max = max(pathSumUpperCanUse(root->left), 0);
        int right_max = max(pathSumUpperCanUse(root->right), 0);
        int max_can_use = max(left_max, right_max);
        if (right_max + left_max + root->val > res) {
            res = right_max + left_max + root->val;
        }
        return max_can_use > 0 ? max_can_use + root->val : root->val;
    }

private:
    int res = -1001;
};