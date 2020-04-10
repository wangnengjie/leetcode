#include <vector>
#include <algorithm>

using std::min;
using std::vector;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<int> path(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < path.size(); j++)
            {
                if (j == 0)
                    path[j] += grid[i][j];
                else if (i == 0)
                    path[j] = grid[i][j] + path[j - 1];
                else
                    path[j] = grid[i][j] + min(path[j], path[j - 1]);
            }
        }
        return path.back();
    }
};