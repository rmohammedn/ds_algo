#include <queue>
#include <iostream>


void printq(std::queue<int> q)
{
    while(!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
}

std::queue<int> reverse(std::queue<int> &q)
{
    if (q.size() == 1)
        return q;
    int num = q.front();
    q.pop();
    q = reverse(q);
    q.push(num);
    return q;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5, 6};
    std::queue<int> q;
    for (int ele : vec)
        q.push(ele);
    q = reverse(q);
    printq(q);
    return 0;
}