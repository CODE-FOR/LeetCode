struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy_head = new ListNode();
        ListNode *start = dummy_head;
        while (list1 != nullptr || list2 != nullptr) {
            if (!list1) {
                start->next = list2;
                list2 = list2->next;
            }
            else if (!list2) {
                start->next = list1;
                list1 = list1->next;
            }
            else if (list1 && list2) {
                if (list1->val < list2->val) {
                    start->next = list1;
                    list1 = list1->next;
                } else {
                    start->next = list2;
                    list2 = list2->next;
                }
            }
            start = start->next;
        }
        return dummy_head->next;
    }
};