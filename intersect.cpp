#include <iostream>
#include <vector>

std::vector<int> intersect(const std::vector<int> &A, const std::vector<int> &B) 
{
    int size_a = A.size();
    int size_b = B.size();
    int n = size_a + size_b;
    int indxa{0}, indxb{0};
    std::vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (indxa >= size_a || indxb >= size_b)
            break;
        
        if (A[indxa] == B[indxb])
        {
            ans.push_back(A[indxa]);
            indxa++;
            indxb++;
        }
        else if (A[indxa] < B[indxb])
            indxa++;
        else
            indxb++;
    }
    return ans;
}

int main()
{
    std::vector<int> A{1,2,3,4,5,5};
    std::vector<int> B{2,4,5,7,8};
    std::vector<int> ans = intersect(A, B);
    return 0;
}