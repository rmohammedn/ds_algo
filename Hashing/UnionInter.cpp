#include<iostream>
#include<vector>
#include<unordered_set>
#include<list>

std::vector<std::list<int>> unionIntersection(const std::list<int> &list1, const std::list<int> &list2)
{
    std::unordered_set<int> un_os;
    std::list<int> uni;
    for (auto ele : list1)
    {
        un_os.insert(ele);
        uni.push_back(ele);
    }

    std::list<int> inter;
    for (auto ele : list2)
    {
        if (un_os.find(ele) != un_os.end())
            inter.push_back(ele);
        else
            uni.push_back(ele);
    }

    std::vector<std::list<int>> ans{uni, inter};
    return ans;
}

void print(const std::vector<std::list<int>> &vec)
{
    for (auto list : vec)
    {
        for (auto ele : list)
            std::cout << ele << ", ";
        std::cout << std::endl;
    }
}

int main()
{
    std::list<int> list1{1,2,3,4,5,6};
    std::list<int> list2{2,4,6,8,0};
    std::vector<std::list<int>> vec = unionIntersection(list1, list2);
    print(vec);
    return 0;
}