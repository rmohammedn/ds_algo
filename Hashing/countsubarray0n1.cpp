#include<iostream>
#include<unordered_map>
#include<vector>

void countsubarray0n1(std::vector<int> &arr)
{
    size_t size = arr.size();
    std::unordered_map<int, int> uno_m;
    std::vector<int> sumleft;
    int sum{0};

    for (auto ele : arr)
    {
        (ele == 0)? (sum += -1): (sum += 1);
        sumleft.push_back(sum);
    }

    for (auto ele : sumleft)
    {
        if (uno_m.find(ele) != uno_m.end())
            uno_m[ele] += 1;
        else
            uno_m[ele] = 1;
    }
    int count{0};
    for (auto it : uno_m)
    {
        if (it.first == 0)
            count += it.second * (it.second + 1) / 2;

        else if(it.second > 1)
            count += it.second * (it.second - 1) / 2;
        else 
            continue;
    }
    std::cout << count << std::endl;
}

int main()
{
    std::vector<int> vec{1, 0, 0, 1, 0, 1, 1};
    countsubarray0n1(vec);
    return 0;
}