#include <iostream>
#include <vector>
#include <algorithm>

void combineSum(std::vector<std::vector<int>> &ans,
                std::vector<int> &subset,
                std::vector<int> &A, int B, int indx, int sum)
{
    int ele{0};
    if (sum == B)
        ans.push_back(subset);
    for (int i=indx; i<A.size(); i++)
    {
        if (A[i] > B || ele == A[i])
            continue;
        subset.push_back(A[i]);
        sum += A[i];
        combineSum(ans, subset, A, B, i+1, sum);
        sum -= A[i];
        ele = A[i];
        subset.pop_back();
    }
}

std::vector<std::vector<int> > combinationSum(std::vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    std::sort(A.begin(), A.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> subset;
    int indx{0};
    
    combineSum(ans, subset, A, B, indx, 0);
    return ans;
}

int main()
{
    std::vector<int> vec{8, 10, 6, 11, 1, 16, 8};
    combinationSum(vec, 28);
    return 0;
}
