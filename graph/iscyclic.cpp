#include<iostream>
#include<vector>
#include<stack>

#include"makegraph.cpp"

bool isCyclic(Graph &graph)
{
    std::vector<std::vector<int>> &vec = graph.getGraph();
    std::stack<int> stk;
    bool arr[vec.size()]{};
    stk.push(0);
    arr[0] = 1;
    int curr, parent{-1};
    int flag{0};
    while(!stk.empty())
    {
        curr = stk.top();
        for (auto ele : vec[curr])
        {
            if (arr[ele] && ele != parent)
                return true;
            else if (arr[ele] == false)
            {
                stk.push(ele);
                arr[ele] = 1;
                flag = 1;
                parent = curr;
                break;
            }
        }
        if (flag == 0)
        {
            stk.pop();
            if (stk.size() > 1)
            {
                curr = stk.top();
                stk.pop();
                parent = stk.top();
                stk.push(curr);
            }
            else
                parent = -1;
        }
        else
        {
            flag = 0;
        }
        
    }
    return false;
}

void findPath(Graph &g, int u, int v)
{
    const std::vector<std::vector<int>> vec = g.getGraph();
    bool visited[vec.size()]{};
    int flag{0}, curr;
    std::stack<int> stk;
    stk.push(u);
    visited[u] = 1;
    while(!stk.empty())
    {
        curr = stk.top();
        for (auto ele : vec[curr])
        {
            if (ele == v)
            {
                stk.push(ele);
                printStack(stk);
                stk.pop();
            }

            else if (!visited[ele])
            {
                stk.push(ele);
                visited[ele] = 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            stk.pop();
        else
            flag = 0;
    }
}

int main()
{
    std::vector<std::vector<int>> vec{{1,2,3}, {0, 4}, {0, 3}, {0, 4}, {1, 3}};
    Graph graph(vec);
    //print2D(vec);
    findPath(graph, 2, 3);
    return 0;
}
