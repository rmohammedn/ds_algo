#include <iostream>
#include <memory>
#include <vector>
#include <utility>

#define TABLE_SIZE 15

struct Node
{
    int val;
    std::shared_ptr<Node> next{nullptr};
    Node(int x):val(x){}
};

class HashingC
{
    private:
    std::unique_ptr<std::shared_ptr<Node>[]> hash_table;

    public:
    int size;
    void insert(int key);
    int hash(int key);
    std::shared_ptr<Node> lookUp(int key);
    HashingC();
};

HashingC::HashingC()
{
    hash_table = std::make_unique<std::shared_ptr<Node>[]>(TABLE_SIZE);
    for(int i=0; i<TABLE_SIZE; i++)
        hash_table[i] = nullptr;
    size = 0;
}

int HashingC::hash(int key)
{
    return (key % TABLE_SIZE);
}

void HashingC::insert(int key)
{
    int indx = hash(key);
    std::shared_ptr<Node> node = std::make_shared<Node>(key);
    auto head = hash_table[indx];
    while (head.get()->next)
        head = (head.get())->next;
    
    head.get()->next = node;
}

std::shared_ptr<Node> HashingC::lookUp(int key)
{
    int indx = hash(key);
    auto head = hash_table[indx];
    while(head.get()->next != nullptr && head.get()->val != key)
        head = head.get()->next;
    
    if (head->next == nullptr)
        return (head.get())->next;
    return head;
}

int main()
{
    Node n1{1}, n2{2}, n3{3};
    HashingC hash{};
    //hash.insert(1);
    //auto head = hash.lookUp(1);
    //std::cout << head.get()->val << std::endl;
    return 0;
}