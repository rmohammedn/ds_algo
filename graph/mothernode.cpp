#include<iostream>
#include<vector>
#include<stack>

int getMotherNode(std::vector<std::vector<int>> &graph)
{
    std::stack<int> stk;
    size_t size = graph.size();
    bool visited[size]{};
    int flag{0}, curr;
    int count{0}, i{1};

    while (count < size and i < size)
    {
        for (auto ele : visited)
            ele = false;
        stk.push(i);
        count = 1;
        visited[i] = 1;
        i++;

        while (!stk.empty())
        {
            curr = stk.top();
            for (auto ele : graph[curr])
            {
                if (!visited[ele])
                {
                    stk.push(ele);
                    flag = 1;
                    visited[ele] = 1;
                    count++;
                    break;
                }
            }
            if (flag == 0)
            {
                
                stk.pop();
            }
            else
                flag = 0;
        }
    }
    if (i >= size)
        return -1;
    else
        return curr;
}

void DFSUtils(std::vector<std::vector<int>> &graph, std::vector<bool> &visited, int node)
{
    visited[node] = true;
    
    for (auto ele : graph[node])
    {
        if (!visited[ele])
            DFSUtils(graph, visited, ele);
    }

    std::cout << node << ", ";  
}

void DFS(std::vector<std::vector<int>> &graph)
{
    std::vector<bool> visited;
    size_t size = graph.size();

    for (int i=0; i<size; i++)
        visited.push_back(false);
    
    for (int i=0; i<size; i++)
    {
        if (!visited[i])
            DFSUtils(graph, visited, i);
    }
}

int main()
{
    std::vector<std::vector<int>> graph{{2}, {0}, {1}, {4}, {}};
    //std::cout << getMotherNode(graph) << std::endl;
    DFS(graph);
    return 0;
}