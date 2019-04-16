#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *p1 = l1, *p2 = l2, *p3 = NULL;
    struct ListNode *l3 = NULL, *temp = NULL;
    int flag = 0;
    int tempNum;
    p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = p3;

    tempNum = p1->val + p2->val;
    if (tempNum >= 10)
    {
        p3->val = tempNum % 10;
        flag = 1;
    }
    else
    {
        p3->val = tempNum;
        flag = 0;
    }
    p3->next = NULL;
    p1 = p1->next;
    p2 = p2->next;
    while (p1 && p2)
    {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tempNum = p1->val + p2->val + flag;
        if (tempNum >= 10)
        {
            temp->val = tempNum % 10;
            flag = 1;
        }
        else
        {
            temp->val = tempNum;
            flag = 0;
        }
        temp->next = NULL;
        p3->next = temp;
        p1 = p1->next;
        p2 = p2->next;
        p3 = p3->next;
    }
    while (p1)
    {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tempNum = p1->val + flag;
        if (tempNum >= 10)
        {
            temp->val = tempNum % 10;
            flag = 1;
        }
        else
        {
            temp->val = tempNum;
            flag = 0;
        }
        temp->next = NULL;
        p3->next = temp;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2)
    {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tempNum = p2->val + flag;
        if (tempNum >= 10)
        {
            temp->val = tempNum % 10;
            flag = 1;
        }
        else
        {
            temp->val = tempNum;
            flag = 0;
        }
        temp->next = NULL;
        p3->next = temp;
        p2 = p2->next;
        p3 = p3->next;
    }
    if (flag)
    {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = flag;
        temp->next = NULL;
        p3->next = temp;
    }
    return l3;
}