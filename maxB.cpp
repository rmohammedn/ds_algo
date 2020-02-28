#include <iostream>
#include <vector>

using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B) 
{
    int size = A.size();
    int ele = A[0];
    int sum{0}, max_v{0};
    std::vector<int> vec;
    int i = 0;
    if (B <= size)
    {
        for (i; i<B; i++)
            sum += A[i];
        vec.push_back(sum);
        for (i = B; i<size; i++)
        {
            ele = A[i-B];
            std::cout << ele <<"," << sum << "," << A[i] << std::endl;
            sum = sum - ele + A[i];
            vec.push_back(sum);
        }
        return vec;
    }
    else
    {
        for (i; i<size; i++)
        {
            if (A[i] > max_v)
                max_v = A[i];
        }
        vec.push_back(max_v);
        return vec;
    }
}

int main()
{
    std::vector<int> vec{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vec = slidingMaximum(vec, 2);
    return 0;
}
