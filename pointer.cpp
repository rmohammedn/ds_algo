#include<iostream>

void assign(int *x, int &y)
{
    x = &y;
    std::cout << *x << std::endl;
}

int main()
{
    int *x;
    int y = 2;
    //x = &y;
    assign(x, y);
    std::cout << *x << std::endl;
    return 0;
}