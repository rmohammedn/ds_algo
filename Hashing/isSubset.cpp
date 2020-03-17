#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

bool isSubset(std::vector<int> &set1, std::vector<int> &set2)
{
    std::unordered_set<int> un_set;
    for (auto ele : set1)
        un_set.insert(ele);

    for (auto ele : set2)
    {
        if (un_set.find(ele) == un_set.end())
            return false;
    }
    return true;
}

int main()
{
    std::vector<int> vec1{1,2,3,4,5,6};
    std::vector<int> vec2{2,4,6, 7};
    if (isSubset(vec1, vec2))
        std::cout << "vec2 is subset of vec1" << std::endl;
    else 
        std::cout << "not a subset" << std::endl;
    return 0;
}