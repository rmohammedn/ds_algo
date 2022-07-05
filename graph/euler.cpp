#include<iostream>
#include<vector>
#include<set>

void deleteEdge(std::vector<std::set<int>> &graph, int start, int end);
int DFSCount(std::vector<std::set<int>> &graph, int node, std::vector<bool> &visited, int &count);
bool isBridge(std::vector<std::set<int>> &graph, int start, int end);
void printEulerPath(std::vector<std::set<int>> graph);
bool eulerPath(const std::vector<std::set<int>> &graph);
void addEdge(std::vector<std::set<int>> &graph, int start, int end);
std::vector<int> getDegree(const std::vector<std::set<int>> &graph);

std::vector<int> getDegree(const std::vector<std::set<int>> &graph)
{
    std::vector<int> degree;
    size_t size = graph.size();
    for (int i=0; i<size; i++)
        degree.push_back(0);
    
    int sum;
    for (int i=0; i<size; i++)
    {
        degree[i] += graph[i].size();
        for (auto ele : graph[i])
        {
            degree[ele]++;
        }
    }
    return degree;
}

bool eulerPath(const std::vector<std::set<int>> &graph)
{
    std::vector<int> degree = getDegree(graph);
    int odd_count{0};
    for (auto ele : degree)
    {
        if (ele %2 == 1)
            odd_count++;
    }
    if (odd_count == 0 || odd_count == 2)
        return true;
    else
        return false;
}

bool eulerCycle(const std::vector<std::set<int>> &graph)
{
    std::vector<int> degree = getDegree(graph);
    for (auto ele : degree)
    {
        if (ele % 2 == 1)
            return false;
    }
    return true;
}

void printEulerPath(std::vector<std::set<int>> graph)
{
    int start, i{-1}, j{0};
    int odd[2];
    std::vector<int> indeg, outdeg;
    

    for (auto ele : degree)
    {
        if (ele % 2 == 1)
        {
            odd[++i] = j;
        }
        j++;
    }
    if (i == -1)
        start = 0;
    else if (i > 1 || i == 0)
    {
        std::cout << " graph is not eulerian path " << std::endl;
        return;
    }
    else
    {
        if (graph[odd[0]].size() < graph[odd[1]].size() && graph[odd[0]].size != 0)
            start = odd[0];
        else
            start = odd[1];
        
        for (auto ele : graph[start])
        {
            if (!isBridge(graph, start, ele))
            {
                std::cout << start << "-" << ele << std::endl;
                deleteEdge(graph, start, ele);
                start = ele;
                break;
            }

        }
    }

    while(!graph[start].empty())
    {
        for (auto ele : graph[start])
        {
            std::cout << start << "-" << ele << std::endl;
            deleteEdge(graph, start, ele);
            start = ele;
        }
    }
}

int DFSCount(std::vector<std::set<int>> &graph, int node, std::vector<bool> &visited, int &count)
{
    count++;
    visited[node] = true;
    for (auto ele : graph[node])
    {
        if (!visited[ele])
        {
            count++;
            DFSCount(graph, ele, visited, count);
        }
    }
    return count;
}

bool isBridge(std::vector<std::set<int>> &graph, int start, int end)
{
    std::vector<bool> visited;
    size_t size = graph.size();
    int num{0};

    for (int i=0; i<size; i++)
        visited.push_back(false);

    int count = DFSCount(graph, end, visited, num);
    deleteEdge(graph, start, end);
    int count2 = DFSCount(graph, end, visited, num);
    addEdge(graph, start, end);

    if (count2 < count)
        return true;
    
    return false;
}

void deleteEdge(std::vector<std::set<int>> &graph, int start, int end)
{
    graph[start].erase(end);
}

void addEdge(std::vector<std::set<int>> &graph, int start, int end)
{
    graph[start].insert(end);
}

int main()
{
    std::vector<std::set<int>> graph{{1,2}, {0, 2}, {0, 1, 3, 4}, {2, 5}, {2, 5}, {3, 4}, {2}};
    std::cout << eulerCycle(graph) << std::endl;
    std::cout << eulerPath(graph) << std::endl;
    std::vector<int> degree = getDegree(graph);
    printEulerPath(graph);
    for (auto ele : degree)
        std::cout << ele << " ";
    return 0;
}