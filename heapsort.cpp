#include <iostream>

template<typename T>
void heapify(T arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (i != largest)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template<typename T>
void heapSort(T arr[], int n)
{
    for (int i=n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n-1; i>=0; i--)
    {
        std::swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

template<typename T>
void printCAarry(T arr[], int n)
{
    for (int i=0; i < n; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = {3,2,4,6,5,7, 5};
    //std::size_t n{std::size(arr)}; c++17 onward
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    std::cout << "sorting the array" << std::endl;
    printCAarry(arr, n);
    return 0;
}