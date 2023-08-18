#include <vector>

using std::vector;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        vector<Node*> nodePerLevel;
        vector<Node*> tmp;
        int depth = 0;
        nodePerLevel.push_back(root);
        while(!nodePerLevel.empty()) {
            for (auto& node : nodePerLevel) {
                for (auto& child_node : node->children) {
                    tmp.push_back(child_node);
                }
            }
            depth++;
            nodePerLevel = tmp;
            tmp.clear();
        }
        return depth;
    }
};