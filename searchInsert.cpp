#include <iostream>
#include <vector>

int searchInsert(std::vector<int> &A, int B)
{
    int size = A.size();
    int start{0};
    int end{size-1};
    int indx;
    
    while (start <= end)
    {
        indx = (start + end)/2;
        if (A[indx] == B)
            return indx;
        if (A[indx] > B)
            end = indx - 1;
        else
            start = indx + 1;
    }
    std::cout<< start << ", "<< end << ", "<< A[indx] << std::endl;
    if (A[indx] >= B)
        return indx;
    else
        return indx + 1;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,11,13,14,15,16};
    std::cout << searchInsert(vec, 12) << std::endl;
    return 0;
}