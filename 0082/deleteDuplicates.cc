
#include <cstddef>
#include <cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *pos = head;
        ListNode *prev = head;
        while (pos != NULL) {
            ListNode *q = pos->next;
            bool flag = false;
            while (q != NULL) {
                if (q->val == pos->val) {
                    pos->next = q->next;
                    delete q;
                    q = pos->next;
                    flag = true;
                } else {
                    break;
                }
            }
            if (flag) {
                if (pos == head) {
                    head = pos->next;
                    delete pos;
                    pos = head;
                    prev = head;
                } else {
                    prev->next = pos->next;
                    delete pos;
                    pos = prev->next;
                }
            } else {
                prev = pos;
                pos = pos->next;
            }
        }
        return head;
    }
};