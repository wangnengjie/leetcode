
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* h = head;
        while(head->next!=NULL){
            auto t = head->next;
            head->next = t->next;
            t->next = h;
            h = t;
        }
        return h;
    }
};