#include<iostream>
#include<vector>
#include<string>

void getCps(std::vector<int> &cps, std::string &str)
{
    int size = str.length();
    int len{0}, i{0};
    while(i < size)
    {
        if (len <= 0)
        {
            cps.push_back(0);
            len = 0;
            i++;
        }

        if (str[i] == str[len])
        {
            cps.push_back(++len);
            i++;
        }
        else
        {
            while(len >= 0)
            {
                len--;
                if (str[len] == str[i])
                {
                    cps.push_back(++len);
                    i++;
                    break;
                }
            }
        }
        
    }
}

int matchPattarn(std::string &str1, std::string &str2)
{
    std::vector<int> cps;
    getCps(cps, str2);
    int i{0}, j{0}, match{0};
    int size1 = str1.length();
    int size2 = str2.length();
    while(i <  size1)
    {
        if (str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            while(j > 0)
            {
                j = cps[j-1];
                if (str2[j] == str1[i])
                {
                    i++;
                    j++;
                    break;
                }
            }
            i++;
        }
        if (j == size2)
        {
            match++;
            j = 0;
        }
    }
    return match;
}

int main()
{
    std::string str1 = "cool";
    std::string str2 = "cool";
    std::cout << matchPattarn(str1, str2);
    return 0;
}