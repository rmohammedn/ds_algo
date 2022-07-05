#include<iostream>
#include<vector>
#include<queue>
#include<memory>
#include<stack>

struct Node
{
    int data;
    std::shared_ptr<Node> left, right;
    Node(int val): data(val), left(nullptr), right(nullptr){}
    ~Node()
    {
        left = nullptr;
        right = nullptr;
        std::cout << "Node " << data << " got deleted" << std::endl;
    }
};

std::shared_ptr<Node> makeTree(std::vector<int> &vec)
{
    std::queue<std::shared_ptr<Node>> q;
    int indx{0};
    size_t size = vec.size();
    std::shared_ptr<Node> root = std::make_shared<Node>(vec[indx++]);
    std::shared_ptr<Node> temp;
    q.push(root);

    while(indx < size)
    {
        temp = q.front();
        q.pop();
        temp->left = std::make_shared<Node>(vec[indx++]);
        q.push(temp->left);

        if (indx < size)
        {
            temp->right = std::make_shared<Node>(vec[indx++]);
            q.push(temp->right);
        }
    }
    return root;
}

void postOrderPrint(std::shared_ptr<Node> root)
{
    if (root == nullptr)
        return;
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    std::cout << root->data << " ";
}

void postOrderTraversal(std::shared_ptr<Node> root)
{
    std::stack<std::shared_ptr<Node>> stk;
    std::shared_ptr<Node> temp, curr;
    if (root->right)
        stk.push(root->right);
    stk.push(root);
    curr = root->left;

    while(!stk.empty())
    {
        if (curr != nullptr)
        {
            if (curr->right)
                stk.push(curr->right);
            stk.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = stk.top();
            stk.pop();
            
            if (curr->right && !stk.empty() && curr->right == stk.top())
            {
                stk.pop();
                stk.push(curr);
                curr = curr->right;
            }
            else
            {
                std::cout << curr->data << " ";
                curr = nullptr;
            }
        }
    }
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7};
    std::shared_ptr<Node> root = makeTree(vec);
    postOrderPrint(root);
    postOrderTraversal(root);
    return 0;
}
