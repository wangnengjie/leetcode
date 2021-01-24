class Solution {
  public:
    vector<int> exchange(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums;
        }
        int lpos = 0, rpos = nums.size() - 1;
        while (lpos < rpos) {
            while (lpos < rpos) {
                if (!(nums[lpos] % 2)) {
                    break;
                }
                lpos++;
            }
            while (lpos < rpos && rpos >= 0) {
                if (nums[rpos] % 2) {
                    break;
                }
                rpos--;
            }
            if (lpos == rpos) {
                break;
            }
            swap(nums[lpos++], nums[rpos--]);
        }
        return nums;
    }
};