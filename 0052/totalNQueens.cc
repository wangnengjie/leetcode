class Solution {
  public:
    int totalNQueens(int n) {
        vector<vector<bool>> status(n, vector<bool>(n, false));
        vector<bool> column(n, false);
        return trace(n, 0, status, column);
    }

    int trace(int N, int raw, vector<vector<bool>> &status, vector<bool> &column) {
        if (raw == N) {
            return 1;
        }
        int match = 0;
        for (int i = 0; i < N; i++) {
            if (column[i]) {
                continue;
            }
            bool flag = true;
            for (int r = raw - 1, c = i + 1; r >= 0 && c < N; r--, c++) {
                if (status[r][c]) {
                    flag = false;
                    break;
                }
            }
            for (int r = raw - 1, c = i - 1; r >= 0 && c >= 0; r--, c--) {
                if (status[r][c]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                status[raw][i] = true;
                column[i] = true;
                match += trace(N, raw + 1, status, column);
                status[raw][i] = false;
                column[i] = false;
            }
        }
        return match;
    }
};