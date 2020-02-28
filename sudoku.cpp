#include <iostream>
#include <vector>

constexpr int col=9;
constexpr int row=9;

bool conflict(std::vector<std::string> &A, int r, int c, char num)
{
    //std::cout << num;
    for (int i=0; i<row; i++)
    {
        if (i == r)
            continue;
        if (num == A[i][c])
            return true;
    }
    
    for (int i=0; i<col; i++)
    {
        if (i == c)
            continue;
        if (num == A[r][i])
            return true;
    }
    
    int max_r = r - (r%3);
    int max_c = c - (c%3);

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (i+max_r == r && j+max_c == c)
                continue;
            if (num == A[i+max_r][j+max_c])
                return true;
        }
    }
    return false;
}

void solveSudoku(std::vector<std::string> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    char start = '1';
    static int flag = 0;
    int i, j;
    
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            //std::cout << A[i][j];
            if (A[i][j] == '.')
            {
                while (flag == 0)
                {       
                    if (start > '9')
                    {
                        A[i][j] = '.';
                        return;
                    }
                    if (conflict(A, i, j, start))
                        start++;
                    else
                    {
                        A[i][j] = start;
                        solveSudoku(A);
                        start++;
                    }
                }
                //std::cout << std::endl << i << j << start <<std::endl;
            }
        }
    }
    flag = 1;
    //std::cout<<std::endl << i << j<< start <<std::endl;
    return;
}
void print(std::vector<std::string> &vec)
{

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            //if (conflict(vec, i, j, vec[i][j]))
                std::cout << vec[i][j];
        }
        std::cout<<std::endl;
    }
        
}

int main()
{
    std::vector<std::string> vec{"53..7....",
                                  "6..195...",
                                  ".98....6.", 
                                  "8...6...3",
                                  "4..8.3..1",
                                  "7...2...6",
                                  ".6....28.",
                                  "...419..5",
                                  "....8..79"};
    solveSudoku(vec);
    print(vec);
    return 0;
}