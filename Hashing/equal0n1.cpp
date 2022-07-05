#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>

void count0n1(std::vector<int> &arr)
{
    std::unordered_map<int, int> uno_m;
    size_t size = arr.size();
    int sum{0};
    std::vector<int> leftsum;
    for (auto ele : arr)
    {
        (ele == 0)? (sum += -1): (sum += 1);
        leftsum.push_back(sum);
    }

    int start_indx, end_indx, max_size{0};
    
    for (int i=0; i<size; i++)
    {
        if (leftsum[i] == 0)
        {
            start_indx = 0;
            end_indx = i;
            max_size = i+1;
        }

        if (uno_m.find(leftsum[i]) != uno_m.end())
        {
            int length =  i - uno_m[leftsum[i]];
            if (length > max_size)
            {
                start_indx = uno_m[leftsum[i]] + 1;
                end_indx = i;
                max_size = length;
            }
        }
        else
            uno_m[leftsum[i]] = i;
    }
    if (max_size == 0)
        std::cout << "No such subarray" << std::endl;
    else
        std::cout << start_indx << "-" << end_indx << ":" << max_size << std::endl;
}

int main()
{
    std::vector<int> vec{1, 1, 0, 0, 1, 1, 0};
    count0n1(vec);
    return 0;
}