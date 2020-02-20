#include <iostream>
#include <vector>

std::vector<int>& deleteZero(std::vector<int> &A)
{
    auto start = A.begin();
    if (*start == 0)
    {
        A.erase(start);
        deleteZero(A);
    }
    else
        return A;
}

std::vector<int> plusOne(std::vector<int> &A)
{
    int size = A.size();
    auto i = A.rbegin();
    int carry{1};
    for (i; i != A.rend(); ++i)
    {
        std::cout << *i << "," << carry << std::endl;
        if (*i < 9)
        {
            *i += carry;
            carry = 0;
            break;
        }
        else
        {
            *i = 0;
            carry = 1;
        }
    }
    std::cout << carry << std::endl;
    if (carry == 1)
        A.insert(A.begin(), 1);
    
    return A;
}

int main()
{
    std::vector<int> vec{9};
    vec = plusOne(vec);
    for (auto ele : vec)
        std::cout << ele;
    return 0;
}