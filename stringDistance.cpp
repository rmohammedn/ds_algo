#include<iostream>
#include<vector>
#include<string>

int getmin(int x, int y, int z)
{
    int temp = std::min(x, y);
    return std::min(temp, z);
}

int findDistance(const std::string& str1, const std::string& str2)
{
    int len_1 = str1.length();
    int len_2 = str2.length();
    std::vector<std::vector<int>> dp_table;
    std::vector<int> temp;
    for (int i=0; i<=len_2; i++)
    {
        temp.clear();
        for (int j=0; j<=len_1; j++)
        {
            if (i == 0)
                temp.push_back(j);
            else if (j == 0)
                temp.push_back(i);
            else
                temp.push_back(0);
        }
        dp_table.push_back(temp);
    }

    for (int i=1; i<= len_2; i++)
    {
        for (int j=1; j<= len_1; j++)
        {
            if (str2[i] == str1[j])
                dp_table[i][j] = dp_table[i-1][j-1];
            else
            {
                dp_table[i][j] = 1 + getmin(dp_table[i-1][j-1], dp_table[i][j-1], dp_table[i-1][j]);
            }
        }
    }
    return dp_table[len_2][len_1];
}

int main()
{
    std::string str1 = "geek";
    std::string str2 = "gesek";
    std::cout << findDistance(str1, str2) << std::endl;
    return 0;
}