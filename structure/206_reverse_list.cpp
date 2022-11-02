#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<ListNode *> list_nodes;
        ListNode *start = head;
        while(start) {
            list_nodes.push_back(start);
            start = start->next;
        }
        ListNode *reversed_head = new ListNode();
        start = reversed_head;
        for (int i = list_nodes.size() - 1; i >= 0; i--) {
            start->next = list_nodes[i];
            start = list_nodes[i];
        }
        start->next = nullptr;
        return reversed_head->next;
    }
};