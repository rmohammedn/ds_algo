#include<vector>
#include<list>
#include<utility>
#include<algorithm>
#include<iterator>
#include<iostream>

void print(std::vector<std::pair<int, int>> &vec)
{
    for (auto &ele : vec)
        std::cout << ele.first << ele.second << std::endl;
}

bool compare(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
{
    return lhs.first > rhs.first;
}
void arrange(std::vector<int> &A, std::vector<int> &B)
{
    int size = A.size();
    std::vector<std::pair<int, int>> vec;
    for (int i=0; i<size; i++)
        vec.push_back(std::make_pair(A[i], B[i]));
    

    std::sort(vec.begin(), vec.end(), compare);
    print(vec);
    std::pair<int, int> top, next;
    std::list<std::pair<int, int>> arr;
    arr.push_front(vec[0]);
    for (int i=1; i<size; i++)
    {
        top = arr.front();
        next = vec[i];
        if (next.second > top.second)
        {
            auto it = arr.begin();
            for (int j=0; j<next.second; j++)
            {
                it++;
                if (it == arr.end())
                    break;
            }
            arr.insert(it, next);
        }
        else
            arr.push_front(next);
    }
    
    for (auto &ele: arr)
        std::cout << ele.first << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{5,3,2,6,1,4};
    std::vector<int> pos{0,1,2,0,3,2};
    arrange(vec, pos);
    return 0;
}