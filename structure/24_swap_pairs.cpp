struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *start = head;
        ListNode *dummy_head = new ListNode(0, head);
        ListNode* last = dummy_head;
        while (start && start->next) {
            ListNode *tmp = start->next;
            start->next = start->next->next;
            tmp->next = start;
            last->next = tmp;
            last = start;
            start = last->next;
        }
        return dummy_head->next;
    }
};