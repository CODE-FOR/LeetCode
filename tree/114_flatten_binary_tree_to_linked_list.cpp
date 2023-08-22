#include <stack>

using std::stack;

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
    void flatten(TreeNode* root) {
        TreeNode* dummy_head = new TreeNode();
        TreeNode* head = dummy_head;
        stack<TreeNode*> right_subtree_root_stack;
        right_subtree_root_stack.push(root);
        while (!right_subtree_root_stack.empty()) {
            root = right_subtree_root_stack.top();
            head->right = root;
            right_subtree_root_stack.pop();
            while (root) {
                if (root->right) {
                    right_subtree_root_stack.push(root->right);
                }
                head = root;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
        root = dummy_head->left;
    }
};