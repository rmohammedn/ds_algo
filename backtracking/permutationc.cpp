#include<iostream>
#include<vector>

void getPermute(std::vector<std::vector<int>> &vec, std::vector<int> &A, int l, int r)
{
    if (l == r)
        vec.push_back(A);
    else
    {
        for (int i=l; i<r; i++)
        {
            std::swap(A[l], A[i]);
            getPermute(vec, A, l+1, r);
            std::swap(A[l], A[i]);
        }
    }
}
void print2D(std::vector<std::vector<int>> &vec)
{
    for (auto &arr: vec)
    {
        for (auto &ele: arr)
            std::cout << ele;
        std::cout << std::endl;
    }
}


void permute(std::vector<int> &A) 
{
    std::vector<std::vector<int>> vec;
    
    //static int l{0};
    int r = A.size();
    getPermute(vec, A, 0, r);

    print2D(vec);
}

int main()
{
    std::vector<int> a{1,2,3};
    //permute(a);
    int n{4};
    int &m = n;
    int k = m;
    std::cout << k << std::endl;
    k++;
    std::cout << k << n << m << std::endl;
    return 0;
}