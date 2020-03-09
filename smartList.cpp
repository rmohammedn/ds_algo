#include<iostream>
#include<memory>

struct Node
{
    int val;
    Node *next;
    Node(int x):val(x), next(nullptr){}
    ~Node(){ next = nullptr;}
};

void printList(Node* head)
{
    while(head != nullptr)
    {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
}

void deleteList(Node* &head)
{
    Node *temp = head;
    while(temp != nullptr)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

Node* pushFront(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    return temp;
}

std::shared_ptr<Node> pushSmart(std::shared_ptr<Node> &head, int val)
{
    std::shared_ptr<Node> temp = std::make_shared<Node>(val);
    temp->next = head.get();
    return temp;
}

int main()
{
    std::shared_ptr<Node> head = std::make_shared<Node>(5);
    for (int i=0; i<10; i++)
        head = pushSmart(head, i);
    
    printList(head.get());

    /*
    Node *head = new Node(5);
    for (int i=1; i<10; i++)
        head = pushFront(head, i);
    
    printList(head);
    deleteList(head);
    printList(head);
    */
    return 0;
}