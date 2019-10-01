#include <vector>

using std::vector;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.empty())
            return 0;
        int len = nums.size();
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            if (nums[j] == val)
                len--;
            else if (i != j)
                nums[i++] = nums[j];
            else
                i++;
        }
        return len;
    }
};