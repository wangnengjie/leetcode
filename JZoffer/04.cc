class Solution {
  public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        for (int i = 0, j = matrix[0].size() - 1; i < matrix.size() && j >= 0;) {
            if (matrix[i][j] == target) {
                return true;
            } else {
                matrix[i][j] > target ? j-- : i++;
            }
        }
        return false;
    }
};