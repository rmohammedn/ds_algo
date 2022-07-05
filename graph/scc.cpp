#include<iostream>
#include<vector>
#include<set>
#include<stack>

std::vector<std::set<int>> getTranspose(const std::vector<std::set<int>> &graph);
void DFS(const std::vector<std::set<int>> &graph, int node, std::vector<bool> &visit);
void printGraph(const std::vector<std::set<int>> &graph);

void printGraph(const std::vector<std::set<int>> &graph)
{
    for (auto set: graph)
    {
        for (auto ele : set)
            std::cout << ele << " ";
        std::cout << std::endl;
    }
}

void DFS(const std::vector<std::set<int>> &graph, int node, std::vector<bool> &visit)
{
    visit[node] = true;
    for (auto ele: graph[node])
    {
        if (!visit[ele])
            DFS(graph, ele, visit);
    }
}

void DFS(const std::vector<std::set<int>> &graph, int node, std::vector<bool> &visited,
        std::stack<int> &output_stk)
{
    std::stack<int> stk;
    int curr;
    bool flag{false};
    visited[node] = true;
    stk.push(node);

    while(!stk.empty())
    {
        curr = stk.top();
        for (auto ele : graph[curr])
        {
            if (!visited[ele])
            {
                stk.push(ele);
                visited[ele] = true;
                flag = true;
            }
        }
        if (!flag)
        {
            output_stk.push(curr);
            stk.pop();
        }
        else
        {
            flag = false;
        }               
    }
}

void printSCC(const std::vector<std::set<int>> &graph)
{
    std::stack<int> stk, output_stk;
    std::vector<std::set<int>> tgraph = getTranspose(graph);
    std::vector<bool> visited;
    size_t size = graph.size();
    int curr;

    for (int i=0; i<size; i++)
        visited.push_back(false);

    for (int i=0; i<size; i++)
    {
        if (!visited[i])
        {
            DFS(graph, i, visited, output_stk);
        }
    }

    for (auto ele : visited)
        ele = false;
    
    while (!output_stk.empty())
    {
        curr = output_stk.top();
        output_stk.pop();

        if (!visited[curr])
        {
            DFS(tgraph, curr, visited, stk);
        
            while(!stk.empty())
            {
                std::cout << stk.top() << " ";
                stk.pop();
            }
            std::cout << std::endl;
        }
    }
}

bool checkSC(const std::vector<std::set<int>> &graph)
{
    std::vector<bool> visit;
    size_t size = graph.size();
    int start{0};

    for (int i=0; i<size; i++)
        visit.push_back(false);
    DFS(graph, start, visit);

    for (auto ele: visit)
    {
        if (!ele)
            return false;
        ele = false;
    }

    std::vector<std::set<int>> tgraph = getTranspose(graph);
    DFS(graph, start, visit);

    for (auto ele: visit)
    {
        if (!ele)
            return false;
    }
    return true;
}


std::vector<std::set<int>> getTranspose(const std::vector<std::set<int>> &graph)
{
    std::vector<std::set<int>> tgraph;
    size_t size = graph.size();
    std::set<int> temp{};

    for (int i=0; i<size; i++)
        tgraph.push_back(temp);
    
    for (int i=0; i<size; i++)
    {
        for (auto ele : graph[i])
            tgraph[ele].insert(i);
    }
    return tgraph;
}

int main()
{
    std::vector<std::set<int>> graph{{1,2}, {0, 2}, {0, 1, 3, 4}, {2, 5}, {2, 5}, {3, 4}, {2}};
    std::cout << checkSC(graph) << std::endl;
    printSCC(graph);
    return 0;
}