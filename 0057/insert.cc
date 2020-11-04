class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        res.reserve(intervals.size() + 1);
        int pos = 0;
        while (pos < intervals.size() && intervals[pos][1] < newInterval[0]) {
            res.push_back(intervals[pos++]);
        }
        if (pos == intervals.size()) {
            res.push_back(newInterval);
            return res;
        }
        if (intervals[pos][0] > newInterval[1]) {
            res.push_back(newInterval);
        } else {
            vector<int> tmp(2);
            tmp[0] = std::min(intervals[pos][0], newInterval[0]);
            while (++pos < intervals.size() && intervals[pos][0] <= newInterval[1]) {
                ;
            }
            tmp[1] = std::max(newInterval[1], intervals[pos - 1][1]);
            res.push_back(tmp);
        }
        while (pos < intervals.size()) {
            res.push_back(intervals[pos++]);
        }
        return res;
    }
};