#include<iostream>
#include<memory>
#include<vector>
#include<string>

#define alpha 26

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v): val{v}, next{nullptr}{};
    ~ListNode(){ std::cout << val << " destroyed" << std::endl;}
};

void insert(ListNode *head, int val)
{
    ListNode *temp{head};
    while(temp->next)
        temp = temp->next;
    
    ListNode *node = new ListNode(val);
    //ListNode *node = std::make_shared<ListNode>(val).get();
    temp->next = node;
}

void print(ListNode *head)
{
    std::cout << std::endl;
    while(head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
void clear(ListNode *head)
{
    ListNode *temp{head};
    while(head)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}
struct Trie;
using trie = std::shared_ptr<Trie>;

struct Trie
{
    int count{1};
    bool end{0};
    trie child[alpha]{};
    Trie(){}
};

void insert(trie root, const std::string &word)
{
    trie node = root;
    node->count++;
    for (int i=0; i<word.length(); i++)
    {
        int indx = word[i] - 'a';
        if (node->child[indx] == nullptr)
        {
            node->child[indx] = std::make_shared<Trie>();
            node = node->child[indx];
        }
        else
        {
            node = node->child[indx];
            node->count++;
        }
    }
    node->end = true;
}

bool search(trie root, const std::string &word)
{
    trie temp{root};
    for (auto &letter: word)
    {
        int indx = letter - 'a';
        if (temp->child[indx] == nullptr)
            return false;
        temp = temp->child[indx];
    }
    return true;
}

void remove(trie root, const std::string &word)
{
    trie temp{root};
    int indx;
    int count;
    for (auto &letter: word)
    {
        indx = letter-'a';
        if (root->child[indx])
            count = root->child[indx]->count;
        else
        {
            std::cout << "word not found" << std::endl;
            return;
        }
        
        if (count <= 1)
        {
            temp = root->child[indx];
            root->child[indx] = nullptr;
            root = temp;
        }
        else
        {
            root = root->child[indx];
            root->count--;
        }    
    }
    root->end = 0;
}

void desplay(trie root, std::string &str)
{
    if (root->end)
        std::cout << str << std::endl;
    for (int i=0; i<alpha; i++)
    {
        if (root->child[i])
        {
            str += 'a' + i;
            desplay(root->child[i], str);
            str.pop_back();
        }
    }
}

int main()
{
    std::vector<std::string> vec{"zebra", "dog", "duck", "dove", "dogies"};
    //trie *root = new Trie();
    trie root = std::make_shared<Trie>();

    for (auto &ele: vec)
        insert(root, ele);
    
    for (auto &ele: vec)
    {
        trie temp{root};
        int count{root->count};
        std::string str{""};
        int indx;
        for (auto &letter: ele)
        {
            indx = letter - 'a';
            temp = temp->child[indx];
            count = temp->count;
            str += letter;
            if (count < 2)
                break;
        }
        std::cout << str << " ";
    }
    std::cout << std::endl;
    std::string str{""};
    remove(root, "zebra");
    desplay(root, str);
    return 0;
}