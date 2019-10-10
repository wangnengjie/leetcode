#include <vector>
#include <algorithm>

using std::sort;
using std::swap;
using std::vector;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = len - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                int j;
                for (j = i; j < len - 1; j++)
                {
                    if (nums[i - 1] >= nums[j + 1])
                    {
                        swap(nums[i - 1], nums[j]);
                        break;
                    }
                }
                if (j == len - 1)
                    swap(nums[i - 1], nums[j]);
                sort(nums.begin() + i, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};

int main(void)
{
    Solution a;
    vector<int> b{1, 2, 3};
    a.nextPermutation(b);
    return 0;
}