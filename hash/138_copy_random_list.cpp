#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    unordered_map<Node *, Node *> origin_to_copyed;

    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node *node_copy = new Node(head->val);
        origin_to_copyed[head] = node_copy;
        if (head->next) {
            if (!origin_to_copyed.count(head->next))
                node_copy->next = copyRandomList(head->next);
            else
                node_copy->next = origin_to_copyed[head->next];
        }
        if (head->random) {
            if (!origin_to_copyed.count(head->random))
                node_copy->random = copyRandomList(head->random);
            else
                node_copy->random = origin_to_copyed[head->random];
        }
        return node_copy;
    }
};