#include<iostream>
#include<deque>
#include<vector>
#include<utility>

std::vector<int> slidingMax(const std::vector<int> &vec, int k)
{
    std::deque<int> q;
    std::vector<int> ans;
    int n = vec.size();
    int i{0};
    for (i; i<k; i++)
    {
        while (!q.empty() && vec[i] >= vec[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for (; i<n; i++)
    {
        ans.push_back(vec[q.front()]);
        if (!q.empty() && q.front() <= i-k)
            q.pop_front();
        
        while (!q.empty() && vec[i] >= vec[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    return ans;
}

void print(const std::vector<int> &vec)
{
    for (auto ele: vec)
        std::cout << ele << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1,2,3,1,4,5,2,3,6};
    std::vector<int> ans = slidingMax(vec, 3);
    print(ans);
    std::pair<int, int> pr = std::make_pair(1,2);
    return 0;

}