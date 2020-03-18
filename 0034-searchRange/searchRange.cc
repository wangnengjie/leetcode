#include <vector>

using std::vector;

class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> re(2, -1);
        if (nums.empty())
            return re;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
            {
                re[0] = mid;
                right = mid - 1;
            }
        }
        left = re[0] == -1 ? 0 : re[0];
        right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
            {
                re[1] = mid;
                left = mid + 1;
            }
        }
        return re;
    }
};