#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

void sum2(std::vector<int> &arr, int n)
{
    int temp;
    std::unordered_set<int> s;
    for (int i=0; i<arr.size(); i++)
    {
        temp = n - arr[i];
        if (s.find(temp) != s.end())
            std::cout << temp <<", "<< arr[i] << std::endl;
        
        s.insert(arr[i]);
    }
}
void print(std::vector<int> &vec)
{
    for (auto x : vec)
        std::cout << x << ", ";
    std::cout << std::endl;
}

void sum2map(std::vector<int> &arr, int n)
{
    int temp;
    int num;
    std::unordered_map<int, int> m;
    std::vector<int> vec;
    int min{-1}, max{-1};
    for (int i=0; i<arr.size(); i++)
    {
        
        temp = n - arr[i];
        if (temp != arr[i] && m.find(arr[i]) != m.end())
            continue;
        if (m.find(temp) != m.end())
        {
            num = m[temp];
            if (max == -1)
            {
                max = i;
                min = num;
            }
            else if (max < i)
                continue;
            else 
            {
                max = i;
                min = num;
            }
        }
        m[arr[i]] = i;
    }
}

int diffPossible(const std::vector<int> &A, int B) 
{
    if (A.size() == 1)
        return 0;
    int temp;
    int num;
    std::unordered_set<int> s;
    std::vector<int> vec;
    for (int i=0; i<A.size(); i++)
    {
        temp = abs(B + A[i]);
        if (s.find(temp) != s.end())
        {
            std::cout << A[i] << ", " << i << std::endl;
            return 1;
        }
        s.insert(A[i]);
    }
    return 0;
}

int main()
{
    std::vector<int> vec{10,3,3,3,4,5,6,7,9,-1,-3};
    diffPossible(vec, 6);
    return 0;
}