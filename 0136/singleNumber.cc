#include <vector>
using std::vector;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int re = 0;
        for (const auto &n : nums)
            re ^= n;
        return re;
    }
};