#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<climits>

void APUtils(const std::vector<std::set<int>> &graph,
             std::vector<int> &disc,
             std::vector<int> &low,
             std::vector<int> &parent,
             std::vector<bool> &ap,  int node, int &time)
{
    time++;
    disc[node] = time;
    low[node] = time;
    int children{0};
    for (auto ele: graph[node])
    {
        if (disc[ele] == -1)
        {
            parent[ele] = node;
            children++;
            APUtils(graph, disc, low, parent, ap, ele, time);

            if (parent[node] == -1 && children > 1)
                ap[node] = true;
            else if (parent[node] != -1 && low[ele] >= disc[node])
                ap[node] = true;
            
            low[node] = std::min(low[node], low[ele]);
        }
        else
        {
            if (ele != parent[node])
                low[node] = std::min(low[node], disc[ele]);
        }   
    }
}

std::vector<bool> findAP(const std::vector<std::set<int>> &graph)
{
    size_t size = graph.size();
    std::vector<int> disc, low, parent;
    std::vector<bool> ap{};
    int time{0}, node{0};
    for (int i =0; i<size; i++)
    {
        disc.push_back(-1);
        low.push_back(INT_MAX);
        ap.push_back(false);
        parent.push_back(-1);
    }
    APUtils(graph, disc, low, parent, ap, node, time);
    return ap;
}

void bridgeUtils(const std::vector<std::set<int>> &graph,
                int *disc, int *low, int *parent, int node, int &time)
{
    disc[node] = low[node] = ++time;
    for (auto ele : graph[node])
    {
        if (disc[ele] == -1)
        {
            parent[ele] = node;
            bridgeUtils(graph, disc, low, parent, ele, time);
            
            if (low[ele] > disc[node])
                std::cout << node << "-" << ele << std::endl;
            
            low[node] = std::min(low[node], low[ele]);
        }
        else
        {
            if (ele != parent[node])
                low[node] = std::min(low[node], disc[ele]);
        }
        
    }
}

void discLowUtils(const std::vector<std::set<int>> &graph,
                int *disc, int *low, int *parent, int node, int &time)
{
    disc[node] = low[node] = ++time;
    for (auto ele : graph[node])
    {
        if (disc[ele] == -1)
        {
            parent[ele] = node;
            discLowUtils(graph, disc, low, parent, ele, time);
            
            low[node] = std::min(low[node], low[ele]);
        }
        else
        {
            if (ele != parent[node])
                low[node] = std::min(low[node], disc[ele]);
        }
        
    }
}

std::pair<int*, int*> getDiscLow(const std::vector<std::set<int>> &graph)
{
    size_t size = graph.size();
    int parent[size];
    int *disc = new int[size];
    int *low = new int[size];
    int time{0}, node{0};

    for (int i=0; i<size; i++)
    {
        disc[i] = -1;
        low[i] = INT_MAX;
        parent[i] = -1;
    }
    discLowUtils(graph, disc, low, parent, node, time);

    for (int i=0; i<size; i++)
        std::cout << disc[i] << " ";
    
    std::cout << std::endl;
    for (int i=0; i<size; i++)
        std::cout << low[i] << " ";

    return std::make_pair(disc, low);
}

void findRoot(const std::vector<std::set<int>> &graph)
{
    int *low, *disc;
    std::pair<int*, int*> data = getDiscLow(graph);
    disc = data.first;
    low = data.second;
}

void findBridge(const std::vector<std::set<int>> &graph)
{
    size_t size = graph.size();
    int disc[size], low[size], parent[size];
    int time{0}, node{0};

    for (int i=0; i < size; i++)
    {
        disc[i] = -1;
        low[i] = INT_MAX;
        parent[i] = -1;
    }
    bridgeUtils(graph, disc, low, parent, node, time);
}


int main()
{
    std::vector<std::set<int>> graph{{1,2}, {0, 2}, {0, 1, 3, 4, 6}, {2, 5}, {2, 5}, {3, 4}, {2}};
    std::vector<bool> ap;
    ap = findAP(graph);
    size_t size = graph.size();
    findBridge(graph);
    findRoot(graph);
    for (int i=0; i<size; i++)
    {
        if (ap[i])
            std::cout << i << " ";
    }
    return 0;
}