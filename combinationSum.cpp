#include <iostream>
#include <vector>
#include <algorithm>

void print2D(std::vector<std::vector<int>> &vec)
{
    for (auto ele : vec)
    {
        for (auto num : ele)
            std::cout << num <<", ";
        std::cout<< std::endl;
    }
}

bool same(std::vector<int> &vec, std::vector<int> &subset)
{
    int size_vec = vec.size();
    int size_sub = subset.size();
    if (size_vec != size_sub)
        return false;
    else
    {
        for (int i=0; i<size_vec; i++)
        {
            if (vec[i]!=subset[i])
                return false;
        }
    }
    return true;
}

void checkFinalSum(std::vector<std::vector<int>> &ans,
                   std::vector<int> &multiple,
                   std::vector<int> &subset, int B, int sum, int indx)
{
    if (sum == B)
    {
        if (ans.size() == 0)
            ans.push_back(subset);
        else
        {
            auto &vec = *ans.rbegin();
            if (!same(vec, subset))
                ans.push_back(subset);
            //std::cout << indx << std::endl;
        }
    }
    int ele{0};
    for (int i=indx; i<multiple.size(); i++)
    {
        if (ele == multiple[i])
            continue;
        subset.push_back(multiple[i]);
        sum += multiple[i];
        checkFinalSum(ans, multiple, subset, B, sum, i+1);
        sum -= multiple[i];
        ele = multiple[i];
        subset.pop_back();
    }
}

std::vector<std::vector<int> > combinationSum(std::vector<int> &A, int B)
{
    std::sort(A.begin(), A.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> subset;
    std::vector<int> multiple;
    int indx, i, factor, pre{0};
    for (int ele : A)
    {
        if (pre == ele)
            continue;
        i = 0;
        factor = B/ele;
        while (i < factor)
        {
            multiple.push_back(ele);
            i++;
        }
        pre = ele;
    }
    checkFinalSum(ans, multiple, subset, B, 0, 0);
    print2D(ans);
    return ans;
}

int main()
{
    std::vector<int> vec{1, 2,3, 7, 3, 4, 2};
    int B{28};
    combinationSum(vec, B);
    return 0;
}