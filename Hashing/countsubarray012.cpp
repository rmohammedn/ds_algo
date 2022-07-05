#include<iostream>
#include<utility>
#include<map>
#include<vector>

void countSubArray012(std::vector<int> &vec)
{
    size_t size = vec.size();
    std::map<std::pair<int, int>, int> uno_m;
    int zc{0}, oc{0}, tc{0};
    uno_m[std::make_pair(0,0)] = 1;
    int count{0};
    for (auto ele: vec)
    {
        if (ele == 0)
            zc++;
        else if (ele == 1)
            oc++;
        else
            tc++;
        
        std::pair<int, int> temp = std::make_pair(zc-oc, zc-tc);
        count += uno_m[temp];
        uno_m[temp]++;
    }
    std::cout << count << std::endl;
}

int main()
{
    std::vector<int> vec{0,1,0,2,0,1,0};
    countSubArray012(vec);
    return 0;
}