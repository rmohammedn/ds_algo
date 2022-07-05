#include<iostream>
#include<memory>

struct Node
{
    int data;
    int height{1};
    std::shared_ptr<Node> left, right;
    Node(int val):data(val), left(nullptr), right(nullptr){}
    ~Node()
    {
        std::cout << "deleting node " << data << std::endl;
        data = 0;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

int height(std::shared_ptr<Node> node)
{
    if (node)
        return node->height;
    else
        return 0;
}

std::shared_ptr<Node> rotateRight(std::shared_ptr<Node> node)
{
    std::shared_ptr<Node> y, t1;
    y = node->left;
    t1 = y->right;
    node->left = t1;
    y->right = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    y->height = std::max(node->height, height(y->left)) + 1;
    return y;
}

std::shared_ptr<Node> rotateLeft(std::shared_ptr<Node> node)
{
    std::shared_ptr<Node> y, t1;
    y = node->right;
    t1 = y->left;
    node->right = t1;
    y->left = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    y->height = std::max(node->height, height(y->right)) + 1;
    return y;
}
std::shared_ptr<Node> insert(std::shared_ptr<Node> node, int data)
{
    if (node == nullptr)
        return std::make_shared<Node>(data);
    
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = std::max(height(node->left), height(node->right)) + 1;

    int bal = height(node->left) - height(node->right);

    if (bal > 1 && node->left->data > data)
        node = rotateRight(node);
    else if (bal > 1 && node->left->data < data)
    {
        node->left = rotateLeft(node->left);
        node = rotateRight(node);
    }
    else if (bal < -1 && data > node->right->data)
        node = rotateLeft(node);
    else if (bal < -1 && data < node->right->data)
    {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
    }
    return node;
}

std::shared_ptr<Node> DeleteNode(std::shared_ptr<Node> node, int data)
{
    if (data < node->data)
        node->left = DeleteNode(node->left, data);
    else if (data > node->data)
        node->right = DeleteNode(node->right, data);
    else
    {
        if (node->right == nullptr)
            node = node->left;
        else if (node->left == nullptr)
            node = node->right;
        else
        {
            std::shared_ptr<Node> temp(node->right), next(node);
            while (temp->left != nullptr)
            {
                next = temp;
                temp = temp->left;   
            }
            
            if (next == node)
            {
                temp->left = node->left;
                node = temp;
            }
            else
            {
                node->data = temp->data;
                DeleteNode(node->right, temp->data);
            }
        }
        
    }
    if (node == nullptr)
        return node;

    node->height = std::max(height(node->left), height(node->right)) + 1;

    int bal = height(node->left) - height(node->right);

    if (bal > 1)
    {
        if (node->left->left->height > node->left->right->height)
            node = rotateRight(node);
        else
        {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
        
    }
    else if (bal < -1)
    {
        if (node->right->right->height > node->right->left->height)
            node = rotateLeft(node);
        else
        {
            node->right = rotateLeft(node->right);
            node = rotateLeft(node);
        }
        
    }
    return node;
}

void printInOrder(std::shared_ptr<Node> root)
{
    if (!root)
        return;
    printInOrder(root->left);
    std::cout << root->data << ", ";
    printInOrder(root->right);
}

void printPreOrder(std::shared_ptr<Node> root)
{
    if (!root)
        return;
    std::cout << root->data << ", ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    std::shared_ptr<Node> root = std::make_shared<Node>(2);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 0);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 7);
    printInOrder(root);
    std::cout << std::endl;
    printPreOrder(root);
    std::cout << std::endl;
    root = DeleteNode(root, 4);
    printInOrder(root);
    std::cout << std::endl;
    printPreOrder(root);
    return 0;
}
