#include <iostream>
#include <memory>
#include <vector>

struct Node
{
    int key;
    std::shared_ptr<Node> left, right;
    Node(int val): key(val), left(nullptr), right(nullptr){}
};

int search(std::vector<int> &in, int val, int start, int end)
{
    for (int i=start; i<=end; i++)
    {
        if (in[i] == val)
        return i;
    }
}

std::shared_ptr<Node> buildTree(std::vector<int> &in, std::vector<int> &pre, int strt, int end)
{
    static int indx{0};
    if (strt > end)
        return nullptr;
    
    //std::cout << pre[indx] << ", ";
    int val = search(in, pre[indx], strt, end);
    std::shared_ptr<Node> node = std::make_shared<Node>(pre[indx]);
    indx++;
    if (strt == end)
    {
        std::cout << node->key << ", ";
        return node;
    }

    node->left = buildTree(in, pre, strt, val-1);
    std::cout << node->key << ", ";
    node->right = buildTree(in, pre, val+1, end);
    std::cout << node->key << ", ";
    
    return node;
}

void print(std::shared_ptr<Node> node)
{
    if (node == nullptr)
        return;
    
    print(node->left);
    std::cout << node->key << " ";
    print(node->right);
}

int main()
{
    std::vector<int> in{16, 7, 21, 12, 1, 5, 9};
    std::vector<int> pre{12, 7, 16, 21, 5, 1, 9};
    std::shared_ptr<Node> root = buildTree(in, pre, 0, 6);
    std::cout << std::endl;
    print(root);
    return 0;
}