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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        if (root->left && hasPathSum(root->left, targetSum - root->val)) {
            return true;
        }
        if (root->right && hasPathSum(root->right, targetSum - root->val)) {
            return true;
        }
        if (!root->right && !root->left) {
            return root->val == targetSum;
        }
        return false;
    }
};