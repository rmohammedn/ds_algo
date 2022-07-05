#ifndef MAKE_GRAPH
#define MAKE_GRAPH

#include<iostream>
#include<vector>
#include<queue>
#include<stack>

void printVector(std::vector<int> &vec)
{
    for (auto ele : vec)
        std::cout << ele << ", ";
    std::cout << std::endl;
}

void print2D(std::vector<std::vector<int>> &vec)
{
    for (auto ele : vec)
        printVector(ele);
}

void printStack(std::stack<int> stk)
{
    while(!stk.empty())
    {
        std::cout << stk.top() << ", ";
        stk.pop();
    }
    std::cout << std::endl;
}


class Graph
{
    private:
    std::vector<std::vector<int>> graph;

    public:
    int total_nodes;
    int total_edges;
    Graph(std::vector<std::vector<int>> data);
    void addEdge(int start, int end);
    void delEdge(int start, int end);
    void print();
    void BFS();
    void DFS();
    std::vector<std::vector<int>>& getGraph(){return graph;}
};

Graph::Graph(std::vector<std::vector<int>> data)
{
    graph = data;
    total_nodes = graph.size();
    int edge{0};
    for (auto num : graph)
        edge += num.size();
    total_edges = edge/2;
}

void Graph::addEdge(int start, int end)
{
    if (start >= total_nodes)
    {
        graph.push_back(std::vector<int>{end});
        total_nodes++;
    }
    else
    graph[start].push_back(end);

    if (end >= total_nodes)
    {
        graph.push_back(std::vector<int>{start});
        total_nodes++;
    }
    else
    graph[end].push_back(start);
    total_edges++;
}

void Graph::delEdge(int start, int end)
{
    for (auto i=graph[start].begin(); i < graph[start].end(); i++)
    {
        if (*i == end)
            graph[start].erase(i);
    }

    for (auto i=graph[end].begin(); i < graph[end].end(); i++)
    {
        if (*i == start)
            graph[end].erase(i);
    }
    total_edges--;
}

void Graph::print()
{
    int i{0};
    for (auto vec : graph)
    {
        std::cout << i << ": ";
        i++;
        for (auto ele : vec)
            std::cout << ele << ", ";
        std::cout << std::endl;
    }
}

void Graph::BFS()
{
    std::queue<int> q;
    bool arr[total_nodes]{};
    q.push(0);
    arr[0] = 1;
    int curr;
    while(!q.empty())
    {
        curr = q.front();
        q.pop();
        for (auto ele : graph[curr])
        {
            if (!arr[ele])
                q.push(ele);
            arr[ele] = 1;
        }
        std::cout << curr << ", ";
    }
    std::cout << std::endl;
}

void Graph::DFS()
{
    std::stack<int> stk;
    bool arr[total_nodes]{};
    stk.push(0);
    arr[0] = 1;
    int curr;
    int flag{0};
    while(!stk.empty())
    {
        curr = stk.top();
        for (auto ele : graph[curr])
        {
            if (!arr[ele])
            {
                stk.push(ele);
                arr[ele] = 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            std::cout << curr << ", ";
            stk.pop();
        }
        else
            flag = 0;  
    }
}

#endif
