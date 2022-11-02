#include <stack>

using std::stack;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode *> num1, num2;
        stack<ListNode *> res;
        while (l1) {
            num1.push(l1);
            l1 = l1->next;
        }
        while (l2) {
            num2.push(l2);
            l2 = l2->next;
        }
        int cin = 0;
        while (!num1.empty() || !num2.empty() || cin) {
            int point_value = cin;
            if (!num1.empty()) {
                point_value += num1.top()->val;
                num1.pop();
            }
            if (!num2.empty()) {
                point_value += num2.top()->val;
                num2.pop();
            }
            res.push(new ListNode(point_value % 10));
            cin = point_value / 10;
        }
        ListNode *dummy_head = new ListNode();
        ListNode *start = dummy_head;
        while (!res.empty()) {
            start->next = res.top();
            start = start->next;
            res.pop();
        }
        return dummy_head->next;
    }
};