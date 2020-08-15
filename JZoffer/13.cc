class Solution {
  public:
    int movingCount(int m, int n, int k) {
        int ml = max(m, n);
        auto sum = vector<int>(ml);
        for (int i = 0; i < ml; i++) {
            int s = 0;
            for (int j = i; j > 0;) {
                s += j % 10;
                j /= 10;
            }
            sum[i] = s;
        }
        auto trace = vector<vector<bool>>(m, vector<bool>(n, false));
        search(trace, sum, 0, 0, k);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (trace[i][j]) {
                    res++;
                }
            }
        }
        return res;
    }

    void search(vector<vector<bool>> &trace, vector<int> &sum, int row, int col, int k) {
        if (row < 0 || row >= trace.size() || col < 0 || col >= trace[0].size() || trace[row][col] ||
            (sum[row] + sum[col] > k)) {
            return;
        }
        trace[row][col] = true;
        search(trace, sum, row + 1, col, k);
        search(trace, sum, row - 1, col, k);
        search(trace, sum, row, col + 1, k);
        search(trace, sum, row, col - 1, k);
    }
};