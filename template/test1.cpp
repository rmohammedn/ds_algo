#include<iostream>
#include<array>

template<typename T1, std::size_t size>
void print(std::array<T1, size> &arr)
{
    for (auto ele : arr)
        std::cout << ele << " ";
}

template<std::size_t size>
void print(std::array<float, size> &arr)
{
    std::cout << "its float" << std::endl;
    for (auto ele : arr)
        std::cout << ele << " ";
}

int main()
{
    std::array<int, 3> arr{1,3,4};
    std::array<float, 2> ar2{1.3, 3.4};
    print(arr);
    print(ar2);
    return 0;
}
