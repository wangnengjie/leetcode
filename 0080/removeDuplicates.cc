#include <bits/c++config.h>
#include <cstddef>
#include <vector>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        size_t len = nums.size();
        if (len < 3) {
            return len;
        }
        int l = 0;
        int r = 1;
        int count = 1;
        while (r < len) {
            if (nums[r - 1] == nums[r]) {
                count++;
            } else {
                count = 1;
            }
            if (count > 2) {
                int n = nums[r];
                while (++r < len && nums[r] == n) {
                    ;
                }
                if (r >= len) {
                    break;
                }
                count = 1;
            }
            nums[++l] = nums[r++];
        }
        return l + 1;
    }
};