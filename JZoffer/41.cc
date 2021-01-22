class MedianFinder {
  private:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

  public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        q1.push(num);
        q2.push(q1.top());
        q1.pop();
        if (q1.size() < q2.size()) {
            q1.push(q2.top());
            q2.pop();
        }
    }

    double findMedian() {
        if (q1.size() == q2.size()) {
            return (double)(q1.top() + q2.top()) / 2.0;
        }
        return (double)q1.top();
    }
};