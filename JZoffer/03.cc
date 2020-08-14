class Solution {
  public:
    int findRepeatNumber(vector<int> &nums) {
        auto m = unordered_map<int, int>();
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (++m[*it] == 2) {
                return *it;
            }
        }
        return -1;
    }
};