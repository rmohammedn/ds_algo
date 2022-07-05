#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <stack>

struct Node
{
    int key;
    std::shared_ptr<Node> left, right;
    Node(int val): key(val), left(nullptr), right(nullptr){}
    ~Node(){key=0; left=nullptr; right=nullptr;}
};

void inorderPrint(std::shared_ptr<Node> root)
{
    if (root == nullptr)
        return;
    inorderPrint(root->left);
    std::cout << root->key << " ";
    inorderPrint(root->right);
}

void preOrderPrint(std::shared_ptr<Node> root)
{
    if (root == nullptr)
        return;
    std::cout << root->key << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

void postOrderPrint(std::shared_ptr<Node> root)
{
    if (root == nullptr)
        return;
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    std::cout << root->key << " ";
}

void insert(std::shared_ptr<Node> root, int val)
{
    std::queue<std::shared_ptr<Node>> q;
    q.push(root);

    while(!q.empty())
    {
        std::shared_ptr<Node> temp = q.front();
        q.pop();

        if(!temp->left)
        {
            temp->left = std::make_shared<Node>(val);
            return;
        }
        else
            q.push(temp->left);
        
        if(!temp->right)
        {
            temp->right = std::make_shared<Node>(val);
            return;
        }
        else
            q.push(temp->right);
    }
}

std::shared_ptr<Node> find(std::shared_ptr<Node> root, int val)
{
    std::stack<std::shared_ptr<Node>> stk;
    std::shared_ptr<Node> curr{root};

    while (!stk.empty() || curr != nullptr)
    {
        while(curr != nullptr)
        {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();
        if (curr->key == val)
            return curr;
        
        else
            curr = curr->right;
    }
}

void postPrint(std::shared_ptr<Node> root)
{
    std::stack<std::shared_ptr<Node>> stk;
    std::shared_ptr<Node> curr{root};
    std::shared_ptr<Node> temp;

    while (!stk.empty() || curr != nullptr)
    {
        while(curr != nullptr)
        {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        if (!curr->right)
        {
            std::cout << curr->key << " ";
            stk.pop();
            curr = nullptr;
        }
        else
        {
            temp = curr;
            curr = curr->right;
            stk.pop();
        }
    }
}
void prePrint(std::shared_ptr<Node> root)
{
    std::stack<std::shared_ptr<Node>> stk;
    std::shared_ptr<Node> curr{root};

    while (!stk.empty() || curr != nullptr)
    {
        while(curr != nullptr)
        {
            std::cout << curr->key << " ";
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();
        curr = curr->right;
    }
}

void deleteNode(int val)
{

}

std::shared_ptr<Node> makePerfactTree(std::vector<int> &vec)
{
    int indx{0};
    size_t size = vec.size();
    std::queue<std::shared_ptr<Node>> q;
    std::shared_ptr<Node> root = std::make_shared<Node>(vec[indx++]);
    q.push(root);

    while(indx < size)
    {
        std::shared_ptr<Node> temp = q.front();
        q.pop();

        temp->left = std::make_shared<Node>(vec[indx++]);
        q.push(temp->left);
        temp->right = std::make_shared<Node>(vec[indx++]);
        q.push(temp->right);
    }
    return root;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7};
    std::shared_ptr<Node> root = makePerfactTree(vec);
    
    prePrint(root);
    return 0;
}