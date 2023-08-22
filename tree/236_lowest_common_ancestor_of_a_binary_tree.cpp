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

    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (find_p && find_q) {
            return;
        }

        if (!root) {
            return;
        }
        
        bool find_p_now = find_p, find_q_now = find_q;
        dfs(root->left, p, q);
        if (find_p && find_q) {
            return;
        }
        bool find_p_after_left = find_p, find_q_after_left = find_q;
        find_p = find_p_now, find_q = find_q_now;
        dfs(root->right, p, q);
        if (find_p && find_q) {
            return;
        }
        find_p = find_p_after_left | find_p;
        find_q = find_q_after_left | find_q;
        if (root == p) {
            find_p = true;
        } else if (root == q) {
            find_q = true;
        }
        if (find_p && find_q) {
            res = root;
        }
    }

private:
    bool find_p = false;
    bool find_q = false;
    TreeNode* res = nullptr;
};