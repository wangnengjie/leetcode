class Solution {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        auto res = vector<int>(nums.size(), -1);
        if (nums.empty()) {
            return res;
        }
        auto numStack = stack<int>(); // idx stack acc
        for (int i = 0; i < nums.size(); i++) {
            if (numStack.empty()) {
                numStack.push(i);
            } else {
                while (!numStack.empty() && nums[i] > nums[numStack.top()]) {
                    res[numStack.top()] = nums[i];
                    numStack.pop();
                }
                numStack.push(i);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            while (!numStack.empty() && nums[i] > nums[numStack.top()]) {
                res[numStack.top()] = nums[i];
                numStack.pop();
            }
        }
        return res;
    }
};