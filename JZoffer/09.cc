class CQueue {
  private:
    stack<int> s1;
    stack<int> s2;

  public:
    CQueue() {}

    void appendTail(int value) { s2.push(value); }

    int deleteHead() {
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        if (s1.empty()) {
            return -1;
        }
        int t = s1.top();
        s1.pop();
        return t;
    }
};