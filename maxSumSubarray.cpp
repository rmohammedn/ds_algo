#include <iostream>
#include <vector>

int maxSum(const std::vector<int> &A)
{
    std::vector<int> temp;
    auto i = A.begin();
    int max = *i;
    int temp_max;
    int global_max{max};
    temp.push_back(max);
    i++;
    for (i; i != A.end(); ++i)
    {
        temp_max = max + *i;
        if (temp_max < *i)
        {
            max = *i;
            temp.push_back(max);
            if (max > global_max)
                global_max = max;
        }
        else
        {
            max = temp_max;
            temp.push_back(max);
            if (max > global_max)
                global_max = max;
        }
    }
    return global_max;
}

int main()
{
    std::vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << maxSum(vec) << std::endl;
    return 0;
}