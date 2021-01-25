#include <stack>

using std::stack;

class MinStack {
  private:
    stack<int> s_num{};
    stack<int> s_min{};

  public:
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x) {
        s_num.push(x);
        if (s_min.empty() || x <= s_min.top()) {
            s_min.push(x);
        }
    }

    void pop() {
        if (s_num.top() == s_min.top()) {
            s_min.pop();
        }
        s_num.pop();
    }

    int top() { return s_num.top(); }

    int min() { return s_min.top(); }
};