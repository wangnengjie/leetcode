#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return 0;
        int step = 0;
        for (int next = 0; next + nums[next] < nums.size() - 1; step++)
        {
            int maxLen = 0;
            int t = next;
            for (int j = t + 1; j < nums.size() && j <= t + nums[t]; j++)
            {
                if (j + nums[j] > maxLen)
                {
                    maxLen = j + nums[j];
                    next = j;
                }
            }
        }
        return step + 1;
    }
};
