#include <iostream>
#include <vector>
#include <sstream>

void print(std::vector<int> vec)
{
    for (int ele : vec)
        std::cout << ele;
    std::cout << std::endl;
}

void getPermute(std::vector<int> &A, int B, int l, int r)
{
    static int count{0};
    if (l == r)
    {
        count++;
        std::cout << count;
        if (count == B)
        {
            print(A);
            return;
        }
    }
    else
    {
        for (int i=l; i<r; i++)
        {
            std::swap(A[l], A[i]);
            getPermute(A, B, l+1, r);
            if (count == B)
                return;
            std::swap(A[l], A[i]);
        }
    }
}


std::string getPermutation(int A, int B) 
{
    std::ostringstream ostr;
    std::vector<int> vec;
    for (int i=1; i<=A; i++)
        vec.push_back(i);
    getPermute(vec, B, 0, A);
    print(vec);
    for (int ele:vec)
    {
        ostr << ele;
    }
    
    return ostr.str();
}

int main()
{
    std::cout << getPermutation(3, 4);
    return 0;
}