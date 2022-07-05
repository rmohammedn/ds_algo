#include<iostream>
#include<unordered_map>
#include<vector>

std::vector<int> dNums(std::vector<int> &A, int B)
{
    int n = A.size();
    std::vector<int> ans;
    if (B > n)
        return ans;
        
    std::unordered_map<int, int> uno_m;
    int count = 0;
    for (int i=0; i<B; i++)
    {
        if (uno_m.find(A[i]) == uno_m.end())
        {
            uno_m[A[i]] = 1;
            count++;
        }
        else
        {
            if (uno_m[A[i]] == 0)
                count++;
            uno_m[A[i]]++;
        }
    }
    ans.push_back(count);

    int j = 0;
    for (int i=B; i<n; i++)
    {
        if (uno_m[A[j]] == 1)
        {
            uno_m[A[j]]--;
            j++;
            count--;
        }
        else
        {
            uno_m[A[j]]--;
            j++;
        }

        if (uno_m.find(A[i]) == uno_m.end())
        {
            
            uno_m[A[i]] = 1;
            count++;
        }
        else
        {
            if (uno_m[A[i]] == 0)
                count++;
            uno_m[A[i]]++;
        }
        std::cout << count << " ";
        ans.push_back(count);
    }
    return ans;
}

int main()
{
    std::vector<int> vec{1, 2, 1, 3, 4, 3};
    dNums(vec, 3);
    return 0;
}