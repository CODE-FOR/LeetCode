struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (true) {
            if (tempA == tempB) return tempA;
            if (tempA != nullptr) tempA = tempA->next;
            else tempA = headB;
            if (tempB != nullptr) tempB = tempB->next;
            else tempB = headA;
        }
    }
};

// 4 1 8 4 5 5 6 1 8 4 5
// 5 6 1 8 4 5 4 1 8 4 5