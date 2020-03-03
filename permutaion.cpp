#include <iostream>
#include <vector>

void print(std::vector<int> &A)
{
    for (auto ele:A)
        std::cout<< ele << " ";
    std::cout << std::endl;
}

std::vector<std::vector<int>> getPermute(std::vector<int> &A, int l, int r)
{
    std::vector<std::vector<int>> vec;
    if (l == r)
    {
        vec.push_back(A);
        print(A);
    }
    else
    {
        for (int i=l; i<r; i++)
        {
            std::swap(A[l], A[i]);
            vec = getPermute(A, l+1, r);
            std::swap(A[l], A[i]);
        }
    }
    return vec;
}


std::vector<std::vector<int> > permute(std::vector<int> &A) 
{
    int size = A.size();
    return getPermute(A, 0, size);
}

int main()
{
    std::vector<int> vec{1,2,3};
    permute(vec);
    return 0;
}