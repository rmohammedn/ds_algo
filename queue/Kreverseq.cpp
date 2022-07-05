#include<iostream>
#include<queue>
#include<stack>
#include<vector>

void reverseQ(std::queue<int> &q, int k)
{
    size_t n = q.size();
    std::stack<int> stk;
    for (int i=0; i<k ; i++)
    {
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }
    for (int i=0 ; i < n-k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void printq(std::queue<int> q)
{
    while(!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    std::vector<int> vec{1,2,3,4,5};
    std::queue<int> q;
    for (auto ele : vec)
        q.push(ele);
    reverseQ(q, 3);
    printq(q);
}