#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_root_id = postorder.size() - 1;
        int pos = 0;
        for (auto& value : inorder) {
            inorder_value_to_pos_map[value] = pos++;
        }
        return buildTree(inorder, postorder, 0, postorder_root_id);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inorder_left, int inorder_right) {
        if (inorder_left > inorder_right) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postorder_root_id]);
        postorder_root_id--;
        int index = inorder_value_to_pos_map[root->val];
        root->right = buildTree(inorder, postorder, index + 1, inorder_right);
        root->left = buildTree(inorder, postorder, inorder_left, index - 1);
        return root;
    }

private:
    int postorder_root_id;
    unordered_map<int, int> inorder_value_to_pos_map;
};