#include <iostream>

template <typename T>
struct Node
{
    T num;
    Node<T> *next{};
    Node<T> *pre{};
};

template <class T>
class Vector
{
public:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *start;


};


int main()
{
    Node<int> n;
    n.num = 10;
    std::cout << n.num << std::endl;
    return 0;
}