#include <iostream>

int gcd(int n, int m)
{
    int max, min;
    int rem;
    if (n > m)
    {
        max = n;
        min = m;
    }
    else
    {
        max = m;
        min = n;
    }
    rem = max % min;
    while (rem != 0)
    {
        min = rem;
        max = min;
        rem = max % min;
    }
    return min;
}

int power(int A)
{
    int n = A;
    int i = 2;
    int count{0};
    int rem{0};
    int power{0};
    int temp{0};
    
    while (i < 256)
    {
        rem = n % i;
        if (rem == 0)
        {
            n = n / i;
            count = count + 1;
        }
        else
        {
            std::cout << n << ", "<< count << std::endl;
            if (power == 0 && count != 0)
                power = count;
            if (power != count && count != 0)
            {
                temp = gcd(power, count);
                if (temp == 1)
                    return 0;
                else
                    power = temp;
            }
            if (count == 1)
                return 0;
            if (n == 1)
                return 1;
            if (i > n)
                return 0;
            if (i == 2)
                i = 3;
            else
                i = i + 2;
            count = 0;
        }
    }
}

int main()
{
    int n = 536870912;
    std::cout << power(n) << std::endl;
    return 0;
}