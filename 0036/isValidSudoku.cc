#include <vector>

using std::vector;

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        decltype(row) col(9, vector<bool>(9, false));
        decltype(row) block(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++)     // row
            for (int j = 0; j < 9; j++) // col
            {
                if (board[i][j] == '.')
                    continue;
                int v = board[i][j] - '0' - 1;
                if (row[i][v] || col[j][v] || block[getBlock(i, j)][v])
                    return false;
                row[i][v] = col[j][v] = block[getBlock(i, j)][v] = true;
            }
        return true;
    }

    int getBlock(const int &i, const int &j) { return (i / 3) + ((j / 3) * 3); }
};