#include <iostream>
#include <vector>
#include <stack>
#include <utility>

std::pair<int, int> checkSurr(std::vector<std::vector<int>> &matrix, int i, int j)
{
    int startx, starty;
    int endx, endy;
    int x, y;
    x = matrix.size();
    y = matrix[0].size();
    startx = std::max(i-1, 0);
    starty = std::max(j-1, 0);
    endx = std::min(i+2, x);
    endy = std::min(j+2, y);

    matrix[i][j] = 0;

    for (int i=startx; i < endx; i++)
    {
        for (int j=starty; j < endy; j++)
        {
            if (matrix[i][j])
                return std::make_pair(i, j);
        }
    }
    return std::make_pair(-1, -1);
}

int countIsland(std::vector<std::vector<int>> &matrix)
{
    size_t sizex = matrix.size();
    size_t sizey = matrix[0].size();
    int count{0};
    std::pair<int, int> cord, next;
    std::stack<std::pair<int, int>> stk;

    for (int i=0; i<sizex; i++)
    {
        for (int j=0; j<sizey; j++)
        {
            if (matrix[i][j])
            {
                stk.push(std::make_pair(i, j));
                count++;
                while(!stk.empty())
                {
                    cord = stk.top();
                    next = checkSurr(matrix, cord.first, cord.second);
                    if (next.first == -1)
                        stk.pop();
                    else
                        stk.push(next);
                }
            }
        }
    }
    return count;
}

std::pair<int, int> checkSurr2(std::vector<std::vector<int>>& matrix, int i, int j, int x, int y)
{
    int startx = std::max(0, i-1);
    int starty = std::max(0, j-1);
    int endx = std::min(x, i+2);
    int endy = std::min(y, j+2);

    matrix[i][j] = 0;
    for (int k=startx; k<endx; k++)
    {
        for (int l=starty; l<endy; l++)
        {
            if (matrix[k][l])
                return std::make_pair(k, l);
        }
    }
    return std::make_pair(-1, -1);
}

int countIsland2(std::vector<std::vector<int>>& matrix)
{
    size_t sizex = matrix.size();
    size_t sizey = matrix[0].size();
    std::stack<std::pair<int, int>> stk;
    std::pair<int, int> temp, next;
    int count = 0;

    for (int i=0; i<sizex; i++)
    {
        for (int j=0; j<sizey; j++)
        {
            if (matrix[i][j])
            {
                count++;
                stk.push(std::make_pair(i, j));
                while(!stk.empty())
                {
                    temp = stk.top();
                    next = checkSurr2(matrix, temp.first, temp.second, sizex, sizey);
                    if (next.first == -1)
                        stk.pop();
                    else
                    {
                        stk.push(next);
                    }
                    
                }
            }
        }
    }
    return count;
}

int main()
{
    std::vector<std::vector<int>> matrix{{ 1, 1, 0, 0, 0 }, 
                                         { 0, 1, 0, 0, 1 }, 
                                         { 1, 0, 0, 1, 1 }, 
                                         { 0, 0, 0, 0, 0 }, 
                                         { 1, 0, 1, 0, 1 },
                                         { 0, 1, 0, 1, 0 }};
    
    std::cout << countIsland2(matrix) << std::endl;
    return 0;
}