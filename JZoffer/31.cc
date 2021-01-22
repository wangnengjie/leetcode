class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        auto s = stack<int>();
        int i = 0, j = 0;
        for (; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        while (!s.empty() && j < popped.size()) {
            if (s.top() == popped[j]) {
                s.pop();
                j++;
            } else {
                return false;
            }
        }
        return true;
    }
};