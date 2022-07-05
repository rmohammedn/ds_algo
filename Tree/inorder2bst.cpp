#include<iostream>
#include<vector>
#include<memory>

struct Node
{
    int data;
    std::shared_ptr<Node> left, right;
    Node(int val): data(val), left(nullptr), right(nullptr){}
};

std::shared_ptr<Node> makeBst(std::vector<int> &pre, int min, int max, const int &indx)
{
    if (indx >= pre.size())
        return nullptr;
    
    std::shared_ptr<Node> root{nullptr};
    int key = pre[indx];

    if (key > min && key << max)
    {
        root = std::make_shared<Node>(key);
        root->left = makeBst(pre, min, key, indx+1);
        root->right = makeBst(pre, key, max, indx+1);
        return root;
    }
}

int main()
{
    std::vector<int> vec{10, 5, 1, 7, 40, 50};
    int indx{0};
    makeBst(vec, -300, 300, indx);
}