#include <iostream>
#include <iterator>

int main()
{
    int arr[50];
    arr[true] = 10;
    int num = '0';
    arr['0'] = 20;
    //std::cout << size << length ;
    //size_t l = std::size(arr);
    int arr2[]{1,2,3,4,5};
    int arr3[][4]{{1,2,3,4}, {1,2,3,4}};
    const char *name = "Alex";
    int *array = new int[5] { 9, 7, 5, 3, 1 };
    int size = sizeof(array);
    int length = size/sizeof(array[0]);
    std::cout << length <<", "<< size << '\n';
    return 0;
}