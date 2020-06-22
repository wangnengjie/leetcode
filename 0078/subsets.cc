#include <vector>
using std::vector;
class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        auto res = vector<vector<int>>();
        unsigned long long n = 1 << nums.size();
        for (decltype(n) i = 0; i < n; i++) {
            auto vec = vector<int>();
            for (decltype(n) j = 0; j < nums.size(); j++) {
                if ((i & (1 << j)) != 0U) {
                    vec.push_back(nums[j]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};