#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

struct Node
{
    int val;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    Node(int x): val(x), left(nullptr), right(nullptr){}
};

void verticleOrder(std::unordered_map<int, std::vector<int>> &un_m,
               std::shared_ptr<Node> head, int num)
{
    un_m[num].push_back(head->val);

    if (head->left != nullptr)
        verticleOrder(un_m, head->left, num-1);
    
    if (head->right != nullptr)
        verticleOrder(un_m, head->right, num+1);
}

void printVO(std::shared_ptr<Node> head)
{
    std::unordered_map<int, std::vector<int>> un_m;
    verticleOrder(un_m, head, 0);
    for (auto key : un_m)
    {
        std::cout << key.first << " - ";
        for (auto ele : key.second)
            std::cout << ele << ", ";
        std::cout << std::endl;
    }
}

int main()
{
    std::shared_ptr<Node> head = std::make_shared<Node>(5);
    head->left = std::make_shared<Node>(3);
    head->left->left = std::make_shared<Node>(1);
    head->left->right = std::make_shared<Node>(0);
    head->right = std::make_shared<Node>(4);
    head->right->right = std::make_shared<Node>(2);
    printVO(head);
    return 0;
}

