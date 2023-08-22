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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return val;
    }

    int dfs(TreeNode* root, int k) {
        if (!root) {
            return k;
        }
        k = dfs(root->left, k);
        if (k <= 0) {
            return 0;
        }
        if (k == 1) {
            val = root->val;
            return 0;
        }
        k = dfs(root->right, --k);
        return k;
    }

private:
    int val;
};