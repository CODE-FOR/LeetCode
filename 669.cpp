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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root->left != nullptr && (root->left->left != nullptr || root->left->right != nullptr)) {
            root->left = trimBST(root->left, low, high);
        }
        if (root->right != nullptr && (root->right->left != nullptr || root->right->right != nullptr)) {
            root->right = trimBST(root->right, low, high);
        }
        if (root->left != nullptr) {
            if (root->left->val < low) {
                root->left = nullptr;
            } else if (root->left->val > high) {
                return nullptr;
            }
        }
        if (root->right != nullptr) {
            if (root->right->val > high) {
                root->right = nullptr;
            } else if (root->right->val < low) {
                return nullptr;
            }
        }
        if (root->val < low && root->right) {
            return root->right;
        }
        if (root->val > high && root->left) {
            return root->left;
        }
        if (root->val >= low && root->val <= high) {
            return root;
        }
        return nullptr;
    }
};


int main() {
    TreeNode* t = new TreeNode(1);
    // t->left = new TreeNode(0);
    t->right = new TreeNode(2);
    Solution* s = new Solution();
    s->trimBST(t, 1, 2);
    return 0;
}