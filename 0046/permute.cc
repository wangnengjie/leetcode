#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> result;

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> bitmap(nums.size(), false);
        result.reserve(g(nums.size()));
        dfs(nums, bitmap);
        return result;
    }

    long long g(int num)
    {
        long long a = 1;
        for (int i = 1; i <= num; i++)
            a *= i;
        return a;
    }

    void dfs(const vector<int> &nums, vector<bool> &bitmap)
    {
        static vector<int> re;
        if (re.size() == nums.size())
        {
            result.push_back(re);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!bitmap[i])
            {
                re.push_back(nums[i]);
                bitmap[i] = true;
                dfs(nums, bitmap);
                bitmap[i] = false;
                re.pop_back();
            }
        }
    }
};