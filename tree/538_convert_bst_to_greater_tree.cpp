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
    TreeNode* convertBST(TreeNode* root) {
        help(root, 0);
        return root;
    }

    int help(TreeNode* root, int val_to_add) {
        if (!root) {
            return val_to_add;
        }
        val_to_add = help(root->right, val_to_add);
        root->val += val_to_add;
        val_to_add = root->val;
        val_to_add = help(root->left, val_to_add);
        return val_to_add;
    }
};