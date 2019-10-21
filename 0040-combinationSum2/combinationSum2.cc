#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(candidates, temp, target, 0);
        return result;
    }

    void dfs(vector<int> &candidates, vector<int> &arr, int target, int index)
    {
        for (int i = index; i < candidates.size();)
        {
            if (candidates[i] > target)
                return;
            else if (candidates[i] == target)
            {
                arr.push_back(candidates[i]);
                result.push_back(vector<int>(arr));
                arr.pop_back();
                return;
            }
            else
            {
                arr.push_back(candidates[i]);
                dfs(candidates, arr, target - candidates[i], i + 1);
                arr.pop_back();
            }
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                i++;
            i++;
        }
    }
};