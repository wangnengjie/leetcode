#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> arr(amount + 1, -1);
        arr[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            int minValue = i + 1;
            for (const auto &v : coins)
            {
                if (i - v < 0 || arr[i - v] == -1)
                    continue;
                minValue = std::min(minValue, arr[i - v]);
            }
            if (minValue != i + 1)
                arr[i] = minValue + 1;
        }
        return arr[amount];
    }
};