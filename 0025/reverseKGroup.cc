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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;
        ListNode *re = head;
        for (int i = 0; i < k - 1; i++)
        {
            if (!re->next)
                return head;
            re = re->next;
        }
        // 此时re指向反转后的头结点
        ListNode *next = re->next;
        ListNode *p = reverse(head, k);
        p->next = reverseKGroup(next, k);
        return re;
    }

    ListNode *reverse(ListNode *p, int k)
    {
        if (k == 2)
        {
            ListNode *t = p->next;
            t->next = p;
            return p;
        }
        ListNode *t = reverse(p->next, k - 1);
        t->next = p;
        return p;
    }
};