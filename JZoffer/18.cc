struct ListNode {
    int val;
    ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head == nullptr || head->val == val) {
            return head->next;
        }
        auto pos = head;
        for (; pos->next != nullptr; pos = pos->next) {
            if (pos->next->val == val) {
                break;
            }
        }
        if (pos->next == nullptr) {
            return head;
        }
        pos->next = pos->next->next;
        return head;
    }
};