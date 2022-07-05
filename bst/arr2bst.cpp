#include<iostream>
#include<vector>
#include<memory>

struct Node
{
    int data;
    std::shared_ptr<Node> left, right;
    Node(int key): data(key), left(nullptr), right(nullptr){}
    ~Node(){left=nullptr; right=nullptr; std::cout<<data<<" deleted"<< std::endl; data=0;}
};

std::shared_ptr<Node> makeBst(std::vector<int> &vec, int strt, int end)
{
    if (strt >= end)
        return nullptr;
    
    int indx = (strt + end)/2;
    std::shared_ptr<Node> root = std::make_shared<Node>(vec[indx]);
    root->left = makeBst(vec, strt, indx);
    root->right = makeBst(vec, indx+1, end);
    return root;
}

void insert(std::shared_ptr<Node> root, int val)
{
    if (root == nullptr)
        return;

    if (val > root->data)
    {
        if (root->right)
            insert(root->right, val);
        else
            root->right = std::make_shared<Node>(val);
    }
    else
    {
        if (root->left)
            insert(root->left, val);
        else
        {
            root->left = std::make_shared<Node>(val);
        }
    }
}

std::shared_ptr<Node> deleteNode(std::shared_ptr<Node> root, int key)
{
    if (root == nullptr)
    {
        std::cout << key << " not found" << std::endl;
        return nullptr;
    }
    if (root->data > key)
        root->left = deleteNode(root->left, key);
    else if (root->data < key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->right == nullptr)
            return root->left;
        else if (root->left == nullptr)
            return root->right;
        else
        {
            std::shared_ptr<Node> temp{root->right}, pre{root};
            while (temp->left != nullptr)
            {
                pre = temp;
                temp = temp->left;
            }
            root->data = temp->data;
            if (pre == root)
                root->right = temp->right;
            else
                pre->left = temp->right;
            
            return root;
        }
        
    }
    return root;
}

void printInorder(std::shared_ptr<Node> root)
{
    if (root == nullptr)
        return;
    printInorder(root->left);
    std::cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    std::vector<int> vec{1,2,3,4,5, 6, 7};
    std::shared_ptr<Node> root = makeBst(vec, 0, vec.size());
    printInorder(root);
    std::cout << std::endl;
    deleteNode(root, 5);
    insert(root, 5);
    printInorder(root);
    return 0;
}