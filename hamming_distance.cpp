#include <iostream>
#include <vector>

int getHammingDist(int a, int b)
{
    int onebit{0};
    int zor = a ^ b;
    while (zor > 0)
    {
        onebit += zor & 1;
        zor >>= 1;
    }
    return onebit;
}

int hammingDistance(const std::vector<int> &A) 
{
    int sum{0};
    std::vector<int>::const_iterator i, j;
    for (i = A.begin(); i != A.end(); ++i)
    {
        j = std::next(i,1);
        for (j; j != A.end(); ++j)
        {
            sum += getHammingDist(*i, *j);
            std::cout << sum << *i << *j << std::endl;
        }
    }
    return sum * 2;
}

int main()
{
    std::vector<int> vec{2,4,6};
    int sum = hammingDistance(vec);
    std::cout << sum << std::endl;
    return 0;
}