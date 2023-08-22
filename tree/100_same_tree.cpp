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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return !q && !p;
        }
        if (p->val != q->val) {
            return false;
        }
        if (p->left || q->left) {
            if (!q->left || !p->left) {
                return false;
            }
            if (!isSameTree(p->left, q->left)) {
                return false;
            }
        }
        if (p->right || q->right) {
            if (!q->right || !p->right) {
                return false;
            }
            if (!isSameTree(p->right, q->right)) {
                return false;
            }
        }
        return true;
    }
};