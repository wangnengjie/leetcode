#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *re = head->next;
        head->next = swapPairs(re->next);
        re->next = head;
        return re;
    }
};