#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            int minStep = dp[i - 1], e = std::sqrt(i);
            for (int j = 1; j <= e; j++)
            {
                minStep = std::min(dp[i - j * j], minStep);
            }
            dp[i] = minStep + 1;
        }
        return dp[n];
    }
};