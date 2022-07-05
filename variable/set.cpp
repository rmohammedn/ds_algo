#include<iostream>
#include<set>

struct Node
{
    int key;
    int val;
    Node(int k, int v): key(k), val(v){}
    Node(){}
    bool operator() (const Node &lhs, const Node &rhs) const
    {
        if (lhs.key == rhs.key)
            return lhs.val < rhs.val;
        else
            return lhs.key < rhs.key;
    }
};


void print(const std::set<Node, Node> &list)
{
    for (auto &node : list)
        std::cout << node.key << "," << node.val << std::endl;
}

int main()
{
    Node* (2,5);
    std::set<Node, Node> list;
    list.insert(Node(1,5));
    list.insert(Node(1,5));
    list.insert(Node(5,10));
    list.insert(Node(3,10));
    list.insert(Node(3,20));
    std::cout << list.size() << std::endl;
    print(list);
    return 0;
}