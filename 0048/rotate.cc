#include <vector>
using std::vector;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        if (matrix.size() <= 1)
            return;
        for (int i = matrix.size(), step = 0; i > 0; i -= 2, step++)
        {
            for (int j = 0, temp; j < i - 1; j++)
            {
                temp = matrix[step][step + j];
                std::swap(temp, matrix[step + j][step + i - 1]);
                std::swap(temp, matrix[step + i - 1][step + i - j - 1]);
                std::swap(temp, matrix[step + i - j - 1][step]);
                std::swap(temp, matrix[step][step + j]);
            }
        }
        return;
    }
};

int main()
{
    Solution a;
    a.rotate(vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}