#include <vector>
using std::vector;

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            if (nums[left] == 0)
                left++;
            if (left >= nums.size())
                return;
            else
                break;
        }
        while (true) {
            if (nums[right] == 2)
                right--;
            if (right < 0)
                return;
            else
                break;
        }
        for (int i = left; i <= right; i++) {
            if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
            }
        }
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};