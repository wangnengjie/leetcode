#include <vector>

using std::vector;

class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid[0].size(), n = obstacleGrid.size();
        vector<long> arr(m + 1);
        arr[1] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                arr[j] = obstacleGrid[i][j - 1] == 1 ? 0 : arr[j - 1] + arr[j];
        return arr[m];
    }
};