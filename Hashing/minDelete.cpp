#include<iostream>
#include<unordered_map>
#include<vector>

int minDelete(const std::vector<int> &vec)
{
    std::unordered_map<int, int> uno_map;
    int max{0};
    for (auto ele : vec)
    {
        if (uno_map.find(ele) != uno_map.end())
            uno_map[ele] += 1;
        else
            uno_map[ele] = 1;
    }

    for (auto ele : uno_map)
        max = std::max(ele.second, max);
    
    return vec.size() - max;
}

int main()
{
    std::vector<int> vec{1,1,1,1,1,1};
    int num = minDelete(vec);
    std::cout << num << std::endl;
    return 0;
}