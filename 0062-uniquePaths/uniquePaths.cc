#include <vector>

using std::vector;

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));
        arr[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        return arr[m][n];
    }
};