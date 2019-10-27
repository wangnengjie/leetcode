#include <vector>

using std::vector;

class Solution
{
public:
    enum D
    {
        Right,
        Down,
        Left,
        Up
    };
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        D cur = Right;
        int max = n * n;
        for (int i = 1, row = 0, col = 0; i <= max; i++)
        {
            result[row][col] = i;
            switch (cur)
            {
            case Right:
                if (col == n - 1 || result[row][col + 1] != 0)
                    cur = Down;
                break;
            case Down:
                if (row == n - 1 || result[row + 1][col] != 0)
                    cur = Left;
                break;
            case Left:
                if (col == 0 || result[row][col - 1] != 0)
                    cur = Up;
                break;
            case Up:
                if (row == 0 || result[row - 1][col] != 0)
                    cur = Right;
                break;
            default:
                break;
            }
            switch (cur)
            {
            case Right:
                col++;
                break;
            case Down:
                row++;
                break;
            case Left:
                col--;
                break;
            case Up:
                row--;
                break;
            default:
                break;
            }
        }
        return result;
    }
};