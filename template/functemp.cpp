#include<iostream>
#include<array>

template<class T, int size>
class Template
{
    public:
    std::array<T, size> arr;
};

template<typename T1, int size>
void print(Template<T1, size> &obj)
{
    for (auto ele : obj.arr)
        std::cout << ele << " ";
}

template<int size>
void print(Template<float, size> &obj)
{
    for (auto ele : obj.arr)
        std::cout << ele << " ";
}

int main()
{
    Template<int, 3> array;
    array.arr[0] = 1;
    array.arr[1] = 2;
    array.arr[2] = 3;
    Template<float, 2> arr2;
    arr2.arr[0] = 2.3;
    arr2.arr[1] = 2.9;
    print(array);
    print(arr2);
    return 0;
}