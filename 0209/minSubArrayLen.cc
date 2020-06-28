#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = 0;
        for (int left = 0, right = 0, count = 0; right < nums.size();) {
            count += nums[right++];
            if (count >= s) {
                while (count >= s) {
                    count -= nums[left++];
                }
                int sublen = right - left + 1;
                res = res == 0 ? sublen : min(res, sublen);
            }
        }
        return res;
    }
};