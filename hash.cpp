#include <iostream>
#include <vector>
#include <memory>

#define TABLE_SIZE 13
#define PRIME 7

template<class T>
class DoubleHash
{
    private:
    std::unique_ptr<T[]> hash_table;
    T init;

    public:
    int size;
    bool isFull();
    int hash1(int key);
    int hash2(int key);
    DoubleHash(int x);
    void insert(int key);
    int lookup(int key);
};

template<class T>
DoubleHash<T>::DoubleHash(int x):init(x)
{
    hash_table = std::make_unique<T[]>(TABLE_SIZE);
    size = 0;
    for (int i=0; i<TABLE_SIZE; i++)
        hash_table[i] = init;
}

template<class T>
bool DoubleHash<T>::isFull()
{
    return (size == TABLE_SIZE);
}

template<class T>
int DoubleHash<T>::hash1(int key)
{
    return (key % TABLE_SIZE);
}

template<typename T>
int DoubleHash<T>::hash2(int key)
{
    return (PRIME - key % PRIME);
}

template<typename T>
void DoubleHash<T>::insert(int key)
{
    if (isFull())
    {
        std::cout << "Hash Table is full" << std::endl;
        return;
    }

    int indx1 = hash1(key);
    if (hash_table[indx1] != init)
    {
        int i = 1;
        int indx2 = hash2(key);
        while (true)
        {
            int new_indx = (indx1 + i*indx2)%TABLE_SIZE;
            if (hash_table[new_indx] == init)
            {
                hash_table[new_indx] = key;
                break;
            }
            i++;
        }
    }
    else
        hash_table[indx1] = key;
    size++;
}

template<typename T>
int DoubleHash<T>::lookup(int key)
{
    int indx1 = hash1(key);
    if (hash_table[indx1] == key)
        return indx1;
    else
    {
        int indx2 = hash2(key);
        int i{0};
        while (true)
        {
            int new_indx = (indx1 + i*indx2)%TABLE_SIZE;
            if (hash_table[new_indx] == key)
                return new_indx;
            i++;
            if (i > TABLE_SIZE)
                return init;
        }
    }
    
}


int main()
{
    DoubleHash<int> hash(-1);
    int arr[]{1,2,3,4,7,14};
    for (auto ele : arr)
        hash.insert(ele);
    std::cout << hash.lookup(14) << std::endl;
    return 0;
}