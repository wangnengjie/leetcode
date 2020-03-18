#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool dC = false;
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                dC = true;
            }
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if ((matrix[i][0] == 0) || (matrix[0][j] == 0)) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            std::fill(matrix[0].begin() + 1, matrix[0].end(), 0);
        }
        if (dC) {
            for (int i = 1; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};