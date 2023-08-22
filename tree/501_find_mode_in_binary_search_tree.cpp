#include <vector>

using std::vector;

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
    vector<int> findMode(TreeNode* root) {
        while (root) {
            if (!root->left) {
                log(root->val);
                root = root->right;
            } else {
                TreeNode* precursor = root->left;
                while (precursor->right && precursor->right != root) {
                    precursor = precursor->right;
                }
                if (precursor->right == root) {
                    log(root->val);
                    precursor->right = nullptr;
                    root = root->right;
                } else {
                    precursor->right = root;
                    root = root->left;
                }
            }
        }
        return res;
    }

private:
    int pre_value;
    int max_count = 0;
    int value_count = 0;
    vector<int> res;
    
    void log(int val) {
        if (value_count == 0) {
            ++value_count;
            pre_value = val;
        } else {
            if (val == pre_value) {
                ++value_count;
            } else {
                value_count = 1;
                pre_value = val;
            }
        }
        if (value_count && value_count == max_count) {
            res.push_back(val);
        }
        if (value_count > max_count) {
            max_count = value_count;
            res = vector<int>({val});
        }
    }
};