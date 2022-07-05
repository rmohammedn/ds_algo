#include<iostream>
#include<memory>

struct Node 
{
    int data;
    int height{1};
    bool color;
    std::shared_ptr<Node> left, right, parent{nullptr};
    Node(int val, bool col=0): data(val), color(col), left(nullptr), right(nullptr){}
}

enum Color{Black, Red};

std::shared_ptr<Node>& BSTinsert(std::shared_ptr<Node> &root, std::shared_ptr<Node> &node)
{
    if (root == nullptr)
        return node;
    
    if (node->data < root->data)
    {
        root->left = BSTinsert(root->left, node);
        root->left->parent = root;
    }
    else if (node->data > root->data)
    {
        root->right = BSTinset(root->right, node);
        root->right->parent = root;
    }
    else
        return root;
}

void rotateRight(std::shared_ptr<Node> &node)
{
    std::shared_ptr<Node> father, t1, x;
    x = node->left;
    t1 = x->right;
    father = node->parent;

    x->parent = father;
    x->right = node;
    node->parent = x;
    node->left = t1;
    t1->parent = node;
}

std::shared_ptr<Node>& balanceTree(std::shared_ptr<Node> &root, std::shared_ptr<Node> &node)
{
    if (node->parent == nullptr)
    {
        node->color = Black;
        return node;
    }

    std::shared_ptr<Node> father, uncle, gr_father;

    father = node->parent;
    if (father->color == Black)
        return root;
    
    gr_father = node->parent->parent;
    if (gr_father->left == father)
    {
        uncle = gr_father->right;

        if (uncle && uncle->color == Red)
        {
            uncle->color = Black;
            father->color = Black;
            gr_father->color = Red;
            node = gr_father;
            root = balanceTree(root, node);
        }

        else
        {
            if (father->left == node)
                rotateRight(gr_father);
            else
            {
                rotateLeft(father);
                rotateRight(gr_father);
            }
        }
        
    }
    else
    {
        uncle = gr_father->left;

        if (uncle && uncle->color == Red)
        {
            uncle->color = Black;
            father->color = Black;
            gr_father->color = Red;
            node = gr_father;
            root = balanceTree(root, node);
        }

        else
        {
            if (father->right == node)
                rotateLeft(gr_father);
            else
            {
                rotateRight(father);
                rotateLeft(gr_father);
            }
        }
        
    }
}

std::shared_ptr<Node> insert(std::shared_ptr<Node> &root, int val)
{
    std::shared_ptr<Node> node = std::make_shared<Node>(val);
    root = BSTinset(root, node);
    root = balanceTree(root, node);
    return root;
}

