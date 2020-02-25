#include <iostream>
#include <vector>

void print(std::vector<int> &A)
{
    for(auto ele : A)
        std::cout << ele << ", ";
    std::cout << std::endl;
}

void merge(std::vector<int> &A, std::vector<int> &B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int size_a = A.size();
    int size_b = B.size();
    int n = size_a + size_b;
    std::vector<int> ans;
    int indxa{0}, indxb{0};
    for (int i=0; i < n; i++)
    {
        if (indxa < size_a && indxb < size_b && A[indxa] <= B[indxb])
        {
            ans.push_back(A[indxa]);
            indxa++;
        }
        else
        {
            if (indxb < size_b)
            {
                ans.push_back(B[indxb]);
                indxb++;
            }
            else
            {
                ans.push_back(A[indxa]);
                indxa++;
            }
            
        }
        
    }
    print(ans);
    A = ans;
}

int main()
{
    std::vector<int> A{2,4,5,6};
    std::vector<int> B{1,3, 7};
    merge(A, B);
    print(A);
    return 0;
}