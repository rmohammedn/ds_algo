#include <iostream>
#include <vector>
#include <cstdarg>

class Elipsis
{
public:
    int x;
    int y;
    std::vector<int> arr;
public:
    Elipsis(int x1, ...);
    Elipsis(){};
    ~Elipsis(){};

};

Elipsis::Elipsis(int x1, ...)
{
    arr.push_back(x1);
    va_list list;
    va_start(list, x1)
    
}

int main()
{
    Elipsis obj{2,4};
    std::cout << obj.x << obj.y << std::endl;
    return 0;
}