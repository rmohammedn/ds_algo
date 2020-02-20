#include <iostream>
#include <cmath>

int sqrt(int A)
{
    double temp;
    double square{1};
    double start{0};
    double end = static_cast<double>(A);
    
    if (A == 1 | A == 2 | A == 3)
        return 1;
    
    while((square - A) < 0 | (square - A) > 0.5 )
    {
        temp = (start + end)/2;
        square = temp * temp;
        std::cout << square <<" ,"<< square - A << std::endl;
        if (square > A)
        {
            end = temp;
        }
        else
        {
            start = temp;
        }
    }
    return floor(temp);
}

int main()
{
    std::cout << sqrt(8) << std::endl;
    return 0;
}