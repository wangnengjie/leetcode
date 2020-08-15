class Solution {
  private:
    int M, N;

  public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        M = board.size();
        N = board[0].size();
        auto trace = vector<vector<bool>>(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (search(board, trace, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>> &board, vector<vector<bool>> &trace, string &word, int idx, int row, int col) {
        if (idx >= word.size()) {
            return true;
        }
        if (row < 0 || row >= M || col < 0 || col >= N || trace[row][col] || word[idx] != board[row][col]) {
            return false;
        }
        trace[row][col] = true;
        bool res =
            search(board, trace, word, idx + 1, row + 1, col) || search(board, trace, word, idx + 1, row - 1, col) ||
            search(board, trace, word, idx + 1, row, col + 1) || search(board, trace, word, idx + 1, row, col - 1);
        trace[row][col] = false;
        return res;
    }
};