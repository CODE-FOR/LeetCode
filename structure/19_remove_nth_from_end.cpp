struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *start = head;
        while(start != nullptr) {
            ++len;
            start = start->next;
        }
        int kth_from_head = len - n;
        if (!kth_from_head) {
            return head->next;
        }
        len = 0;
        start = head;
        while (len < kth_from_head - 1) {
            start = start->next;
            ++len;
        }
        start->next = start->next->next;
        return head;
    }
};