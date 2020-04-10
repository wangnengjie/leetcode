#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

class Solution
{
public:
    vector<vector<bool>> row, col, block;
    void solveSudoku(vector<vector<char>> &board)
    {
        row = vector<vector<bool>>(9, vector<bool>(9, false));
        col = vector<vector<bool>>(9, vector<bool>(9, false));
        block = vector<vector<bool>>(9, vector<bool>(9, false));
        initialize(board);
        fillBoard(0, board);
        return;
    }

    void initialize(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int index = board[i][j] - '0' - 1;
                    row[i][index] = true;
                    col[j][index] = true;
                    block[getBlock(i, j)][index] = true;
                }
            }
        }
        return;
    }

    bool fillBoard(int count, vector<vector<char>> &board)
    {
        if (count == 81)
            return true;

        int i = count / 9, j = count % 9;

        if (board[i][j] != '.')
        {
            if (fillBoard(count + 1, board))
                return true;
            else
                return false;
        }

        int blockIndex = getBlock(i, j);

        for (int num = 0; num < 9; num++)
        {
            if (!row[i][num] && !col[j][num] && !block[blockIndex][num])
            {
                board[i][j] = '0' + num + 1;
                row[i][num] = true;
                col[j][num] = true;
                block[blockIndex][num] = true;
                if (!fillBoard(count + 1, board))
                {
                    board[i][j] = '.';
                    row[i][num] = false;
                    col[j][num] = false;
                    block[blockIndex][num] = false;
                }
                else
                    return true;
            }
        }
        return false;
    }

    int getBlock(const int &i, const int &j)
    {
        return (i / 3) + ((j / 3) * 3);
    }
};
