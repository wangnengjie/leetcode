class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        auto t = vector<int>(nums.size());
        t[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (t[i - 1] >= 0) {
                t[i] = nums[i] + t[i - 1];
            } else {
                t[i] = nums[i];
            }
        }
        return *max_element(t.begin(), t.end());
    }
};