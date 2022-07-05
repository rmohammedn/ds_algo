#include<iostream>

class first
{
    public:
    int name{0};
};

inline namespace x
{
    int s = 7;
};

namespace y
{
    int s = 9;
}

int i{10};

int check(int f=0)
{
    return 5;
}
const int& check()
{
    return 6;
}

int main()
{
    const int &x{5};
    int y = x + 3;
    std::cout << check()<< std::endl;
    return 0;
}