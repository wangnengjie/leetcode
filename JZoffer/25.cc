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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode *p = NULL;
        ListNode *q = NULL;
        if(l1->val<l2->val){
            p = l1;
            l1 = l1->next;
        }else {
            p = l2;
            l2 = l2->next;
        }
        q = p;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val){
                p->next = l1;
                l1 = l1->next;
            }else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1==NULL?l2:l1;
        return q;
    }
};