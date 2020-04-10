#include <vector>
#include <algorithm>

using std::vector;

// dp
// class Solution
// {
// public:
//     vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//     {
//         vector<vector<vector<int>>> dp(target, vector<vector<int>>());
//         // [target][[number]]
//         for (int i = 0; i < target; i++)
//         {
//             for (int j = 0; j < candidates.size(); j++)
//             {
//                 if (candidates[j] == i + 1)
//                     dp[i].push_back(vector<int>{candidates[j]});
//                 int before = i - candidates[j];
//                 if (before >= 0)
//                 {
//                     for (auto temp : dp[before])
//                     {
//                         temp.push_back(candidates[j]);
//                         std::sort(temp.begin(), temp.end());
//                         if (std::find(dp[i].begin(), dp[i].end(), temp) == dp[i].end())
//                             dp[i].push_back(temp);
//                     }
//                 }
//             }
//         }
//         return dp[target - 1];
//     }
// };

class Solution
{
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(candidates, temp, target, 0);
        return result;
    }

    void dfs(vector<int> &candidates, vector<int> &arr, int target, int index)
    {
        for (int i = index; i < candidates.size(); i++)
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
                dfs(candidates, arr, target - candidates[i], i);
                arr.pop_back();
            }
        }
    }
};