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
    vector<int> reversePrint(ListNode *head) {
        auto res = vector<int>();
        auto pos = head;
        while (pos != nullptr) {
            res.push_back(pos->val);
            pos = pos->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};