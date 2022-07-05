#include<iostream>
#include<climits>
#include<vector>


struct Node
{
    int val;
    Node *next;
    Node(int x): val(x), next{nullptr}{}
};

Node* makeList(const std::vector<int> &vec)
{
    Node* head{nullptr},*curr, *temp;
    for (auto ele: vec)
    {
        temp = new Node(ele);
        if (head == nullptr)
        {
            head = temp;
            curr = temp;
        }
        else
        {
            curr->next = temp;
            curr = temp;
        }
    }
    return head;
}

Node* removeDup(Node* head)
{
    Node *curr{head}, *post{nullptr}, *start{nullptr}, *pre{nullptr};
    int target{INT_MAX};
    post = curr->next;
    while(post != nullptr)
    {
        if (target == curr->val)
        {
            if (start == nullptr)
            {
                curr = post;
                post = post->next;
            }
            else
            {
                pre->next = post;
                curr = post;
                post = post->next;
            }   
        }
        else
        {
            if (curr->val == post->val)
            {
                target = curr->val;

                if (start == nullptr)
                {
                    curr = post;
                    post = post->next;
                }
                else
                {
                    pre->next = post;
                    curr = post;
                    post = post->next;
                }
            }
            else
            {
                if (start == nullptr)
                {
                    start = curr;
                }
                pre = curr;
                curr = post;
                post = post->next;
            }     
        }
        
    }
    return start;
}

void printList(Node *head)
{
    while(head != nullptr)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1,1,3,3,4,5};
    Node* head = makeList(vec);
    printList(head);
    head = removeDup(head);
    printList(head);
    return 0;
}