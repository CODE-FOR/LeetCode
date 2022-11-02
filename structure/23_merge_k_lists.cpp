#include <vector>
#include <queue>

using std::priority_queue;
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Compare
{
public:
    bool operator () (const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};


class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, std::vector<ListNode *>, Compare> smallest_set;
        for (auto list : lists)
        {
            if (list)
                smallest_set.push(list);
        }
        ListNode *dummy_head = new ListNode();
        ListNode *start = dummy_head;
        while (!smallest_set.empty())
        {
            start->next = smallest_set.top();
            smallest_set.pop();
            start = start->next;
            if (smallest_set.empty())
            {
                break;
            }
            ListNode *smallest_in_set = smallest_set.top();
            while (start->next)
            {
                if (start->next->val > smallest_in_set->val)
                {
                    smallest_set.push(start->next);
                    break;
                }
                start = start->next;
            }
        }
        return dummy_head->next;
    }
};