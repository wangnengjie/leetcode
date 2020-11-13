/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        ListNode *l1 = head;
        ListNode *l2 = head->next;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *pos = l2->next;
        for (int i = 0; pos != nullptr; i++, pos = pos->next) {
            if (i % 2) {
                p2->next = pos;
                p2 = p2->next;
            } else {
                p1->next = pos;
                p1 = p1->next;
            }
        }
        p1->next = l2;
        p2->next = nullptr;
        return l1;
    }
};