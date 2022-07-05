#include<iostream>
#include<vector>
#include<unordered_map>

void countSubArray1more1(std::vector<int> &vec)
{
    size_t size = vec.size();
    std::unordered_map<int, int> uno_map;
    std::vector<int> sumleft;
    int sum{0};

    for (auto ele: vec)
    {
        (ele == 0)? (sum += -1): (sum += 1);
        sumleft.push_back(sum);
    }
    int start_indx, end_indx, max_size{0};

    for (int i=0; i<size; i++)
    {
        if (sumleft[i] == 1)
        {
            start_indx = 0;
            end_indx = i;
            max_size = i+1;
        }
        else if (uno_map.find(sumleft[i]) != uno_map.end())
        {
            if (i - uno_map[sumleft[i]] > max_size)
            {
                start_indx = uno_map[sumleft[i]];
                end_indx = i;
                max_size = end_indx - start_indx + 1;
            }
        }
        else
            uno_map[sumleft[i]] = i;
    }

    std::cout << start_indx << "-" << end_indx << ":" << max_size << std::endl;
}

int main()
{
    std::vector<int> vec{1,0,1,1,1,0,0};
    countSubArray1more1(vec);
    return 0;
}
