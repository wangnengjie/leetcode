#include <vector>

using std::vector;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int count = 0, major = 0;
        for (const auto &num : nums) {
            if (count == 0) {
                count += 1;
                major = num;
            } else {
                count += (major == num) ? 1 : -1;
            }
        }
        return major;
    }
};