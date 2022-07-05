#include<iostream>
#include<vector>
#include<memory>
#include<queue>

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
std::vector<int> list2tree(std::shared_ptr<Node> root)
{
    std::queue<std::shared_ptr<Node>> q;
    std::shared_ptr<Node> temp;
    std::vector<int> arr;
    q.push(root);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        arr.push_back(temp->key);

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);

    }
    return arr;
}

void printVector(std::vector<int> &vec)
{
    for (auto ele : vec)
        std::cout<< ele << ", ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7}, vec2;
    std::shared_ptr<Node> root = makePerfactTree(vec);
    vec2 = list2tree(root);
    printVector(vec2);
    return 0;
}