#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) 
{
    int i{0};
    ListNode *head = A;
    while(head != nullptr)
    {
        head = head->next;
        i++;
    }
    if (i == 1)
        return 1;
    
    int half = i / 2;
    int odd = i % 2;
    ListNode *pre{nullptr}, *post{nullptr};
    head = A;
    for (int j=0; j < half; j++)
    {
        post = head->next;
        head->next = pre;
        pre = head;
        head = post;
    }
    
    if (odd)
        post = post->next;
    
    for (int j=0; j<half; j++)
    {
        if (pre->val == post->val)
        {
            pre = pre->next;
            post = post->next;
        }
        else
            return 0;
    }
    return 1;
}
