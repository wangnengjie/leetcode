class Solution {
  public:
    int maxValue(vector<vector<int>> &grid) {
        auto board = vector<int>(grid[0].size() + 1, 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                board[j + 1] = max(board[j] + grid[i][j], board[j + 1] + grid[i][j]);
            }
        }
        return board.back();
    }
};