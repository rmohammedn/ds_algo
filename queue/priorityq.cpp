#include <iostream>
#include <vector>


void heapifyDown(std::vector<int> &vec, int size, int i);

int extractNode(std::vector<int> &vec, int size, int indx)
{
    std::swap(vec[indx], vec[size-1]);
    heapifyDown(vec, size-1, indx);

    return size-1;
}

bool search(std::vector<int> &vec, int size, int key)
{
    for (auto ele : vec)
    {
        if (ele == key)
        {
            std::cout << true << " " << vec[0] << std::endl;
            extractNode(vec, size, 0);
            return true;
        }   
    }
    return false;
}

void heapifyDown(std::vector<int> &vec, int size, int i)
{
    int largest = i;
    int l, r;
    l = 2*i + 1;
    r = 2*i + 2;

    if (l < size && vec[l] > vec[largest])
        largest = l;
    if (r < size && vec[r] > vec[largest])
        largest = r;
    
    if (i != largest)
    {
        std::swap(vec[largest], vec[i]);
        heapifyDown(vec, size, largest);
    }
}

void makePriorityQ(std::vector<int> &vec)
{
    size_t size = vec.size();
    for (int i=(size-1)/2; i>=0; i--)
        heapifyDown(vec, size, i);
}

void printVector(const std::vector<int> &vec)
{
    for (auto ele : vec)
        std::cout << ele << ", ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 2, 3, 1};
    std::vector<int> m{1, 3, 2, 9, 10};
    size_t size = vec.size();
    makePriorityQ(vec);
    for (auto ele : m)
    {
        if (search(vec, size, ele))
            size--;
        else 
            std::cout << "-1" << std::endl;
    }
    printVector(vec);
    return 0;
}