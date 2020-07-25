#include <vector>
using std::vector;

class Solution {
  public:
    int splitArray(vector<int> &nums, int m) {
        int max = 0;
        long long sum = 0;
        for (int &num : nums) {
            sum += num;
            max = std::max(num, max);
        }
        long long min = 0;
        for (long long left = max, right = sum; left <= right;) {
            long long mid = (left + right) >> 1;
            int p = 1;
            long long count = 0;
            for (int &num : nums) {
                if (count + num > mid) {
                    p++;
                    count = num;
                } else {
                    count += num;
                }
            }
            if (p <= m) {
                min = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return min;
    }
};