#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(std::vector<string> &vec)
{
    for (auto ele : vec)
        std::cout << ele << std::endl;
}

bool isSafe(std::vector<string> &board, int col, int raw, int N)
{
    int i, j;
    for (int i=0; i<=col; i++)
    {
        if(board[raw][i] == 'Q')
            return false;
    }
    for (i=raw, j=col; i>=0 && j>=0; i--, j-- )
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (i=raw, j=col; i<N && j>=0; i++, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

bool NQueen(std::vector<string> &board, int col, int N)
{
    if (N==2 && col == 1)
        return true;
    else if (col >= N)
        return true;
    for (int i=0; i<N; i++)
    {
        if(isSafe(board, col, i, N))
        {
            board[i][col] = 'Q';
            if(NQueen(board, col+1, N))
                return true;
            board[i][col] = '.';
        }
    }
    return false;
}

std::vector<std::vector<std::string> > solveNQueens(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> board;
    std::string s;
    for (int i=0; i<A; i++)
        s.push_back('.');
    
    for (int j=0; j<A; j++)
        board.push_back(s);
    
    NQueen(board, 0, A);
    ans.push_back(board);
    print(board);
    return ans;
    
}

int main()
{
    solveNQueens(3);
    return 0;
}