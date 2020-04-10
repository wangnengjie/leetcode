
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
  public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        unsigned int len = 1;
        for (ListNode *p = head; p->next != nullptr; p = p->next, len++)
            ;
        unsigned int bcIndex = k % len;
        ListNode *p = head, *q = head;
        for (unsigned int i = 0; i < bcIndex; i++)
            p = p->next;

        for (; p->next != nullptr; p = p->next, q = q->next)
            ;
        p->next = head;
        head = q->next;
        q->next = nullptr;
        return head;
    }
};