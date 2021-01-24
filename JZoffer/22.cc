/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        auto l = head, r = head;
        while (k > 0) {
            r = r->next;
            k--;
        }
        while (r != nullptr) {
            l = l->next;
            r = r->next;
        }
        return l;
    }
};