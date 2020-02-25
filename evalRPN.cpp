#include <iostream>
#include <vector>
#include <stack>
//#include <bits/stdc++.h> 

int evalRPN(std::vector<std::string> &A) 
{
    std::stack<int> s;
    int num1, num2, val{0}, flag{0};
    for (auto i = A.begin(); i != A.end(); ++i)
    {
        if (*i == "+")
        {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num1 + num2);
        }
        else if (*i == "*")
        {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num1 * num2);
        }
        else if (*i == "-")
        {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num2 - num1);
        }
        else if (*i == "/")
        {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num2 / num1);
        }
        else
        {
            for (int ele : *i)
            {
                if (ele == '-')
                    flag = 1;
                else if (ele == '+')
                    continue;
                else
                    val = 10 * val + (ele - '0');
            }
            if (flag == 1)
                val = -val;
            s.push(val);
            std::cout << val << std::endl;
            val = 0;
            flag = 0;
        }
    }
    return s.top();
}

int main()
{
    std::vector<std::string> vec{"-1", "1", "-2", "+", "*"};
    std::cout << evalRPN(vec) << std::endl;
    return 0;
}