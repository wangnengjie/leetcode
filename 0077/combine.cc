#include <vector>
using std::vector;
class Solution {
  public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n == 0 || k == 0) {
            res.push_back(vector<int>());
            return res;
        }
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                res.push_back(vector<int>{i});
            }
            return res;
        }
        for (int i = n; i >= k; i--) {
            decltype(res) t = combine(i - 1, k - 1);
            for (auto &arr : t) {
                arr.push_back(i);
            }
            res.insert(res.end(), t.begin(), t.end());
        }
        return res;
    }
};