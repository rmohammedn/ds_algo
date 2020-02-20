#include "sorting.h"

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
void printCAarry(T arr[], int n)
{
    for (int i=0; i < n; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
}