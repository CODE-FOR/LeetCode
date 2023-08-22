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
    int maxDiameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        depthOfBinaryTree(root);
        return maxDiameter;
    }

    int depthOfBinaryTree(TreeNode* root) {
        if (!root->left && !root->right) {
            return 0;
        } else if (!root->left) {
            int rightDepth = depthOfBinaryTree(root->right);
            maxDiameter = max(maxDiameter, rightDepth + 1);
            return rightDepth + 1;
        } else if (!root->right) {
            int leftDepth = depthOfBinaryTree(root->left);
            maxDiameter = max(maxDiameter, leftDepth + 1);
            return leftDepth + 1;
        } else {
            int rightDepth = depthOfBinaryTree(root->right);
            int leftDepth = depthOfBinaryTree(root->left);
            maxDiameter = max(maxDiameter, leftDepth + rightDepth + 2);
            return max(rightDepth, leftDepth) + 1;
        }
    }
};