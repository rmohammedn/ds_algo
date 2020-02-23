/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) 
{
    if (B == C)
        return A;
    
    ListNode *pre{}, *post{}, *head{A}, *start{}, *end{A};
    int i{1};
    
    while (i <= C)
    {
        if (i < B-1)
        {
            head = head->next;
        }
        else if (i == B - 1)
        {
            start = head;
            head = head->next;
            end = head;
        }
        else
        {
            post = head->next;
            head->next = pre;
            pre = head;
            head = post;
            
        }
        i++;
    }
    if (start != nullptr)
        start->next = pre;
    else
        A = pre;
    end->next = post;
    return A;
}
