#include <vector>
#include <iostream>
#include <climits>

class MinHeap
{
    public:
    size_t capacity;
    std::vector<int> arr;
    int size;
    MinHeap(std::vector<int> &vec);
    void heapifyDawn(int indx);
    void heapifyUp(int indx);
    int getMin();
    int parent(int indx);
    int left(int indx);
    int right(int indx);
    void changeData(int indx, int val);
    int extract(int indx=0);
    void deleteKey(int indx);
    void insert(int key);
    void sort();
    void print();
    void init();
};
MinHeap::MinHeap(std::vector<int> &vec)
{
    arr = vec;
    size = arr.size();
    init();
}
void MinHeap::init()
{
    for (int i=size/2-1; i >= 0; i--)
        heapifyDawn(i);
}

void MinHeap::heapifyDawn(int indx)
{
    int l = left(indx);
    int r = right(indx);
    int smallest{indx};
    if (l < size && arr[l] < arr[smallest])
        smallest = l;
    if (r < size && arr[r] < arr[smallest])
        smallest = r;
    
    if (smallest != indx)
    {
        std::swap(arr[smallest], arr[indx]);
        heapifyDawn(smallest);
    }
}

void MinHeap::heapifyUp(int indx)
{
    int p = parent(indx);
    while(arr[p] > arr[indx] && indx != 0)
    {
        std::swap(arr[p], arr[indx]);
        indx = p;
        p = parent(p);
    }
}

int MinHeap::left(int indx)
{
    return 2*indx + 1;
}

int MinHeap::right(int indx)
{
    return 2*indx + 2;
}

int MinHeap::parent(int indx)
{
    return (indx - 1)/2;
}

int MinHeap::getMin()
{
    return arr[0];
}

void MinHeap::changeData(int indx, int val)
{
    int data = arr[indx];
    arr[indx] = val;
    if (val < data)
        heapifyUp(indx);
    else
        heapifyDawn(indx);
}

int MinHeap::extract(int indx)
{
    int data = arr[indx];
    std::swap(arr[indx], arr[--size]);
    heapifyDawn(indx);
    return data;
}

void MinHeap::deleteKey(int indx)
{
    arr[indx] = INT_MAX;
    size--;
    heapifyDawn(indx);
}

void MinHeap::insert(int val)
{
    if (size < arr.size())
    {
        arr[size] = val;
        heapifyUp(size);
        size++;
    }
    else
    {
        arr.push_back(val);
        heapifyUp(size);
        size++;
    }
}

void MinHeap::sort()
{
    int initial_size = size;
    for (int i=size/2-1; i >= 0; i--)
    {
        heapifyDawn(i);
    }
    for (int i=size - 1; i>0; i--)
    {
        std::swap(arr[0], arr[i]);
        size--;
        heapifyDawn(0);
    }
    size = initial_size;
}

void MinHeap::print()
{
    for (auto ele : arr)
        std::cout << ele << ", ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{2,1,4,3,6,5,7};
    MinHeap heap(vec);
    heap.print();
    heap.insert(0);

    heap.print();
    return 0;
}