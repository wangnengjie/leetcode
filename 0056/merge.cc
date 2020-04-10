#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        result.reserve(intervals.size());
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        for (int i = 0; i < intervals.size(); i++)
        {
            if (!result.empty() && result.back()[1] >= intervals[i][0])
                result.back()[1] = std::max(intervals[i][1], result.back()[1]);
            else
                result.push_back(intervals[i]);
            while (i < intervals.size() - 1 && intervals[i][0] == intervals[i + 1][0])
                i++;
        }
        return result;
    }
};