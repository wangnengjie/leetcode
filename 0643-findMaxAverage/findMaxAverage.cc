#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int max = 0, cur = 0;
        for (int i = 0; i < k; i++)
            max += nums[i];
        cur = max;
        for (int i = k; i < nums.size(); i++)
        {
            cur = cur + nums[i] - nums[i - k];
            max = std::max(max, cur);
        }
        return static_cast<double>(max) / k;
    }
};