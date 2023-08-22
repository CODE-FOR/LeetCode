struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return false;
        } 
        bool find_in_right_sub = dfs(root->right, p, q);
        bool find_in_left_sub = dfs(root->left, p, q);
        if ((find_in_left_sub && find_in_right_sub) || ((root == p || root == q) && (find_in_left_sub || find_in_right_sub))) {
            res = root;
        }
        return find_in_left_sub | find_in_right_sub | root == p | root == q;
    }

private:
    TreeNode* res = nullptr;
};