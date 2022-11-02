#include <stack>

using std::stack;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node *dummy_head = new Node();
        Node *end = dummy_head;
        stack<Node *> nodes_to_flatten;
        if (head) {
            nodes_to_flatten.emplace(head);
        }
        while(!nodes_to_flatten.empty()) {
            end->next = nodes_to_flatten.top();
            end->next->prev = end;
            end = end->next;
            nodes_to_flatten.pop();
            Node *last;
            while (end) {
                if (end->child) {
                    if (end->next)
                        nodes_to_flatten.emplace(end->next);
                    end->next = end->child;
                    end->next->prev = end;
                    end->child = nullptr;
                }
                last = end;
                end = end->next;
            }
            end = last;
        }
        if (dummy_head->next)
            dummy_head->next->prev = nullptr;
        return dummy_head->next;
    }
};