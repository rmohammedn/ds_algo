#include<iostream>
#include<vector>


struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left{nullptr}, right{nullptr}{}
};

TreeNode* makeTree(const std::vector<int> &pre, const std::vector<int> &in, int& indx, int start, int end)
{
    if (start >= end)
    {
        indx--;
        return nullptr;
    }
    
    if (indx > 6)
        return nullptr;
    
    TreeNode *node = new TreeNode(pre[indx]);
    int i;
    for (i=start; i<end; i++)
    {
        if(in[i] == pre[indx])
            break;
    }
    node->left = makeTree(pre, in, ++indx, start, i);
    node->right = makeTree(pre, in, ++indx, i+1, end);
    return node;
}

void print(TreeNode *root)
{
    if (root == nullptr)
        return;
    print(root->left);
    std::cout << root->val << ", ";
    print(root->right);
}

void printPre(TreeNode *root)
{
    if (root == nullptr)
        return;
    std::cout << root->val << ", ";
    printPre(root->left);
    printPre(root->right);
}

TreeNode* makeFlat(TreeNode *node)
{
    if (node->left == nullptr && node->right == nullptr)
        return node;
        
    if (node->left)
    {
        TreeNode *right = node->right;
        node->right = node->left;
        node->left = nullptr;
        TreeNode *left = makeFlat(node->right);
        left->right = right;
        if (right)
            return makeFlat(right);
    }
    else
        return makeFlat(node->right);

}

int main()
{
    std::vector<int> in{4, 2, 5, 1, 6, 3, 7};
    std::vector<int> pre{1, 2, 4, 5, 3, 6, 7};
    int indx{0};
    TreeNode *root = makeTree(pre, in, indx, 0, 7);
    print(root);
    std::cout << std::endl;
    makeFlat(root);
    print(root);
    return 0;
}