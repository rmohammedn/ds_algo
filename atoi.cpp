#include <iostream>
#include <bits/stdc++.h> 

int atoi(const std::string A) 
{
    int charecter;
    int num{0};
    int flag{0};
    int plus = '+' - '0';
    int minus = '-' - '0';
    for (auto ele : A)
    {
        charecter = ele - '0';
        if (charecter < 0 | charecter > 9)
        {
            if (charecter == plus)
                continue;
            else if (charecter == minus)
                flag = 1;
            else
                if (flag == 1)
                    return -(num);
                else
                    return num;
        }
        else
        {
            if (INT_MAX / 10 < num)
            {
                if (flag == 1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            num = num * 10 + charecter;
        }
    }
    if (flag == 1)
        return -(num);
    else
        return num;
}

int main()
{
    std::string s = "-87 34";
    std::cout << atoi(s) << std::endl;
    return 0;
}
