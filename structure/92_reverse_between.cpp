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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode *> list_nodes;
        
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *start = dummy_head;
        ListNode *left_end;
        ListNode *right_start;
        int i = 0;
        while(start) {
            if (i == left - 1)
                left_end = start;
            if (i == right)
                right_start = start->next;
            list_nodes.push_back(start);
            start = start->next;
            i++;
        }
        ListNode *reversed_head = new ListNode();
        start = reversed_head; 
        for (int i = right; i >= left; i--) {
            start->next = list_nodes[i];
            start = list_nodes[i];
        }
        start->next = right_start;
        left_end->next = reversed_head->next;
        return dummy_head->next;
    }
};